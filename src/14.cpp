#include <fstream>

constexpr int64_t mod = 1e9 + 7;
int N{0};
int M{0}, A, B, L;
int64_t **fstMatrix{nullptr};
int64_t **result{nullptr};
int64_t **tempMatr{nullptr};

void multSymMatr(int64_t **&res, int64_t **A, int64_t **B){
    for (int i = 1; i <= N; ++i )
        for (int j = i; j <= N; ++j){
            tempMatr[i][j] = 0;
            for (int k = 1; k <= N; ++k)
                tempMatr[i][j] = (tempMatr[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            tempMatr[j][i] = tempMatr[i][j];
        }
    int64_t **temp = tempMatr;
    tempMatr = res;
    res = temp;
}

void initMatrices(){
    fstMatrix = new int64_t*[N+1];
    tempMatr  = new int64_t*[N+1];
    result    = new int64_t*[N+1];
    for (int i = 1; i <= N; ++i){
        fstMatrix[i] = new int64_t[N+1];
        tempMatr[i]  = new int64_t[N+1];
        result[i]    = new int64_t[N+1];
        for (int j = 1; j <= N; ++j)
            fstMatrix[i][j] = tempMatr[i][j] = result[i][j] = 0;
    }
    for (int i = 1; i <= N; ++i) result[i][i] = 1;
}

void init(){
    std::fstream iFile("input.txt", std::ios_base::in);
    iFile >> N >> M >> A >> B >> L;
    initMatrices();
    int u, v;
    for (int i = 0; i < M; ++i){
        iFile >> u >> v;
        ++fstMatrix[u][v];
        ++fstMatrix[v][u];
    }
}

void calculate() {
    while (L)
        if (L % 2 == 0) {
            multSymMatr(fstMatrix, fstMatrix, fstMatrix);
            L /= 2;
        }
        else {
            multSymMatr(result, result, fstMatrix);
            --L;
        }
}

void output(){
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << result[A][B];
}

int32_t main() {
    init();
    calculate();
    output();
    return 0;
}


