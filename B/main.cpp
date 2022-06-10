#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


int searchSequenceUnit(std::vector<int> vec, int len) {
    int current = 0;
    int best = 0;
    for (int i = 0; i < len; ++i) {
        if (vec[i] > 0) {
            current++;
            best = std::max(best, current);
        } else {
            current = 0;
        }
    }
    return best;
}

int main(int argc, char *argv[]) {
    std::string line;
    std::vector<int> vec;
    int len = 0;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (fin.is_open()) {
        getline(fin, line);
        len = atoi(line.c_str());
        while (getline(fin, line)) {
            vec.push_back(atoi(line.c_str()));
        }
    }
    if (len == 0) fout << 0 << std::endl;
    else fout << searchSequenceUnit(vec, len) << std::endl;
    return 0;
}