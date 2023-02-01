#include "filterFunctions.h"

int main()
{
    IpPool ipPool;

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

    sort(ipPool.begin(), ipPool.end(), comparator);

    printAll(ipPool);
    //    printFiltered(ipPool, std::make_unique<FilterOne>("1"));
    //    printFiltered(ipPool, std::make_unique<FilterPair>("46", "70"));
    //    printFiltered(ipPool, std::make_unique<FilterAny>("46"));

    printFiltered(ipPool, filterOne);
    printFiltered(ipPool, filterPair);
    printFiltered(ipPool, filterAny);

    return 0;
}
