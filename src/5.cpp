#include <fstream>
#include <list>
#include <queue>
constexpr uint64_t max_weight = UINT64_MAX;
struct edge{int b; uint64_t c;};

int main() {
    std::fstream iFile("input.txt", std::ios_base::in);
    int N{0}, M{0};
    iFile >> N >> M;
    std::list<edge> edges[N + 1]; // connected edges and its weight for each node
    std::list<int> lis; // очередь нечекнутых
    bool checked[N + 1]; for (int i = 0; i <= N; ++i) checked[i] = false;
    uint64_t  weight[N + 1];  for (int i = 0; i <= N; ++i) weight[i] = max_weight;
    int A, B;
    uint64_t C; // A, B - nodes of edge, C - weight
    for (int i = 0; i < M; ++i) {
        iFile >> A >> B >> C;
        edges[A].push_back(edge{B, C});
        edges[B].push_back(edge{A, C});
    }
    iFile >> A >> B; // A - from, B - to
    if (A == B) {
        std::fstream oFile("output.txt", std::ios_base::out);
        oFile << 0;
        return 0;
    }
    lis.push_back(A);
    weight[A] = 0;

    while (!lis.empty()){
        auto iter = lis.begin(); auto it = iter;
        for (; iter != lis.end(); ++iter)
            if (weight[*iter] < weight[*it]) it = iter;
        int cur = *it;
        lis.erase(it); checked[cur] = true;
        for (auto elem : edges[cur]){
            if (checked[elem.b]) continue;
            if (weight[elem.b] == max_weight) lis.push_back(elem.b);
            if (weight[cur] + elem.c < weight[elem.b]) weight[elem.b] = weight[cur] + elem.c;
        }
    }
    std::fstream oFile("output.txt", std::ios_base::out);
    oFile << weight[B]; return 0;
}
