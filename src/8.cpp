#include <fstream>
#include <string>

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    std::string S;
    iFile >> S;
    int l{0};
    for(int f = 0, s = S.length() - 1; f < s; ++f, --s)
        if (S[f] != S[s]){
            std::fstream oFile("output.txt", std::ios_base::out);
            oFile << S.length();
            return 0;
        }
    char temp = S[S.length() - 1];
    for(int i = 0; i <= S.length() / 2; ++i)
        if (S[i] != temp) {
            std::fstream oFile("output.txt", std::ios_base::out);
            oFile << S.length() - 1;
            return 0;
        }
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << -1;
    return 0;
}

