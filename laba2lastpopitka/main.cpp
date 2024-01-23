#include <iostream>
#include <chrono>
#include "BaseObject.h"
#include "T1.h"
#include "T2.h"
#include "Factory.h"
#include "test.h"

using namespace std;
using namespace chrono;


class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ��" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    {
        // ��������� ������� ���������� ���� ���������
        LogDuration input;


        setlocale(LC_ALL, "Russian");

        if (testAddObjects()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cout << "����-����� �� ��������!" << endl;
        }

        BaseObject* obj1 = nullptr;
        BaseObject* obj2 = nullptr;

        int choice;
        string idT1;
        string idT2;
        do {

            cout << "����:" << endl;
            cout << "1. ������� ������ T1" << endl;
            cout << "2. ������� ������ T2" << endl;
            cout << "3. �������� �������" << endl;
            cout << "4. ������� �������" << endl;
            cout << "5. �����" << endl;
            cout << "������� ��� �����: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // �������� ������� T1
                cout << "������� ������������� T1: ";
                cin >> idT1;
                cout << "������� �������� T1: ";
                int valueT1;
                cin >> valueT1;
                obj1 = Factory::createT1(idT1, valueT1);
                break;

            case 2:
                // �������� ������� T2
                cout << "������� ������������� T2: ";
                cin >> idT2;
                cout << "������� 16-������ �������� T2: ";
                int hexValueT2;
                cin >> hex >> hexValueT2;
                //������� ����� ����� �� ������� ����� ������
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> dec;
                obj2 = Factory::createT2(idT2, hexValueT2);
                break;

            case 3:
                // �������� �������
                if (obj1 != nullptr)
                    obj1->display();
                if (obj2 != nullptr)
                    obj2->display();
                break;

            case 4:
                // �������� ��������
                if (obj1 != nullptr && obj2 != nullptr) {
                    BaseObject* result = addObjects(obj1, obj2);
                    if (result != nullptr) {
                        result->display();
                        Factory::deleteObject(result);
                    }
                }
                else {
                    cerr << "����������, �������� ��� ������� ����� ����������� ��������." << endl;
                }
                break;

            case 5:
                break;

            default:
                cerr << "�������� �����. ����������, ������� ���������� �����." << endl;
            }
        } while (choice != 5);

        // ������������ ���������� ������
        Factory::deleteObject(obj1);
        Factory::deleteObject(obj2);

        return 0;
    }
}
