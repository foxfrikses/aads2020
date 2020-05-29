#include <fstream>

int main() {
    int n, m, x1, y1, x2, y2;
    std::fstream iFile("input.txt", std::ios_base::in);
    iFile >> n >> m >> x1 >> y1 >> x2 >> y2;
    std::fstream oFile("output.txt", std::ios_base::out);
    if (abs(x1 - x2) == abs(y1 - y2))
        oFile << "NO";
    else
        oFile << "YES";
    return 0;
}
