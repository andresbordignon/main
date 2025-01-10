#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
const int N = 201;  // numero máximo de nodos en el grafo (aulas + source + sink)
const int INF = INT_MAX;

bool bfs(int rGraph[N][N], int s, int t, int parent[]) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int grafo[N][N],int rGraph[N][N], int s, int t) {
    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            rGraph[u][v] = grafo[u][v];

    int padre[N];
    int max_flujo = 0;

    while (bfs(rGraph, s, t, padre)) {
        int path_flow = INF;
        for (int v = t; v != s; v = padre[v]) {
            int u = padre[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (int v = t; v != s; v = padre[v]) {
            int u = padre[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;

        }
        max_flujo+= path_flow;
    }
    return max_flujo;
}

int main() {
    int n, m;
    cin >> n >> m;

    const int h = 201;
    if ( m == 0) {
    cout << "NO" << endl;
    return 0;
    
    }


    // leo alumnos y capacidades
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int grafo[h][h] = {0};
    int rGrafo[h][h];
    int alumnos = 0;
    int source = h-2, target = h - 1;

    // conecto source a las aulas con capacidad ai y tambien con si mismas
    for (int i = 0; i < n; i++) {
        grafo[source][i] = a[i];  
        grafo[i][n + i] = INF;
    }

    // conectar las aulas entre sí
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        grafo[p][q + n] = INF;  // ACA HAY PROBLEMA.... ya no
        grafo[q][p + n] = INF;  // 
    }

    // Conectar las aulas a sUMIDERO
    for (int i = 0; i < n; i++) {
        grafo[i + n][target] = b[i];  // desde cada aula al sumidero con capacidad bi
        alumnos += b[i];   // acumulamos el total de alumnos
    }

    int max_flujo = fordFulkerson(grafo,rGrafo,source, target);
    if (max_flujo == alumnos) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grafo[i][ n + j] - rGrafo[i][n+j] << " "; 
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
