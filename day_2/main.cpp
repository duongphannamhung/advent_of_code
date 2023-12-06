#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(string x, char y) {
    vector<string> v;
    string temp = "";
    for (int i = 0 ; i < x.length(); i++) {
        if (x[i] == y) {
            if (temp == "") {
                continue;
            } else {
                v.push_back(temp);
                temp = "";
            }
        } else {
            temp += x[i];
        }
    }
    if (temp != "") {
        v.push_back(temp);
    }
    return v;
}

int parseIndex(string index) {
    vector<string> v = split(index, ' ');
    int output;
    output = stoi(v[1]);
    return output;
}

int parseMiddle(string middle, int& green, int& red, int& blue) {
    vector<string> v = split(middle, ';');
    int max_red, max_blue, max_green = 0;
    for (string game: v) {
        vector<string> part = split(game, ',');
        for (string p : part) {
            vector<string> gem = split(p, ' ');
            if (gem[1] == "green") {
                if (stoi(gem[0]) > max_green) {
                    max_green = stoi(gem[0]);  
                } 
            } else if (gem[1] == "red") {
                if (stoi(gem[0]) > max_red) {
                    max_red = stoi(gem[0]);
                }
            } else if (gem[1] == "blue") {
                if (stoi(gem[0]) > max_blue ) {
                    max_blue = stoi(gem[0]);
                }
            } else {
                cout << "SOMETHING WRONG !!!" << endl;
            }
        }
        // if (red > 12 || green > 13 || blue > 14) {
        //     red = 0;
        //     blue = 0;
        //     green = 0;
        //     return false;
        // }
        // red = 0;
        // blue = 0;
        // green = 0;
    }
    return max_red * max_green * max_blue;
}

int main() {
    ifstream input;
    vector<string> words;
    input.open("input.txt");
    string line;
    while (getline(input, line)) {
        words.push_back(line);
    }

    input.close();

    int red , blue , green = 0;
    int sum_index = 0;
    for (string row : words) {
        vector<string> game = split(row, ':');
        int index = parseIndex(game[0]);
        int result = parseMiddle(game[1], green, red, blue);   
        // if (result) {
        //     cout << "index " << index << endl;
        //     sum_index += index;
        // }
        sum_index += result;
        cout << result << endl;
    }

    cout << "Output is: " << sum_index << endl; 

}