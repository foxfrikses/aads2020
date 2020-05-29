#include <fstream>
#include <vector>

using namespace std;

struct point{int x; int y;};

bool **done{nullptr};
int N{0};
int M{0};
int nMoves{0};
point fin{0, 0};
auto *cur = new vector<point>{{2,2}};
auto *nxt = new vector<point>{{2, 2}};

void readFromFile();
void swap(vector<point>*& a, vector<point>*& b){
    auto c = a;
    a = b;
    b = c;
}

int main() {
    readFromFile();

    point temp[8];
    while(!done[fin.x][fin.y] & nxt->size() != 0){
        swap(cur, nxt);
        nxt->clear();
        for (auto e = (*cur).begin(); e != (*cur).end(); ++e){
            temp[0].x = (*e).x + 2; temp[0].y = (*e).y + 1;
            temp[1].x = (*e).x + 2; temp[1].y = (*e).y - 1;
            temp[2].x = (*e).x - 2; temp[2].y = (*e).y + 1;
            temp[3].x = (*e).x - 2; temp[3].y = (*e).y - 2;
            temp[4].x = (*e).x + 1; temp[4].y = (*e).y + 2;
            temp[5].x = (*e).x + 1; temp[5].y = (*e).y - 2;
            temp[6].x = (*e).x - 1; temp[6].y = (*e).y + 2;
            temp[7].x = (*e).x - 1; temp[7].y = (*e).y - 2;

            for (int i = 0; i < 8; ++i){
                if (!done[temp[i].x][temp[i].y]){
                    done[temp[i].x][temp[i].y] = true;
                    nxt->push_back(temp[i]);
                }
            }
        }
        ++nMoves;
    }

    std::fstream oFile("output.txt", std::ios_base::out);
    if (done[fin.x][fin.y])
        oFile << nMoves;
    else
        oFile << "NEVAR";
    return 0;
}

void readFromFile(){
    std::fstream iFile("input.txt", std::ios_base::in);
    iFile >> N >> M >> fin.x >> fin.y;
    ++fin.x;
    ++fin.y;
    N += 4;
    M += 4;

    done = new bool*[N];
    for(int i = 0; i < N; ++i){
        done[i] = new bool[M]();
    }
    for(int i = 0; i < N; ++i){
        done[i][0] = done[i][1] = done[i][M - 1] = done[i][M - 2] = true;
    }
    for(int i = 0; i < M; ++i){
        done[0][i] = done[1][i] = done[N - 1][i] = done[N - 2][i] = true;
    }
    done[2][2] = true;
}
