#include "processing.h"

//vector<string> split(const string &b, char sep);
//bool comparator(const vector<string> &v1, const vector<string> &v2);
//void read_file(vector<vector<string>> &res);
//void printAll(const vector<vector<string>> &vec);
//void printFiltered(const vector<vector<string>> &vec, std::unique_ptr<PrimeFilter> f);
//void print(const vector<string> &vec, string &buf);

int main()
{

    string line = "";
    vector<vector<string>> ipPool;

    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }

        string::size_type sz(line.find_first_of('\t'));
        if (sz != string::npos) {
            ipPool.push_back(split(line.substr(0, sz), '.'));
        }
    }

    //        read_file(ipPool);

    try {
        sort(ipPool.begin(), ipPool.end(), comparator);
    } catch (const std::invalid_argument &e) {
        std::cout << "Unfortunately there was a bad input." << e.what() << std::endl;
        exit(0);
    } catch (const std::out_of_range &o) {
        std::cout << "Sorry, but index is out of range." << o.what() << std::endl;
        exit(0);
    }

    printAll(ipPool);
    printFiltered(ipPool, std::make_unique<FilterOne>("1"));
    printFiltered(ipPool, std::make_unique<FilterPair>("157", "39"));
    printFiltered(ipPool, std::make_unique<FilterAny>("1"));

    return 0;
}

