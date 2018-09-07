#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main(const string* input, const string* output) {
    ofstream fout(*output);
    ifstream fin(*input);

    map <string, int> contentTable;

    fout.close();
    fin.close();
    return 0;
}