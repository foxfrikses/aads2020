#include <fstream>

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    std::fstream oFile("output.txt", std::ios_base::out);
    int year{0};
    iFile >> year;
    if (year % 4  == 0 && (year % 100 != 0 || year % 400 == 0)) oFile << "YES";
    else oFile << "NO";
    return 0;
}
