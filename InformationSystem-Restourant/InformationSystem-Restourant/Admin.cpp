#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>
#include <Windows.h>
#include <string>

using namespace std;

string path = "Menu.txt";
string path1 = "Employers.txt";
string path2 = "Clients.txt";

fstream fs;

struct Product
{
    string id;
    string name;
    string price;
};

vector<Product> products;

struct Dish
{
    string id;
    string name;
    string price;
    string productsList;
    int cookTime;
};

void adminRole() {
    int adminChoice;

    do {
        cout << "����� ����������, ��������� ������������� (�������� ����� ���������� ��������������)!\n";
        cout << "1. ������������� ����\n";
        cout << "2. ������������� ������� ������ �����������\n";
        cout << "3. ����������� ���� �������������\n";
        cout << "4. ������������� ������ ���������\n";
        cout << "9. �����\n";

        while (!(cin >> adminChoice) || adminChoice < 1 || adminChoice > 9) {
            cout << "������������ ����. ����������, �������� ��������������� �����.\n";
            cin.clear();
            
        }

        switch (adminChoice) {
        case 1:
        {
            int menuChoice;

            do {
                cout << "���� ��������������:\n";
                cout << "1. ������������� ����\n";
                cout << "4. ��������� � ���� ���������� ��������������\n";

                while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 4) {
                    cout << "������������ ����. ����������, �������� ��������������� ����� (1-4).\n";
                    cin.clear();
                    
                }

                switch (menuChoice) {
                case 1:
                    fs.open(path, fstream::in | fstream::out | fstream::app);
                    if (!fs.is_open())
                    {
                        cout << "������ ��� �������� �����" << endl;
                    }
                    else
                    {
                        string id, name, price, productsList, cookTime;
                        int value;
                        string msg;
                        cout << "���� ������� ������" << endl;
                        cout << "1. �������� ������" << endl;
                        cout << "2. ����������� ��� ������" << endl;
                        cout << "3. ������� ������(�� �������� �����)" << endl;
                        cout << "������� �����: ";
                        cin >> value;
                        if (value == 1)
                        {
                            SetConsoleCP(1251);
                            string productsList;
                            int cookTime;

                            cout << "������� ID �����: ";
                            cin >> id;
                            cout << "������� �������� �����: ";
                            cin >> name;
                            cout << "������� ���� �����: ";
                            cin >> price;
                            cout << "������� ���� ��������� ����� ������: ";
                            cin.ignore();
                            getline(cin, productsList);
                            cout << "������� ��������� ����� ������������� (� �������): ";
                            cin >> cookTime;

                            fs << id << " " << name << " " << price << " " << productsList << " " << cookTime << "\n";

                            SetConsoleCP(866);
                        }

                        else if (value == 2)
                        {
                            SetConsoleCP(1251);
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

                                SetConsoleCP(866);
                            }
                        }

                        else if (value == 3)
                        {
                            SetConsoleCP(1251);
                            string deleteMsg;
                            cin >> deleteMsg;

                            fstream tempFile("Menu.txt", fstream::out);

                            while (!fs.eof())
                            {
                                msg = "";
                                fs >> msg;
                                if (msg != deleteMsg)
                                {
                                    tempFile << msg << "\n";
                                }
                            }
                            tempFile.close();
                            fs.close();
                            remove(path.c_str());
                            rename("Menu.txt", path.c_str());
                            SetConsoleCP(866);
                        }
                    }
                    fs.close();
                    break;

                case 4:
                    cout << "������� � �������� ����...\n";
                    break;
                default:
                    cout << "������������ �����. ���������� ��� ���.\n";
                }

            } while (menuChoice != 4);

            break;
        }

        case 2:
            SetConsoleCP(1251);
            fs.open(path1, fstream::in | fstream::out | fstream::app);
            if (!fs.is_open())
            {
                cout << "������ ��� �������� �����" << endl;
            }
            else
            {
                string fio, position, employeeId, login, password;
                int choice;
                cout << "���� ������� ������" << endl;
                cout << "1. �������� ������" << endl;
                cout << "2. ����������� ��� ������" << endl;
                cout << "3. ������� ������ (�� ID)" << endl;
                cout << "������� �����: ";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "������� ��� ����������: ";
                    cin.ignore();
                    getline(cin, fio);

                    cout << "������� ID ����������: ";
                    cin >> employeeId;

                    cout << "������� ��������� ����������: ";
                    cin.ignore();
                    getline(cin, position);

                    cout << "������� ����� ����������: ";
                    cin >> login;

                    cout << "������� ������ ����������: ";
                    cin >> password;

                    fs << fio << " " << employeeId << " " << position << " " << login << " " << password << "\n";
                }

                else if (choice == 2)
                {
                    cout << "������ �� ����� ������� ���������" << endl;
                    while (fs >> fio >> employeeId >> position >> login >> password)
                    {
                        cout << "���: " << fio << ", ID: " << employeeId << ", ���������: " << position << ", �����: " << login << ", ������: " << password << endl;
                        SetConsoleCP(866);
                    }
                }

                else if (choice == 3)
                {
                    SetConsoleCP(1251);
                    string deleteId;
                    cout << "������� ID ���������� ��� ��������: ";
                    cin >> deleteId;

                    fstream tempFile("Empoyers.txt", fstream::out);

                    while (!fs.eof())
                    {
                        fs >> fio >> position >> employeeId >> login >> password;
                        if (employeeId != deleteId)
                        {
                            tempFile << fio << " " << position << " " << employeeId << " " << login << " " << password << "\n";
                        }
                    }
                    tempFile.close();
                    fs.close();
                    remove(path1.c_str());
                    rename("tempempoyers.txt", path1.c_str());
                }
            }
            fs.close();
            SetConsoleCP(866);
            break;

        case 3:
        {
            SetConsoleCP(1251);
            fstream clientsFile("Clients.txt", fstream::in | fstream::out | fstream::app);
            if (!clientsFile.is_open())
            {
                cout << "������ ��� �������� �����" << endl;
            }
            else
            {
                string clientId, clientName;
                int choice;

                cout << "���� � ����������� � �������� ������� ������" << endl;
                cout << "1. ���������������� �������" << endl;
                cout << "2. ����������� ������ ��������" << endl;
                cout << "������� �����: ";
                cin >> choice;

                if (choice == 1)
                {
                    cout << "������� ID �������: ";
                    cin >> clientId;
                    cout << "������� ��� �������: ";
                    cin.ignore();
                    getline(cin, clientName);

                    clientsFile << clientId << " " << clientName << "\n";
                    cout << "������ ������� ���������������" << endl;
                }
                else if (choice == 2)
                {
                    cout << "������ ������������������ ��������:" << endl;
                    clientsFile.clear();
                    clientsFile.seekg(0, ios::beg);

                    while (clientsFile >> clientId >> clientName)
                    {
                        cout << "ID: " << clientId << ", ���: " << clientName << endl;
                    }
                }
            }
            clientsFile.close();
            SetConsoleCP(866);
            break;
        }
        case 4:
        {
            int choice;
            cout << "1. ����������� ������ ���������" << endl;
            cout << "2. �������� �������" << endl;
            cout << "3. ������� �������" << endl;
            cin >> choice;

            if (choice == 1)
            {
                for (const Product& product : products)
                {
                    cout << "ID: " << product.id << " ��������: " << product.name << " ����: " << product.price << endl;
                }
            }
            else if (choice == 2)
            {
                Product newProduct;
                cout << "������� ID ��������: ";
                cin >> newProduct.id;
                cout << "������� �������� ��������: ";
                cin >> newProduct.name;
                cout << "������� ���� ��������: ";
                cin >> newProduct.price;

                products.push_back(newProduct);
                cout << "������� ������� ��������" << endl;
            }
            else if (choice == 3)
            {
                string productId;
                cout << "������� ID �������� ��� ��������: ";
                cin >> productId;

                for (auto it = products.begin(); it != products.end(); ++it)
                {
                    if (it->id == productId)
                    {
                        products.erase(it);
                        cout << "������� � ID " << productId << " ������� ������" << endl;
                        break;
                    }
                }
                cout << "������� � ID " << productId << " �� ������" << endl;
            }
            break;
        }
        case 9:
            cout << "����� �� ���� ��������������.\n";
            break;
        default:
            cout << "������������ �����. ���������� ��� ���.\n";
        }
    } while (adminChoice != 9);
}

