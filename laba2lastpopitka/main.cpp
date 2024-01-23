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
            << " мс" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    {
        // Измерение времени выполнения всей программы
        LogDuration input;


        setlocale(LC_ALL, "Russian");

        if (testAddObjects()) {
            cout << "Юнит-тесты пройдены успешно!" << endl;
        }
        else {
            cout << "Юнит-тесты не пройдены!" << endl;
        }

        BaseObject* obj1 = nullptr;
        BaseObject* obj2 = nullptr;

        int choice;
        string idT1;
        string idT2;
        do {

            cout << "Меню:" << endl;
            cout << "1. Создать объект T1" << endl;
            cout << "2. Создать объект T2" << endl;
            cout << "3. Показать объекты" << endl;
            cout << "4. Сложить объекты" << endl;
            cout << "5. Выход" << endl;
            cout << "Введите ваш выбор: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // Создание объекта T1
                cout << "Введите идентификатор T1: ";
                cin >> idT1;
                cout << "Введите значение T1: ";
                int valueT1;
                cin >> valueT1;
                obj1 = Factory::createT1(idT1, valueT1);
                break;

            case 2:
                // Создание объекта T2
                cout << "Введите идентификатор T2: ";
                cin >> idT2;
                cout << "Введите 16-ричное значение T2: ";
                int hexValueT2;
                cin >> hex >> hexValueT2;
                //Очищает буфер ввода до символа новой строки
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> dec;
                obj2 = Factory::createT2(idT2, hexValueT2);
                break;

            case 3:
                // Показать объекты
                if (obj1 != nullptr)
                    obj1->display();
                if (obj2 != nullptr)
                    obj2->display();
                break;

            case 4:
                // Сложение объектов
                if (obj1 != nullptr && obj2 != nullptr) {
                    BaseObject* result = addObjects(obj1, obj2);
                    if (result != nullptr) {
                        result->display();
                        Factory::deleteObject(result);
                    }
                }
                else {
                    cerr << "Пожалуйста, создайте оба объекта перед выполнением сложения." << endl;
                }
                break;

            case 5:
                break;

            default:
                cerr << "Неверный выбор. Пожалуйста, введите допустимую опцию." << endl;
            }
        } while (choice != 5);

        // Освобождение выделенной памяти
        Factory::deleteObject(obj1);
        Factory::deleteObject(obj2);

        return 0;
    }
}
