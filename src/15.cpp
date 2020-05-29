#include <fstream>

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    int N, last, cur;
    int64_t sum{0};
    iFile >> N >> last;
    int max{last};
    while (--N) {
        iFile >> cur;
        if (cur > max) {
            sum += cur - max;
            max = cur;
        }
        else if (cur < last)
            sum += last - cur;
        last = cur;
    }
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << sum;
    return 0;
}

