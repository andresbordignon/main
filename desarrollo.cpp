#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iomanip>

using namespace std;

const int INF = 1e6;


vector<long long> floydWarshallMod(vector<vector<long long> >& distancias, vector<long long> sumasTotales, vector<bool> activo, long long n, vector<int> orden) {
    // a cada paso se marca como activo un nodo, esto quiere decir que es "tenido en cuenta" en ese paso para calcular la suma de las distancias
    for (long long k = n - 1; k >= 0; k--) {
        long long nodo_actual = orden[k];
        activo[nodo_actual] = true;
        long long suma_distancias = 0;

        // actualizo las distancias mínimas usando floyd warshall
        for (long long fila = 0; fila < n; fila++) {
            for (int colum = 0; colum < n; colum++) {
                distancias[fila][colum] = min(distancias[fila][colum], distancias[fila][nodo_actual] + distancias[nodo_actual][colum]);
                if (activo[fila] && activo[colum]) {
                    suma_distancias +=distancias[fila][colum];}
            }
        }

        sumasTotales[k] = suma_distancias;
    }
    return sumasTotales;

}
int main() {
    std::ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    // armo la matriz de distancias
    vector<vector<long long> > dist(n, vector<long long>(n));
    for (int fila = 0; fila < n; fila++) {
        for (int columna = 0; columna < n; columna++) {
            cin >> dist[fila][columna];
            if (dist[fila][columna] == 0 && fila != columna && columna != fila) {
                dist[fila][columna] = INF;
            }
        }
    }
    // leo el orden
    vector<int> orden(n);
    for (int i = 0; i < n; i++) {
        cin >> orden[i];
        orden[i]--;  
    }
    // inicializo las estructuras
    vector<long long> sumasTotales(n, 0);
    vector<bool> activo(n, false);
    
    sumasTotales = floydWarshallMod(dist, sumasTotales, activo, n, orden);

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << sumasTotales[i] << " ";
    }
    

    return 0;
}
