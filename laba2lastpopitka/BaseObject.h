#pragma once
#include <string>

using namespace std;

// ������� ����� BaseObject ������������� ����������� ��������� ��� ��������
class BaseObject {
public:
    // ������������� �������
    string identifier;

    // ����������� ������ BaseObject, �������������� ������������� �������
    BaseObject(const string& id);

    // ����������� ���������� �� ���������
    virtual ~BaseObject() = default;

    // ����������� ������� ����������� ���������� �� �������
    virtual void display() const = 0;
};
