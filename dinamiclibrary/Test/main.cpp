#include <iostream>
#include <string>
#include <windows.h>
#include <locale>

using namespace std;

typedef bool (*CharCheckFunction)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Russian");

    // ��������� ���������������� ����
    cout << "������� ������ ��� ������ �������� � ���:";
    string inputStr;
    getline(cin, inputStr);

    cout << "������� ������� ��� ������:";
    string searchChars;
    getline(cin, searchChars);

    // ��������� ������������ ����������
    HMODULE hDLL = LoadLibraryW(L"DinamicLib.dll");
    if (hDLL == NULL) {
        cerr << "�� ������� ��������� ���������� DLL." << endl;
        return 1;
    }

    // �������� ������ ������� �� ������������ ����������
    CharCheckFunction checkCharsInString = (CharCheckFunction)GetProcAddress(hDLL, "serchstr");
    if (checkCharsInString == NULL) {
        cerr << "�� ������� �������� ����� �������." << endl;
        FreeLibrary(hDLL);
        return 1;
    }

    // �������� ������� �� ������������ ����������
    bool result = checkCharsInString(inputStr.c_str(), searchChars.c_str());

    // ������� ���������
    if (result) {
        cout << "��� ������� �������!" << endl;
    }
    else {
        cout << "������� �� �������!" << endl;
    }

    // �������� ������� ����� ������ � ������������ �����������
    FreeLibrary(hDLL);

    return 0;
}
