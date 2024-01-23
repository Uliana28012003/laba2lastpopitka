#pragma once

#include "BaseObject.h"

using namespace std;

// Класс T1, производный от BaseObject, представляет объект с числовым значением
class T1 : public BaseObject {
public:

    int value;

    // Конструктор, инициализирующий объект T1 с заданным идентификатором и числовым значением
    T1(const string& id, int v);

    // Переопределенная функция отображения объекта T1
    void display() const override;
};
