#include <fstream>
#include <string>

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    std::string N;
    iFile >> N;
    std::fstream oFile("output.txt", std::ios_base::out);
    (N[N.length() - 1] - '0' == 0)? oFile << "NO" : oFile << N[N.length() - 1] - '0';
}
