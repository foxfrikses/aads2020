#include <fstream>
#include <algorithm>

int32_t main() {
    int N;
    std::fstream iFile("input.txt", std::ios_base::in);
    iFile >> N;
    int arr[N];
    for (int i = 0; i < N; ++i) iFile >> arr[i];
    std::sort(arr, arr + N);
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << std::max(int64_t(arr[0]) * arr[1], int64_t(arr[N-1]) * arr[N - 2]);
    return 0;
}


