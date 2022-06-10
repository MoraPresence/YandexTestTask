#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::string line;
    int prev = 0;
    int current = 0;
    int len = 0;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    if (fin.is_open()) {
        getline(fin, line);
        len = atoi(line.c_str());
        for (int i = 0; i < len; ++i) {
            getline(fin, line);
            current = atoi(line.c_str());
            if (prev != current || i == 0) fout << current << std::endl;
            prev = current;
        }
    }
    fin.close();
    fout.close();
    return 0;
}