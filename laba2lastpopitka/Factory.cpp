#include <iostream>
#include "Factory.h"
#include "T1.h"
#include "T2.h"

using namespace std;

// �������� ������� T1 � �������� ��������������� � �������� ���������. * ��������� �� ��, ��� ������� `createT1` ���������� ��������� �� ������ ���� `T1`
T1* Factory::createT1(const string& id, int value) {
    return new T1(id, value);
}

// �������� ������� T2 � �������� ��������������� � ����������������� ���������
T2* Factory::createT2(const string& id, int hexValue) {
    //�������� `new` ������������ ��� ������������� ��������� ������ ��� ������� � C++.
    //�� ������� ����� ������ ���������� ���� � ���������� ��������� �� ���� ������. `new` �������� ������ ��� ����� ������� � ���������� ��������� �� ����.
    return new T2(id, hexValue);
}

// �������� �������, ������������ ���������� ������
void Factory::deleteObject(BaseObject* obj) {
    delete obj;
}

BaseObject* addObjects(BaseObject* obj1, BaseObject* obj2) {
    if (dynamic_cast<T1*>(obj1) != nullptr && dynamic_cast<T2*>(obj2) != nullptr) {
        // ���� obj1 �������� �������� T1, � obj2 - �������� T2
        T1* t1Obj1 = dynamic_cast<T1*>(obj1);
        T2* t2Obj2 = dynamic_cast<T2*>(obj2);
        int resultValue = t1Obj1->value + t2Obj2->hexValue;
        T1* result = Factory::createT1("���������", resultValue);
        return result;
    }
    else if (dynamic_cast<T2*>(obj1) != nullptr && dynamic_cast<T1*>(obj2) != nullptr) {
        // ���� obj1 �������� �������� T2, � obj2 - �������� T1
        T2* t2Obj1 = dynamic_cast<T2*>(obj1);
        T1* t1Obj2 = dynamic_cast<T1*>(obj2);
        int resultValue = t2Obj1->hexValue + t1Obj2->value;
        T2* result = Factory::createT2("���������", resultValue);
        return result;
    }
    else {
        // ���� ���� �������� �� ������������� ���������
        cerr << "������������ �������� ��� ������ ��������." << endl;
        return nullptr;
    }
}

