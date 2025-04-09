//5. Заменить каждое число на корень из суммы квадрата текущего числа
//и квадрата первого числа.Ответ округлить до целых.
//Пекшин Степан 9 группа
#include "DEQUE.h" 
fstream file_gen_for(string filename, int N, int M) {
    fstream file(filename, ios::in | ios::out | ios::trunc);
    if (file.is_open()) {
        for (int i = 0; i < N; ++i) {
            file << (rand() % (2 * M + 1) - M) << " ";
        }
        file.seekg(0);
    }
    else cerr << "Ошибка: не удалось открыть файл " << filename << endl;
    return file;
}

fstream file_gen_gen(string filename, int N, int M) {
    fstream file(filename, ios::in | ios::out | ios::trunc);
    if (file.is_open()) {
        generate_n(ostream_iterator<int>(file, " "), N,
            [M]() { return rand() % (2 * M + 1) - M; });
        file.seekg(0);
    }
    else cerr << "Ошибка: не удалось открыть файл " << filename << endl;
    return file;
}

void read_and_check(int& input, int min = 0, int max = INT_MAX) {
    cout << "-> ";
    while (!(cin >> input) || input > max || input < min) {
        cout << "Ошибка ввода!\n";
        cin.clear();
        cin.ignore(255, '\n');
        cout << "-> ";
    }
}

string get_file_name() {
    const string CANT = "'|\"\\/*:?<>+%!@";
    string fname;
    while (true) {
        bool valid = true;
        cout << "Введите имя файла: ";
        cin >> fname;

        for (char c : fname) {
            if (CANT.find(c) != string::npos) {
                valid = false;
                break;
            }
        }

        if (valid) break;
        cout << "Неверное имя файла!\n";
    }
    return fname;
}

int fill_menu() {
    cout << "Выберите способ заполнения файла\n"
        << "1. Используя цикл\n"
        << "2. Используя generate_n\n";
    int choice{};
    read_and_check(choice, 1, 2);
    return choice;
}

int action_menu() {
    cout << "Выберите действие\n"
        << "1. Модифицировать дек\n"
        << "2. Найти сумму элементов\n"
        << "3. Найти среднее арифметическое\n"
        << "4. Вывести контейнер\n"
        << "5. Завершить работу\n";
    int choice{};
    read_and_check(choice, 1, 5);
    return choice;
}

int mod_menu() {
    cout << "Выберите вариант modify\n"
        << "1. for\n"
        << "2. transform\n"
        << "3. for_each\n";
    int choice{};
    read_and_check(choice, 1, 3);
    return choice;
}

pair<deque<int>::iterator, deque<int>::iterator> get_borders(DEQUE& dq) {
    pair<deque<int>::iterator, deque<int>::iterator> result;
    while (true) {
        int left{}, right{};
        cout << "Введите индекс первого элемента: ";
        read_and_check(left, 0);
        cout << "Введите индекс последнего элемента (не включительно): ";
        read_and_check(right, 0);

        if (left > right && right != 0) {
            cout << "Ввод некорректен\n";
        }
        else {
            result.first = left == 0 ? dq.begin() : dq.get_iterator(left);
            result.second = right == 0 ? dq.end() : dq.get_iterator(right);
            break;
        }
    }
    return result;
}

deque<int> mod(DEQUE& dq) {
    auto borders = get_borders(dq);
    int choice = mod_menu();
    switch (choice) {
    case 1: return dq.modify_for(borders.first, borders.second);
    case 2: return dq.modify_transform(borders.first, borders.second);
    case 3: return dq.modify_foreach(borders.first, borders.second);
    default: return {};
    }
}

int output_menu() {
    cout << "Выберите способ вывода\n"
        << "1. В консоль\n"
        << "2. В файл\n";
    int choice{};
    read_and_check(choice, 1, 2);
    return choice;
}

int main() {
    SetConsoleOutputCP(1251);
    srand(GetTickCount64());

    while (true) {
        cout << "Введите количество чисел: ";
        int N{};
        read_and_check(N, 1);

        cout << "Введите границы генерации: ";
        int M{};
        read_and_check(M, 1);

        string file_name = get_file_name();
        fstream file = fill_menu() == 1 ?
            file_gen_for(file_name, N, M) :
            file_gen_gen(file_name, N, M);

        DEQUE dq;
        dq.fill(file);
        file.close();

        cout << "Исходный дек: ";
        dq.print();
        cout << endl;

        bool working = true;
        while (working) {
            switch (action_menu()) {
            case 1: { // modify
                deque<int> modified = mod(dq);
                cout << "Модифицированный дек: ";
                for (int elem : modified) cout << elem << ' ';
                cout << '\n';
                break;
            }
            case 2: // sum
                cout << "Сумма: " << dq.sum() << '\n';
                break;
            case 3: // average
                cout << "Среднее: " << dq.average() << '\n';
                break;
            case 4: { // print
                if (output_menu() == 1) {
                    dq.print();
                }
                else {
                    file_name = get_file_name();
                    ofstream out_file(file_name);
                    dq.print(out_file);
                }
                break;
            }
            case 5:
                working = false;
                break;
            }
        }

        char is_exit;
        cout << "Завершить программу? (Y/N): ";
        cin >> is_exit;
        if (toupper(is_exit) == 'Y') break;
    }

    return 0;
}

