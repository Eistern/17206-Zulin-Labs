#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

//Function tidyString removes punctuation marks from the string and converts it into lower case
string tidyString(string input) {
    int to = input.length();
    for (unsigned int i = 0; i < to; ++i)
        while (i < to && strchr(",.;:()!?'\n", input.at(i)) != nullptr) {
            input.erase(input.begin() + i);
            to = input.length();
        }
    if (input.at(0) == '-')
        input.erase(input.begin());

    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

//Function findMaxVal returns an iterator, that points at the element of max value
map <string, double>::iterator findMaxVal(map <string, double> *source) {
    auto mapP = (*source).end();
    double max = 0;

    for (auto& it : *source)
        if (it.second > max) {
            max = it.second;
            mapP = (*source).find(it.first);
        }
    return mapP;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Wrong number of arguments" << endl;
        return 0;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    map <string, double> contentTable;
    map <string, double>::iterator mapP;
    int wordC = 0;
    string buff;

    //Going through the input file, counting number of words in it
    while (!fin.eof()) {
        getline(fin, buff, ' ');
        buff = tidyString(buff);

        if (!buff.empty()) {
            wordC++;
            if ((mapP = contentTable.find(buff)) != contentTable.end())
                mapP->second++;
            else
                contentTable.insert(pair<string, double>(buff, 1.0));
        }
    }

    //Printing out content of map in decreasing order by value
    while (!contentTable.empty()) {
        mapP = findMaxVal(&contentTable);
        fout << mapP->first << ", " << mapP->second << ", " << mapP->second/wordC * 100 << "%" << endl;
        contentTable.erase(mapP);
    }

    fout.close();
    fin.close();
    return 0;
}