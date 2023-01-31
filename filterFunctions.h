#pragma once
#include <functional>
#include <iterator>
#include <vector>
#include <string>

#include "processing.h"

using FilterFunction = std::function<bool(const vector<string>)>;

void printFiltered(const vector<vector<string>> &vec, FilterFunction fun)
{
    string buf;
    for (const auto &x : vec) {
        if (fun(x)) {
            print(x, buf);
        }
    }
}

FilterFunction filterOne = [filter = "1"](const vector<string> s) {
    return !s.empty() ? filter == s.at(0) : false;
};

FilterFunction filterPair = [filter1 = "46", filter2 = "70"](const vector<string> s) {
    return !s.empty() ? ((s.at(0) == filter1) && (s.at(1) == filter2)) : false;
};

FilterFunction filterAny = [filter = "46"](const vector<string> s) {
    auto it = find(s.begin(), s.end(), filter);
    return it != std::end(s);
};
