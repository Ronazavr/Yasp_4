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
//? ћетод, получающий файловый поток на вход, котора€ осуществл€ет чтение чисел
//из файла в последовательный контейнер; 
// DONE
// 
//? “ри версии метода modify, выполн€ющей преобразование контейнера.Ќа вход
//функции должны поступать итераторы начала и конца обрабатываемой части
//контейнера, в качестве результата функци€ должна возвращать
//модифицированный контейнер(не измен€€ исходный).–еализовать алгоритм
//через : for, std::transform, std::for_each;
// 
// DONE
//? ћетоды, вычисл€ющие сумму и среднее арифметическое чисел, содержащихс€
//в контейнере(не вычисл€ть вручную через €вный вызов for / while / do - while);
// DONE
// 
// DONE
//? ћетод потокового вывода результата.ќсуществить вывод в файл и на экран с ее
//помощью.
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
