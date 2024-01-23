#include "test.h"
#include "Factory.h"
#include <cassert>
#include <iostream>

// ������� ������������ �������� ��������
bool testAddObjects() {
    // �������� �������� T1 � T2 ��� ������������
    T1* t1 = Factory::createT1("TestT1", 13);
    T2* t2 = Factory::createT2("TestT2", 0xE);

    // ����� ������� addObjects ��� �������� ��������
    BaseObject* result = addObjects(t1, t2);

    // ��������, ��� ��������� �� �������� ������� ����������
    assert(result != nullptr);

    // ��������, ��� ������������� ���������� ����� "���������"
    assert(result->identifier == "���������");

    // ������� ������������� ���������� ���������� � ���� T1
    T1* resultT1 = dynamic_cast<T1*>(result);

    // ��������, ��� ������������ ���������� �� �������� ������� ����������
    assert(resultT1 != nullptr);

    // ��������, ��� �������� resultT1->value ����� ����� �������� �� t1 � t2
    assert(resultT1->value == 13 + 0xE);

    // ���� ���� ������� �������, ������������ ������ � ������� true
    if (resultT1->value == 13 + 0xE) {
        Factory::deleteObject(result);
        Factory::deleteObject(t1);
        Factory::deleteObject(t2);
        return true;
    }

    // ���� ���� �� �������, ������������ ������ � ������� false
    Factory::deleteObject(result);
    Factory::deleteObject(t1);
    Factory::deleteObject(t2);
    return false;
}
