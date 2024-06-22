#include <iostream>
#include <vector>
#include <string>
#include "HeaderClient.h"
#include <locale>
#include <fstream>

using namespace std;
extern std::vector<std::string> orders;
vector<string> orders;

class Employer {
public:
    virtual void viewOrders(vector<string>& orders) = 0;
    virtual void startComplete(vector<string>& orders) = 0;
};

class Povar : public Employer {
public:
    void viewOrders(vector<string>& orders) override {
        cout << "�������� ���� �� ������:" << endl;
        for (const auto& order : orders) {
            cout << "����� � ID " << order << endl;
        }
        cout << "������ ������: ������� �� �����" << endl;
    }

    void startComplete(vector<string>& orders) override {
        string userInput;
        cout << "������� ID ��������� ��� �������� � ���������� �������������:" << endl;
        cin >> userInput;

        for (auto& order : orders) {
            if (order == userInput) {
                cout << "����� � ID " << userInput << " ������������. ������ ������ ������� �� '��������'" << endl;
                return;
            }
        }
        cout << "����� � ID " << userInput << " ����������� � ������ ��� �� ������." << endl;
    }
};

class Waiter : public Employer {
public:
    void viewOrders(vector<string>& orders) override {
        cout << "��� ������:" << endl;
        for (const auto& order : orders) {
            cout << "����� � ID " << order << endl;
        }
        cout << "������ ������: ������� �� �����" << endl;
    }

    void startComplete(vector<string>& orders) override {
        cout << "����� ������. ������ ������ ������� �� '��������'" << endl;
    }
};

void waiterRole() {
    Waiter waiter;
    int choice;
    bool exit = false;
    string dishName;

    cout << "�� ������� � ���� ���������" << endl;
    do {
        // ��� ���������
        cout << "�������� ��������:" << endl;
        cout << "1. ����������� ������" << endl;
        cout << "2. ������������ �����" << endl;
        cout << "3. ����� �� ���� ���������" << endl;
        cout << "��� �����: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "�� �������: ����������� ������ \n" << endl;
            cout << "������ (�� ID): 5 \n" << endl;
            waiter.viewOrders(orders);
            break;
        case 2:
            cout << "�� �������: ��������� �����\n" << endl;
            cout << "����� 5 ��������\n" << endl;
            waiter.startComplete(orders);
            break;
        case 3:
            cout << "�� �������: ����� �� ���� ���������" << endl;
            exit = true;
            break;
        default:
            cout << "������������ �����. ����������, �������� �����." << endl;
            break;
        }

    } while (!exit);
}

void povarRole() {
    Povar povar; 
    int choice;
    bool exit = false;
    string dishName;
    vector<string> orders; 

    cout << "�� ������� � ���� ������" << endl;
    do {
        cout << "�������� ��������:" << endl;
        cout << "1. ����������� ������" << endl;
        cout << "2. ����������� �����" << endl;
        cout << "3. ����� �� ���� ������" << endl;
        cout << "��� �����: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "�� �������: ����������� ������" << endl;
            povar.viewOrders(orders);
            break;
        case 2:
            cout << "�� �������: ����������� �����" << endl;
            povar.startComplete(orders);
            break;
        case 3:
            cout << "�� �������: ����� �� ���� ������" << endl;
            exit = true;
            break;
        default:
            cout << "������������ �����. ����������, �������� �����." << endl;
            break;
        }

    } while (!exit);
}
