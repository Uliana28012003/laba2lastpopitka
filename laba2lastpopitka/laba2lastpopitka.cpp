/*#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Объявление базового класса
class BaseObject {
public:
    std::string identifier;

    // Конструктор
    BaseObject(const std::string& id) : identifier(id) {}

    // Виртуальная функция для отображения значения объекта
    virtual void display() const = 0;
};

// Класс T1
class T1 : public BaseObject {
public:
    int value;

    // Конструктор
    T1(const std::string& id, int v) : BaseObject(id), value(v) {}

    // Реализация виртуальной функции
    void display() const override {
        std::cout << "Объект T1 - Идентификатор: " << identifier << ", Значение: " << value << std::endl;
    }
};

// Класс T2
class T2 : public BaseObject {
public:
    int hexValue;

    // Конструктор
    T2(const std::string& id, int hex) : BaseObject(id), hexValue(hex) {}

    // Реализация виртуальной функции
    void display() const override {
        std::cout << "Объект T2 - Идентификатор: " << identifier << ", 16-ричное значение: " << std::hex << hexValue << std::dec << std::endl;
    }
};

// Фабрика для создания объектов
class Factory {
public:
    static T1* createT1(const std::string& id, int value) {
        return new T1(id, value);
    }

    static T2* createT2(const std::string& id, int hexValue) {
        return new T2(id, hexValue);
    }

    static void deleteObject(BaseObject* obj) {
        delete obj;
    }
};

// Функция сложения объектов
BaseObject* addObjects(BaseObject* obj1, BaseObject* obj2) {
     if (dynamic_cast<T1*>(obj1) != nullptr && dynamic_cast<T2*>(obj2) != nullptr) {
        // Пример: Сложение значения T1 с десятичным эквивалентом 16-ричного значения T2
        T1* t1Obj1 = dynamic_cast<T1*>(obj1);
        T2* t2Obj2 = dynamic_cast<T2*>(obj2);

        int resultValue = t1Obj1->value + t2Obj2->hexValue;
        T1* result = Factory::createT1("Результат", resultValue);
        return result;
    }
    else if (dynamic_cast<T2*>(obj1) != nullptr && dynamic_cast<T1*>(obj2) != nullptr) {
        // Пример: Сложение десятичного значения T1 с 16-ричным эквивалентом значения T2
        T2* t2Obj1 = dynamic_cast<T2*>(obj1);
        T1* t1Obj2 = dynamic_cast<T1*>(obj2);

        int resultValue = t2Obj1->hexValue + t1Obj2->value;
        T2* result = Factory::createT2("Результат", resultValue);
        return result;
    }
    else {
        std::cerr << "Недопустимая операция для данных объектов." << std::endl;
        return nullptr;
    }
}






int main() {
    setlocale(LC_ALL, "Russian");
    BaseObject* obj1 = nullptr;
    BaseObject* obj2 = nullptr;

    // Меню
    int choice;
    std::string idT1;
    std::string idT2;
    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Создать объект T1" << std::endl;
        std::cout << "2. Создать объект T2" << std::endl;
        std::cout << "3. Показать объекты" << std::endl;
        std::cout << "4. Сложить объекты" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Создание объекта T1
            std::cout << "Введите идентификатор T1: ";
            std::cin >> idT1;
            std::cout << "Введите значение T1: ";
            int valueT1;
            std::cin >> valueT1;
            obj1 = Factory::createT1(idT1, valueT1);
            break;

        case 2:
            // Создание объекта T2
            std::cout << "Введите идентификатор T2: ";
            std::cin >> idT2;
            std::cout << "Введите 16-ричное значение T2: ";
            int hexValueT2;
            std::cin >> std::hex >> hexValueT2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очистка буфера ввода от лишних символов
            std::cin >> std::dec;  // Возвращение формата ввода к десятичному
            obj2 = Factory::createT2(idT2, hexValueT2);
            break;

        case 3:
            // Отображение объектов
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
                std::cerr << "Пожалуйста, создайте оба объекта перед выполнением сложения." << std::endl;
            }
            break;

        case 5:
            // Выход
            break;

        default:
            std::cerr << "Неверный выбор. Пожалуйста, введите допустимую опцию." << std::endl;
        }
    } while (choice != 5);

    // Очистка памяти
    Factory::deleteObject(obj1);
    Factory::deleteObject(obj2);

    return 0;
}*/
