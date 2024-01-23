#include "test.h"
#include "Factory.h"
#include <cassert>
#include <iostream>

// Функция тестирования сложения объектов
bool testAddObjects() {
    // Создание объектов T1 и T2 для тестирования
    T1* t1 = Factory::createT1("TestT1", 13);
    T2* t2 = Factory::createT2("TestT2", 0xE);

    // Вызов функции addObjects для сложения объектов
    BaseObject* result = addObjects(t1, t2);

    // Проверка, что результат не является нулевым указателем
    assert(result != nullptr);

    // Проверка, что идентификатор результата равен "Результат"
    assert(result->identifier == "Результат");

    // Попытка динамического приведения результата к типу T1
    T1* resultT1 = dynamic_cast<T1*>(result);

    // Проверка, что динамическое приведение не является нулевым указателем
    assert(resultT1 != nullptr);

    // Проверка, что значение resultT1->value равно сумме значений из t1 и t2
    assert(resultT1->value == 13 + 0xE);

    // Если тест пройден успешно, освобождение памяти и возврат true
    if (resultT1->value == 13 + 0xE) {
        Factory::deleteObject(result);
        Factory::deleteObject(t1);
        Factory::deleteObject(t2);
        return true;
    }

    // Если тест не пройден, освобождение памяти и возврат false
    Factory::deleteObject(result);
    Factory::deleteObject(t1);
    Factory::deleteObject(t2);
    return false;
}
