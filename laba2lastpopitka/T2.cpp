#include <iostream>
#include "T2.h"

using namespace std;
// Конструктор класса T2, инициализирует базовый класс и устанавливает значение

T2::T2(const string& id, int hex) : BaseObject(id), hexValue(hex) {}

// Переопределенная функция для отображения информации об объекте T2
void T2::display() const {
    cout << "Объект T2 - Идентификатор: " << identifier << ", 16-ричное значение: " << hex << hexValue << dec << endl;
}
