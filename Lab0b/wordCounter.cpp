#include "wordCounter.h"

void wordCounter::parseFile(std::istream &fin) {
    std::string buff;
    stringParser filter;

    while (!fin.eof()) {
        //Get next string from fin and parse it
        getline(fin, buff, '\n');
        filter.parseString(buff);

        //While filter isn't empty, add it to the wordMap
        while (!filter.isEmpty()) {
            buff = filter.getString();
            wordNumber++;
            wordMap[buff]++;
        }
    }
}

void wordCounter::printMap(std::ostream &fout) {
    std::multimap<int, std::string> outputFormat;

    //Creating multimap for output
    for (auto& it : wordMap)
        outputFormat.insert(std::pair<int, std::string>(it.second, it.first));

    for (auto it = outputFormat.rbegin()++; it != outputFormat.rend(); it++)
        fout << it->second << ", " << it->first << ", " << (double)it->first/wordNumber * 100 << "%" << std::endl;
}
