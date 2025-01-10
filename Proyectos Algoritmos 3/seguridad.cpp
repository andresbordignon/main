#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

using namespace std;

const long long INF = 1e6;

// struct para manejar mejor las aristas
struct arista {
    int u, v, w;
};
// dijastra
vector<long long> dijastra(int inicio, int n, const vector<vector<arista>> grafo) {
    vector<long long> distancias(n, INF);


    distancias[inicio] = 0;
    
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;
    min_heap.push(make_pair(0, inicio));

    while (!min_heap.empty()) {
        long long dist_actual = min_heap.top().first;
        int nodo = min_heap.top().second;
        min_heap.pop();

        if (dist_actual > distancias[nodo]) continue;

        for (const auto arist : grafo[nodo]) {
            int vecino = arist.v;
            long long nueva_dist = dist_actual + arist.w;

            if (nueva_dist < distancias[vecino]) {
                distancias[vecino] = nueva_dist;
                min_heap.push(make_pair(nueva_dist, vecino));
            }
        }
    }

    return distancias;
}

long long calcularCaminoMinimo(int n, int m, const vector<tuple<int, int, int>> aristas) {
    vector<vector<arista>> grafo(n);
    
    // construyo el grafo
    for (const auto& [u, v, w] : aristas) {
        grafo[u].push_back({u, v, w});
        grafo[v].push_back({v, u, w});
    }

    // calculo las distancias minimas desde el nodo 0 y desde el nodo n-1
    vector<long long> dist_desde_0 = dijastra(0, n, grafo);
    vector<long long> dist_desde_n_1 = dijastra(n - 1, n, grafo);
    
    long long min_distancia = dist_desde_0[n - 1];

    long long costoTotal = 0;
    for (const auto [v, w, c] : aristas) {
        if ((dist_desde_0[v] + c + dist_desde_n_1[w] == min_distancia) ||
            (dist_desde_0[w] + c + dist_desde_n_1[v] == min_distancia)) {
            costoTotal +=  c; // doble de la longitud para el costo de seguridad
        }
    }

    return costoTotal;
}

int main() {

    std::ios::sync_with_stdio(false);

    
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> aristas(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        aristas[i] = make_tuple(u, v, w);
    }

    long long costoTotal = calcularCaminoMinimo(n, m, aristas);
    cout << 2 * costoTotal << endl;

    return 0;
}
