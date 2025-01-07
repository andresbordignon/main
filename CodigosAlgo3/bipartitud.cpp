#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector< vector < int > > aristas;
vector<int> color;
long long sizeA, sizeB = 0;

void dfs(int v,int col) {
    color[v] = col;
    if (col == 0){
        sizeA++;
        }
    else{
        sizeB++;
    }
    for (int u : aristas[v]){
        if (color[u] == -1){
            dfs(u, 1-col);
        }
    }
}

int main() {
    int nodos;
    cin >> nodos;
    aristas.resize(nodos + 1);
    color.assign(nodos+1, -1);
    int a, b;
    for(int i = 0; i < nodos - 1; i++ ) {
        cin >> a >> b;
        aristas[a].push_back(b);
        aristas[b].push_back(a);
        
        }
    dfs(1,0);
    long long maxAristas = sizeA * sizeB;


    cout << maxAristas - (nodos - 1) << endl;
    return 0;
  }

