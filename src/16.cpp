#include <fstream>
#include <list>
constexpr int ten = 10;

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    std::list<int> lst;
    int num{0};
    iFile >> num;
    int cur{0};
    lst.push_back(num % ten);
    num /= ten;
    while (num != 0){
        cur = num % ten;
        num /= ten;
        if (cur < lst.back()) {
            std::fstream oFile("output.txt", std::ios_base::out);
            if (num != 0) oFile << num;
            lst.push_back(cur);
            lst.sort();
            for (auto it = lst.begin(); it != lst.end(); ++it) if (*it > cur) {
                    oFile << *it;
                    lst.erase(it);
                    break;
                }
            for (auto e : lst) oFile << e;
            return 0;
        }
        else lst.push_back(cur);
    }

    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << -1;
    return 0;
}

