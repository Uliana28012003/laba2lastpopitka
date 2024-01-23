#include <iostream>
#include "Factory.h"
#include "T1.h"
#include "T2.h"

using namespace std;

// Создание объекта T1 с заданным идентификатором и числовым значением. * указывает на то, что функция `createT1` возвращает указатель на объект типа `T1`
T1* Factory::createT1(const string& id, int value) {
    return new T1(id, value);
}

// Создание объекта T2 с заданным идентификатором и шестнадцатеричным значением
T2* Factory::createT2(const string& id, int hexValue) {
    //Оператор `new` используется для динамического выделения памяти под объекты в C++.
    //Он создает новый объект указанного типа и возвращает указатель на этот объект. `new` выделяет память для этого объекта и возвращает указатель на него.
    return new T2(id, hexValue);
}

// Удаление объекта, освобождение выделенной памяти
void Factory::deleteObject(BaseObject* obj) {
    delete obj;
}

BaseObject* addObjects(BaseObject* obj1, BaseObject* obj2) {
    if (dynamic_cast<T1*>(obj1) != nullptr && dynamic_cast<T2*>(obj2) != nullptr) {
        // Если obj1 является объектом T1, а obj2 - объектом T2
        T1* t1Obj1 = dynamic_cast<T1*>(obj1);
        T2* t2Obj2 = dynamic_cast<T2*>(obj2);
        int resultValue = t1Obj1->value + t2Obj2->hexValue;
        T1* result = Factory::createT1("Результат", resultValue);
        return result;
    }
    else if (dynamic_cast<T2*>(obj1) != nullptr && dynamic_cast<T1*>(obj2) != nullptr) {
        // Если obj1 является объектом T2, а obj2 - объектом T1
        T2* t2Obj1 = dynamic_cast<T2*>(obj1);
        T1* t1Obj2 = dynamic_cast<T1*>(obj2);
        int resultValue = t2Obj1->hexValue + t1Obj2->value;
        T2* result = Factory::createT2("Результат", resultValue);
        return result;
    }
    else {
        // Если типы объектов не соответствуют ожиданиям
        cerr << "Недопустимая операция для данных объектов." << endl;
        return nullptr;
    }
}

