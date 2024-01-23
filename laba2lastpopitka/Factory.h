#pragma once
#include "BaseObject.h"
#include "T2.h"
#include "T1.h"

// Класс Factory предоставляет методы для создания объектов T1 и T2, а также для удаления объектов
class Factory {
public:
    // Создание объекта T1 с заданным идентификатором и числовым значением
    static T1* createT1(const std::string& id, int value);

    // Создание объекта T2 с заданным идентификатором и шестнадцатеричным значением
    static T2* createT2(const std::string& id, int hexValue);

    // Удаление объекта, освобождение выделенной памяти
    static void deleteObject(BaseObject* obj);
};

// Функция для сложения двух объектов и возврата результата
BaseObject* addObjects(BaseObject* obj1, BaseObject* obj2);
