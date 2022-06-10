#include <iostream>
#include <fstream>
#include <algorithm>

void printer(int left, int right, int num, std::string str){
    if (left == num && right == num)
        std::cout << str << std::endl;
    else
    if(left < num)
        printer(left+1, right, num, str+'(');
    if(right < left)
        printer(left, right+1, num, str+')');
}

int main(int argc, char *argv[]) {
    std::string line;
    int len = 0;
    std::ifstream fin("input.txt");
    if (fin.is_open()) {
        getline(fin, line);
        len = atoi(line.c_str());
    }

    printer(0, 0, len, "");
    fin.close();
    return 0;
}