#include <fstream>
#include <string>

std::string  S{""};
void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    int N, ql, qr;
    iFile >> S >> N;
    bool *s =  new bool[S.length() + 1]();
    for(int i = 0; i < N; ++i){
        iFile >> ql >> qr;
        (ql > qr) ? --qr : --ql;
        s[ql] ^= true;
        s[qr] ^= true;
    }

    auto change{false};
    for(int i = 0; i < S.length(); ++i) {
        if (s[i])
            change ^= true;
        if (change)
            if (islower(S[i]))
                S[i] = toupper(S[i]);
            else
                S[i] = tolower(S[i]);
    }

    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << S;
    return 0;
}
