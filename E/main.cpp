#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::string str1;
    std::string str2;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (fin.is_open()) {
        getline(fin, str1);
        getline(fin, str2);
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1.compare(str2) == 0)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;;
    fin.close();
    fout.close();
    return 0;
}