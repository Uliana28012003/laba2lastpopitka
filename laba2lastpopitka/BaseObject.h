#pragma once
#include <string>

using namespace std;

// Базовый класс BaseObject предоставляет абстрактный интерфейс для объектов
class BaseObject {
public:
    // Идентификатор объекта
    string identifier;

    // Конструктор класса BaseObject, инициализирует идентификатор объекта
    BaseObject(const string& id);

    // Виртуальный деструктор по умолчанию
    virtual ~BaseObject() = default;

    // Абстрактная функция отображения информации об объекте
    virtual void display() const = 0;
};
