#include <fstream>

void Merge(int* perm, int l, int r, int m, int64_t &count){
    int res[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while(i <= m && j <= r){
        res[k] = std::min(perm[i], perm[j]);
        if (res[k] == perm[i])
            ++i;
        else{
            ++j;
            count += m - i + 1;
        }
        ++k;
    }
    if (i > m) {
        i = j;
        m = r;
    }
    while (i <= m)
        res[k++] = perm[i++];
    for (int k = 0; l <= r; ++l, ++k)
        perm[l] = res[k];
}

int64_t MergeSort(int* permut, int l, int r){
    if (l >= r) return 0;

    int64_t count{0};
    int m{(l + r) / 2};
    count += MergeSort(permut, l, m);
    count += MergeSort(permut, m + 1, r);
    Merge(permut, l, r, m, count);
    return count;
}

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    int N;
    iFile >> N;
    int perm[N];
    for (auto &elem : perm)
        iFile >> elem;
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << MergeSort(perm, 0, N-1);
}
