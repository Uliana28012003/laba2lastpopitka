#pragma once

#include "BaseObject.h"

using namespace std;

// ����� T1, ����������� �� BaseObject, ������������ ������ � �������� ���������
class T1 : public BaseObject {
public:

    int value;

    // �����������, ���������������� ������ T1 � �������� ��������������� � �������� ���������
    T1(const string& id, int v);

    // ���������������� ������� ����������� ������� T1
    void display() const override;
};
