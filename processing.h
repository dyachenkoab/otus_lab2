#pragma once
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>

#include "filters.h"
using IpPool = vector<vector<int>>;

vector<int> split(const string &line, char sep)
{
    vector<int> v;
    string::size_type start = 0;
    string::size_type stop = line.find_first_of(sep);

    try {
        while (stop != string::npos) {
            v.push_back(stoul(line.substr(start, stop - start)));

            start = stop + 1;
            stop = line.find_first_of(sep, start);
        }
        v.push_back(stoul(line.substr(start)));
    } catch (const std::invalid_argument &e) {
        std::cout << "Unfortunately there was a bad input." << e.what() << std::endl;
        exit(0);
    } catch (const std::out_of_range &o) {
        std::cout << "Sorry, but index is out of range." << o.what() << std::endl;
        exit(0);
    }

    return v;
}

void read_file(IpPool &pool)
{
    const string filename = "ip_filter.tsv";

    string buf;

    std::ifstream istrm(filename, std::ios::in);
    if (!istrm.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        while (istrm) {
            getline(istrm, buf);
            if (!buf.empty()) {
                string::size_type sz(buf.find_first_of('\t'));
                if (sz != string::npos) {
                    pool.push_back(split(buf.substr(0, sz), '.'));
                }
            }
        }
    }
}

void print()
{
    std::cout << "\n";
}

template<typename T, typename... Args>
void print(const T &t, const Args &...args)
{
    std::cout << t;
    if (sizeof...(args) != 0)
        std::cout << ".";
    print(args...);
}

void print(const vector<int> &ip)
{
    if (ip.size() == 4)
        print(ip.at(0), ip.at(1), ip.at(2), ip.at(3));
}

void printFiltered(const IpPool &pool, std::unique_ptr<PrimeFilter> filter)
{
    for (const auto &ip : pool) {
        if (filter && ((*filter)(ip))) {
            print(ip);
        }
    }
}

void printAll(const IpPool &pool)
{
    for (const auto &ip : pool) {
        print(ip);
    }
}

bool comparator(const vector<int> &v1, const vector<int> &v2)
{
    auto first1 = v1.begin();
    auto last1 = v1.end();
    auto first2 = v2.begin();
    auto last2 = v2.end();

    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2) {
        if (*first1 < *first2)
            return false;
        if (*first2 < *first1)
            return true;
    }
    return (first1 != last1) && (first2 == last2);
}
