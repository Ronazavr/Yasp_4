#include "DEQUE.h"

void DEQUE::fill(fstream& file) {
    if (!file.is_open()) {
        cerr << "Ошибка: файл не открыт!" << endl;
        return;
    }

    dq.clear();
    int x;
    while (file >> x) {
        dq.push_back(x);
    }
}

deque<int> DEQUE::modify_for(deque<int>::iterator start, deque<int>::iterator end) {
    deque<int> res;
    if (start == end) return res;

    int min_val = *min_element(dq.begin(), dq.end());

    for (auto it = start; it != end; ++it) {
        double val = sqrt(abs((*it) * min_val));
        res.push_back(round(val));
    }

    return res;
}

deque<int> DEQUE::modify_transform(deque<int>::iterator start, deque<int>::iterator end) {
    deque<int> res;
    if (start == end) return res;

    int min_val = *min_element(dq.begin(), dq.end());

    transform(start, end, back_inserter(res),
        [min_val](int x) { return round(sqrt(abs(x * min_val))); });

    return res;
}

deque<int> DEQUE::modify_foreach(deque<int>::iterator start, deque<int>::iterator end) {
    deque<int> res;
    if (start == end) return res;

    int min_val = *min_element(dq.begin(), dq.end());

    for_each(start, end,
        [&res, min_val](int x) { res.push_back(round(sqrt(abs(x * min_val)))); });

    return res;
}

int DEQUE::sum() {
    return accumulate(dq.begin(), dq.end(), 0);
}

float DEQUE::average() {
    if (dq.empty()) return 0.0f;
    return static_cast<float>(sum()) / dq.size();
}

void DEQUE::print(ostream& out) {
    for (int num : dq) {
        out << num << " ";
    }
    out << endl;
}
//std::forward_list<int> FLIST::modify_foreach(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res{ list.begin(), list.end() };
//    int first = (*start) * (*start);
//    auto res_start = res.begin();
//    std::advance(res_start, std::distance(list.begin(), start));
//    std::for_each(res_start, std::next(res_start, std::distance(start, end)), [&first](int& x) {
//        x = std::sqrt(x * x + first); 
//        });
//
//    return res;
//}

//std::forward_list<int> FLIST::modify_transform(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res{ list.begin(), list.end() };
//    int first = (*start) * (*start);
//    std::forward_list<int>::iterator res_start = res.begin();
//    std::advance(res_start, std::distance(list.begin(), start));
//    std::forward_list<int>::iterator res_end = res_start;
//    std::advance(res_end, std::distance(start, end));
//    std::transform(res_start, res_end, res_start, [&first](int x) {
//        return std::sqrt(x * x + first);
//        });
//
//    return res;
//}

//std::forward_list<int> FLIST::modify_for(std::forward_list<int>::iterator start, std::forward_list<int>::iterator end)
//{
//    std::forward_list<int> res;
//    std::forward_list<int>::iterator iter = res.before_begin();
//    int first = (*start) * (*start);
//    if (start != list.begin())
//    {
//        for (std::forward_list<int>::iterator ptr = list.begin(); ptr != start; ++ptr)
//        {
//            if (ptr == start) break;
//            res.insert_after(iter, *ptr);
//            ++iter;
//        }
//    }
//
//    for (std::forward_list<int>::iterator ptr = start; start != end; ++ptr)
//    {
//        if (ptr == end) break;
//        res.insert_after(iter, sqrt((*ptr) * (*ptr) + first));
//        ++iter;
//    }
//
//    if (end != list.end())
//    {
//        for (std::forward_list<int>::iterator ptr = end; ptr != list.end(); ++ptr)
//        {
//            if (ptr == list.end()) break;
//            res.insert_after(iter, *ptr);
//            ++iter;
//        }
//    }
//
//    return res;
//}
