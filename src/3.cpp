#include <fstream>
#include <vector>
#include <algorithm>
constexpr long long int d = 1e9 + 7;
void swap(std::vector<int> &A, int a, int b){
    int t = A[a];
    A[a] = A[b];
    A[b] = t;
}

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    int N, K;
    iFile >> N >> K;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) iFile >> nums[i];
    if (N > K) {
        sort(nums.begin(), nums.end(), [](int i, int j) { return (abs(i) > abs(j)); });
        bool sign = false;
        for (int i = 0; i < K; ++i) sign ^= nums[i] < 0;
        if (sign){
            bool l_found{false}, r_found{false};
            int l{0}, r{0};
            for (int i = K + 1; i < N; ++i) {
                if ((int64_t)nums[K - 1] * nums[i] <= 0){
                    r_found = true; r = i; break;
                }
            }
            for (int i = K - 2; i >= 0; --i) {
                if ((int64_t)nums[K] * nums[i] <= 0){
                    l_found = true; l = i; break;
                }
            }
            if (l_found){
                if (r_found){
                    if ((int64_t)nums[K]*nums[K-1] > 0) {
                        if ((int64_t)nums[r] * nums[l] > (int64_t)nums[K] * nums[K - 1])
                            swap(nums, r, K-1);
                        else swap(nums, l, K);
                    } else{
                        if ((int64_t)nums[K] * nums[l] > (int64_t)nums[K - 1] * nums[r])
                            swap(nums, K, K-1);
                        else swap(nums, r, l);
                    }
                } else{
                    if ((int64_t)nums[K]*nums[K-1] > 0)
                        swap(nums, l, K);
                    else swap(nums, K, K-1);
                }
            }
            else if (r_found){
                if ((int64_t)nums[K]*nums[K-1] > 0) swap(nums, r, K-1);
                else swap(nums, K, K-1);
            }
            else{
                if ((int64_t)nums[K]*nums[K-1] < 0){
                    swap(nums, K, K-1);
                }
                else std::reverse(std::begin(nums), std::end(nums));
            }
        }
    }
    int64_t result{1};
    for (int i = 0; i < K; ++i){
        result *= nums[i];
        result %= d;
    }

    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << (result + d)%d;
    return 0;
}
