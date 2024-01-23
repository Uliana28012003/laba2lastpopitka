#pragma once
#include "BaseObject.h"
#include "T2.h"
#include "T1.h"

// ����� Factory ������������� ������ ��� �������� �������� T1 � T2, � ����� ��� �������� ��������
class Factory {
public:
    // �������� ������� T1 � �������� ��������������� � �������� ���������
    static T1* createT1(const std::string& id, int value);

    // �������� ������� T2 � �������� ��������������� � ����������������� ���������
    static T2* createT2(const std::string& id, int hexValue);

    // �������� �������, ������������ ���������� ������
    static void deleteObject(BaseObject* obj);
};

// ������� ��� �������� ���� �������� � �������� ����������
BaseObject* addObjects(BaseObject* obj1, BaseObject* obj2);
