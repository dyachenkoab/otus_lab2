#pragma once
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>

#include "filters.h"

vector<string> split(const string &str, char sep)
{
    vector<string> v;
    string::size_type start = 0;
    string::size_type stop = str.find_first_of(sep);
    while (stop != std::string::npos) {
        v.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(sep, start);
    }

    v.push_back(str.substr(start));
    return v;
}

void read_file(vector<vector<string>> &res)
{
    const string filename = "ip_filter.tsv";

    vector<string> t_splitted;
    string buf;

    std::ifstream istrm(filename, std::ios::in);
    if (!istrm.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        while (istrm) {
            getline(istrm, buf);
            if (!buf.empty()) {
                t_splitted = split(buf, '\t');
                res.push_back(split(t_splitted.at(0), '.'));
            }
            t_splitted.clear();
        }
    }
}

void print(const vector<string> &vec, string &buf)
{
    std::ostringstream imploded;
    copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(imploded, "."));
    buf = imploded.str();
    buf.pop_back();
    std::cout << buf << std::endl;
}


void printFiltered(const vector<vector<string>> &vec, std::unique_ptr<PrimeFilter> f)
{
    string buf;
    for (const auto &x : vec) {
        if (f && ((*f)(x))) {
            print(x, buf);
        }
    }
}

void printAll(const vector<vector<string>> &vec)
{
    string buf;
    for (const auto &x : vec) {
        print(x, buf);
    }
}

bool comparator(const vector<string> &v1, const vector<string> &v2)
{
    auto first1 = v1.begin();
    auto last1 = v1.end();
    auto first2 = v2.begin();
    auto last2 = v2.end();

    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
        if (stoul(*first1) < stoul(*first2))
            return false;
        if (stoul(*first2) < stoul(*first1))
            return true;
    }
    return (first1 != last1) && (first2 == last2);
}
