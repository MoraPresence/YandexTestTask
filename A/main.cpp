#include <iostream>
#include <fstream>
#include <algorithm>

std::string removeDupsSorted(std::string s) {
    for (std::string::size_type i = 0; i < s.size(); i++) {
        std::string::size_type j = i + 1;
        while (j < s.size()) {
            if (s[i] == s[j]) {
                s.erase(j, 1);
            } else {
                ++j;
            }
        }
    }
    return s;
}

int searchLettersInString(std::string &J, std::string &S) {
    std::string tmp = removeDupsSorted(S);
    int result = 0;
    for (char i: tmp) {
        for (char j: J) {
            if (i == j) ++result;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    std::string S;
    std::string J;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (fin.is_open()) {
        getline(fin, S);
        getline(fin, J);
    }
    fout << searchLettersInString(J, S);
    fin.close();
    fout.close();
    return 0;
}