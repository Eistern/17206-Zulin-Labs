#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;

string TidyString(string input) {
    int to = input.size();
    for (unsigned int i = 0; i < to; ++i)
        while (i < to && strchr(",.;:()!?'", input.at(i)) != nullptr) {
            input.erase(input.begin() + i);
            to = input.size();
        }
    if (input.at(0) == '-')
        input.erase(input.begin());

    return input;
}

map <string, double>::iterator findMaxVal(map <string, double> source) {
    auto mapP = source.end();
    double max = 0;

    for (auto& it : source)
        if (it.second > max) {
            max = it.second;
            mapP = source.find(it.first);
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

    while (!fin.eof()) {
        getline(fin, buff, ' ');
        buff = TidyString(buff);
        wordC++;

        if ((mapP = contentTable.find(buff)) != contentTable.end())
            (mapP->second)++;
        else
            contentTable.insert(pair<string, double>(buff, 1.0));
    }

    //TODO output of contentTable
    while (!contentTable.empty()) {
        //mapP = findMaxVal(contentTable);
        double max = 0;

        for (auto& it : contentTable)
            if (it.second > max) {
                max = it.second;
                mapP = contentTable.find(it.first);
            }
        fout << mapP->first << ", " << mapP->second << ", " << mapP->second/wordC * 100 << endl;
        //mapP->second = -1;
        contentTable.erase(mapP);
    }

    fout.close();
    fin.close();
    return 0;
}