#include <iostream>
#include "T2.h"

using namespace std;
// ����������� ������ T2, �������������� ������� ����� � ������������� ��������

T2::T2(const string& id, int hex) : BaseObject(id), hexValue(hex) {}

// ���������������� ������� ��� ����������� ���������� �� ������� T2
void T2::display() const {
    cout << "������ T2 - �������������: " << identifier << ", 16-������ ��������: " << hex << hexValue << dec << endl;
}
