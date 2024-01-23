#include <iostream>
#include "T1.h"

using namespace std;

// Конструктор класса T1, инициализирует базовый класс и устанавливает значение
T1::T1(const string& id, int v) : BaseObject(id), value(v) {}

// Переопределенная функция для отображения информации об объекте T1
void T1::display() const {
    cout << "Объект T1 - Идентификатор: " << identifier << ", Значение: " << value << endl;
}
