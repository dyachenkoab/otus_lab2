//#include "processing.h"
#include "filterFunctions.h"

int main()
{
    vector<vector<string>> ipPool;

    string line("");
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

    //    read_file(ipPool);

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
    //    printFiltered(ipPool, std::make_unique<FilterOne>("1"));
    //    printFiltered(ipPool, std::make_unique<FilterPair>("46", "70"));
    //    printFiltered(ipPool, std::make_unique<FilterAny>("46"));

    printFiltered(ipPool, filterOne);
    printFiltered(ipPool, filterPair);
    printFiltered(ipPool, filterAny);

    return 0;
}
