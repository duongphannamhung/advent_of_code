#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int checkFive(string word, unordered_map<string,int> map) {
    set<string> fiveWordFull = {"three", "seven", "eight"};
    if (fiveWordFull.count(word)) {
        return map[word];
    } else {
        return 0;
    }
}

int checkFour(string word, unordered_map<string,int> map) {
    set<string> fourWordFull = {"four", "five", "nine"};
    set<string> fourWord = {"thre", "seve", "eigh"};

    if (fourWordFull.count(word)) {
        return map[word];
    } else if (fourWord.count(word)) {
        return -1;
    } else {
        return 0;
    }
}

int checkThree(string word, unordered_map<string,int> map) {
    set<string> threeWordFull = {"one", "two" , "six"};
    set<string> threeWord = {"thr", "fou", "fiv", "sev", "eig", "nin"};

    if (threeWordFull.count(word)) {
        return map[word];
    } else if (threeWord.count(word)) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    unordered_map<string, int> map = {{"one",1},{"two",2},{"three",3},{"four",4}, {"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};

    ifstream input;
    vector<string> words;
    input.open("input.txt");
    string line;
    while (getline(input, line)) {
        words.push_back(line);
    }

    input.close();

    int output = 0;

    for (string word: words) {
        int first, last;
        bool flag = false;
        int i = 0;
        string temp = "";
        while (i < word.length()) {
            if (isdigit(word[i])) {
                if (!flag) {
                    first = word[i] - '0';
                    last = first;
                    flag = true;
                } else {
                    last = word[i] - '0';
                }
                temp = "";
            } else {
                temp += word[i];
                if (temp.length() == 3) {
                    if (checkThree(temp,map) != -1 and checkThree(temp,map) != 0) {
                        if (!flag) {
                            first = last = checkThree(temp,map);
                            flag = true;
                        } else {
                            last = checkThree(temp, map);
                        }
                        temp = temp.substr(2,1);
                    } else if (checkThree(temp,map) == 0) {
                        temp = temp.substr(1,2);
                    }
                } else if (temp.length() == 4) {
                    if (checkFour(temp,map) != -1 and checkFour(temp,map) != 0) {
                        if (!flag) {
                            first = last = checkFour(temp, map);
                            flag = true;
                        } else {
                            last = checkFour(temp,map);
                        }
                        temp = temp.substr(3,1);
                    } else if (checkFour(temp, map) == 0) {
                        temp = temp.substr(2,2);
                    }
                } else if (temp.length() == 5) {
                    if (checkFive(temp,map) != 0) {
                        if (!flag) {
                            first = last = checkFive(temp, map);
                            flag = true;
                        } else {
                            last = checkFive(temp, map);
                        }
                        temp = temp.substr(4,1);
                    } else {
                        temp = temp.substr(3,2);
                    }
                }
            }
            i++;
        }
        // cout << first*10+last << endl;
        cout << first << last << endl;
        output += first * 10 + last;
    }

    cout << output << endl;
}