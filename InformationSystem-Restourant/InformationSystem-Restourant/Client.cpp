#include "HeaderClient.h"
#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <vector>

#include "HeaderAdmin.h"
using namespace std;
extern basic_fstream<char, struct char_traits<char>> fs;


struct MenuItem {
    string id;
    string name;
    float price;
    string productsList;
    string cookTime;
};

vector<MenuItem> menuItems;
vector<MenuItem> cart;

MenuItem item;
bool found = false;

void loadMenuItems() {
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {
        cout << "������ ��� �������� �����" << endl;
    }
    else {
        string id, name, price, productsList, cookTime;
        cout << "������ �� ����� ������� ���������" << endl;
        while (!fs.eof()) {
            fs >> id >> name >> price >> productsList >> cookTime;
            MenuItem newItem = { id, name, stof(price), productsList, cookTime };
            menuItems.push_back(newItem);
        }
        fs.close();
    }
}

void clientRole()
{
    int choice;
    bool exit = false;
    string dishName;

    do {
        cout << "�������� ��������:" << endl;
        cout << "1. ����������� ����" << endl;
        cout << "2. �������� ����� � ���������������� ���� ��� ��" << endl;
        cout << "4. ��������� ������ ������" << endl;
        cout << "5. ����� �� ���� �������" << endl;
        cout << "��� �����: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "�� �������: ����������� ����" << endl;
            fs.open(path, fstream::in | fstream::out | fstream::app);
            if (!fs.is_open())
            {
                cout << "������ ��� �������� �����" << endl;
            }
            else
            {
                string id, name, price, productsList, cookTime;
                cout << "������ �� ����� ������� ���������" << endl;
                while (!fs.eof())
                {
                    id = "";
                    name = "";
                    price = "";
                    productsList = "";
                    cookTime = "";

                    fs >> id >> name >> price >> productsList >> cookTime;
                    cout << "ID: " << id << ", ��������: " << name << ", ����: " << price << ", ��������: " << productsList << ", ����� �������������: " << cookTime << " �����" << endl;
                }
                fs.close();
            }
            break;
        case 2:
        {
            cout << "�� �������: �������� ����� � �������" << endl;

            string wordFromUser;
            cout << "������� ID ����� ��� ����������: ";
            cin >> wordFromUser;

            ifstream inFile("Menu.txt");
            string wordFromFile = "";
            bool wordFound = false;
            vector<string> orders;

            while (inFile >> wordFromFile) {
                if (wordFromFile == wordFromUser) {
                    wordFound = true;
                    orders.push_back(wordFromFile);
                    cout << "����� ���������!" << endl;
                    cout << "������ ���������� �����? (��/���): ";
                    string continueOrder;
                    cin >> continueOrder;
                    if (continueOrder != "��") {
                        break;
                    }
                }
            }

            inFile.close();

            if (!wordFound) {
                cout << "����� �� �������." << endl;
            }
            else {
                cout << "����� � ����� �������:" << endl;
                for (const auto& order : orders) {
                    cout << "����� � ID " << order << endl;
                }

                cout << "������ ������: ������� �� �����" << endl;
            }

            break;
        }

        case 4:
            cout << "�� �������: ��������� ������ ������" << endl;
            cout << "������� �� �����" << endl;
            break;
        case 5:
            cout << "�� �������: ����� �� ���� �������" << endl;
            exit = true;
            break;
        default:
            cout << "������������ �����. ����������, �������� �����." << endl;
            break;
        }

    } while (!exit);
}

