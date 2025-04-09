#pragma once
#include <iostream>
#include <fstream>
#include <deque>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <numeric>
#include <Windows.h>


// DONE
//? �����, ���������� �������� ����� �� ����, ������� ������������ ������ �����
//�� ����� � ���������������� ���������; 
// DONE
// 
//? ��� ������ ������ modify, ����������� �������������� ����������.�� ����
//������� ������ ��������� ��������� ������ � ����� �������������� �����
//����������, � �������� ���������� ������� ������ ����������
//���������������� ���������(�� ������� ��������).����������� ��������
//����� : for, std::transform, std::for_each;
// 
// DONE
//? ������, ����������� ����� � ������� �������������� �����, ������������
//� ����������(�� ��������� ������� ����� ����� ����� for / while / do - while);
// DONE
// 
// DONE
//? ����� ���������� ������ ����������.����������� ����� � ���� � �� ����� � ��
//�������.
//DONE

using namespace std;

class DEQUE {
private:
    deque<int> dq;

public:
    DEQUE() = default;
    ~DEQUE() = default;

    void fill(fstream& file);
    deque<int> modify_for(deque<int>::iterator start, deque<int>::iterator end);
    deque<int> modify_transform(deque<int>::iterator start, deque<int>::iterator end);
    deque<int> modify_foreach(deque<int>::iterator start, deque<int>::iterator end);

    deque<int>::iterator begin() { return dq.begin(); }
    deque<int>::iterator end() { return dq.end(); }
    deque<int>::iterator get_iterator(size_t pos) {
        if (pos >= dq.size()) return dq.end();
        return dq.begin() + pos;
    }

    int sum();
    float average();
    void print(ostream& out = cout);
};
