#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
vector< vector < int > > aristas;
vector<int> energia;

void bfs(vector<vector<int> > ady, int s) 
{
    queue<int> cola;  
    vector<bool> visitado(ady.size(), false);
    visitado[s] = true;
    energia[s] = 0;
    cola.push(s);

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        for (int x : ady[actual]) {
            if (!visitado[x]) {
                visitado[x] = true;
                cola.push(x);
                energia[x] = energia[actual] + 1;
            }
        }
    }
}

int main() {
    int nodos;
    cin >> nodos;
    aristas.resize(nodos + 1);
    energia.assign(nodos + 1,-1);
    for(int i = 1; i < nodos; i++ ) {
        int a;
        if (i + 1 <= nodos) {
            aristas[i].push_back(i + 1);  
            aristas[i + 1].push_back(i);  
        }
        cin >> a;
        aristas[i].push_back(a);
        }
    
    bfs(aristas,1);
    for (int i = 1; i < energia.size(); i ++){
        cout << energia[i] << " ";
    }
    cout << endl;
    return 0;
  }
