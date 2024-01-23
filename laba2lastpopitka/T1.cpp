#include <iostream>
#include "T1.h"

using namespace std;

// ����������� ������ T1, �������������� ������� ����� � ������������� ��������
T1::T1(const string& id, int v) : BaseObject(id), value(v) {}

// ���������������� ������� ��� ����������� ���������� �� ������� T1
void T1::display() const {
    cout << "������ T1 - �������������: " << identifier << ", ��������: " << value << endl;
}
