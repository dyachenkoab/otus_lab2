#pragma once
#include <vector>
#include <string>
#include <algorithm>

using std::find;
using std::string;
using std::vector;

struct PrimeFilter
{
    virtual ~PrimeFilter() {};
    virtual bool operator()(const vector<string> &s) = 0;
};

struct FilterOne : public PrimeFilter
{
    FilterOne(const string &filter) : m_filter(filter) { }
    ~FilterOne() = default;
    bool operator()(const vector<string> &s)
    {
        return !s.empty() ? m_filter == s.at(0) : false;
    };

private:
    string m_filter;
};

struct FilterPair : public PrimeFilter
{
    FilterPair(const string &filter, const string &filter1)
        : m_filter(filter)
        , m_filter1(filter1)
    {
    }
    ~FilterPair() = default;
    bool operator()(const vector<string> &s)
    {
        return !s.empty() ? ((s.at(0) == m_filter) && (s.at(1) == m_filter1)) : false;
    };

private:
    const string m_filter;
    const string m_filter1;
};

struct FilterAny : public PrimeFilter
{
    FilterAny(const string &filter) : m_filter(filter) { }
    ~FilterAny() = default;
    bool operator()(const vector<string> &s)
    {
        auto it = find(s.begin(), s.end(), m_filter);
        return it != std::end(s);
    };

private:
    string m_filter;
};
