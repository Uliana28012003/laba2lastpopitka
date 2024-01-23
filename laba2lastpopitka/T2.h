#pragma once

#include "BaseObject.h"

using namespace std;

// Класс T2, производный от BaseObject, представляет объект с шестнадцатеричным значением
class T2 : public BaseObject {
public:

    int hexValue;

    // Конструктор, инициализирующий объект T2 с заданным идентификатором и шестнадцатеричным значением
    T2(const string& id, int hex);

    // Переопределенная функция отображения объекта T2
    void display() const override;
};
