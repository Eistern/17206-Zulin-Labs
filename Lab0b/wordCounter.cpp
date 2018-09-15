#include "wordCounter.h"

void wordCounter::parseFile(std::istream &fin) {
    std::string buff;
    stringParser filter;

    while (!fin.eof()) {
        getline(fin, buff, ' ');
        buff = filter.tidyString(buff);

        if (!buff.empty()) {
            wordNumber++;
            wordMap[buff]++;
        }
    }
}

void wordCounter::printMap(std::ostream &fout) {
    std::multimap<int, std::string> outputFormat;

    for (auto& it : wordMap)
        outputFormat.insert(std::pair<int, std::string>(it.second, it.first));

    for (auto it = outputFormat.rbegin()++; it != outputFormat.rend(); it++)
        fout << it->second << ", " << it->first << ", " << (double)it->first/wordNumber * 100 << "%" << std::endl;
}