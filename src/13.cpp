#include <fstream>
#include <vector>

std::vector<int> *nodes = nullptr;
bool *done = nullptr;
int N = 0;
int M = 0;

void readFromFile();
void dfs(int);
int getNumComponent();

int main() {
    readFromFile();

    std::fstream oFile("output.txt", std::ios_base::out);
	if(getNumComponent() != 1)
		oFile << -1;
	else
		oFile << M - N + 1;			
    
    return 0;
}

void readFromFile(){
    std::fstream iFile("input.txt", std::ios_base::in);
    iFile >> N >> M;

    nodes = new std::vector<int>[N + 1]; // 1st elem wil not be used
    done = new bool[N + 1]();

    int first, second;
    while (iFile >> first >> second){
        nodes[first].push_back(second);
        nodes[second].push_back(first);
    }
}

void dfs(int cur){
    done[cur] = true;
    for (int i = 0; i < nodes[cur].size(); ++i){
        int next = nodes[cur][i];
        if (!done[next])
            dfs(next);
    }
}

int getNumComponent(){
    int count = 0;
    for (int i = 1; i <= N; ++i){
        if (!done[i]){
            dfs(i);
            ++count;
        }
    }
    return count;
}
