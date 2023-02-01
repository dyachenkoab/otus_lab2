#pragma once
#include <functional>
#include <iterator>

#include "processing.h"

using FilterFunction = std::function<bool(const vector<int>)>;

void printFiltered(const vector<vector<int>> &vec, FilterFunction fun)
{
    for (const auto &x : vec) {
        if (fun(x)) {
            print(x);
        }
    }
}

FilterFunction filterOne = [filter = 1](const vector<int> &s) {
    return !s.empty() ? filter == s.at(0) : false;
};

FilterFunction filterPair = [filter1 = 46, filter2 = 70](const vector<int> &s) {
    return !s.empty() ? ((s.at(0) == filter1) && (s.at(1) == filter2)) : false;
};

FilterFunction filterAny = [filter = 46](const vector<int> &s) {
    auto it = find(s.begin(), s.end(), filter);
    return it != std::end(s);
};
