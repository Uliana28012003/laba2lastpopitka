#pragma once

#include "BaseObject.h"

using namespace std;

// ����� T2, ����������� �� BaseObject, ������������ ������ � ����������������� ���������
class T2 : public BaseObject {
public:

    int hexValue;

    // �����������, ���������������� ������ T2 � �������� ��������������� � ����������������� ���������
    T2(const string& id, int hex);

    // ���������������� ������� ����������� ������� T2
    void display() const override;
};
