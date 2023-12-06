#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


int main() {
    ifstream input;
    vector<string> words;
    input.open("input.txt");
    string line;
    while (getline(input, line)) {
        words.push_back(line);
    }

    input.close();

    int output = 0;

}