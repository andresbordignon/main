#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <unordered_map>
using namespace std;
// la idea va a ser, armar el grafo y el peso de cada arista dependerá de si cada arista en particular tiene precio
// además, ese precio sera el costo de la arista si precio < ax + ay y luego con los pesos definidos,
// armar el arbol generador minimo(prim o kruskal). la suma de los costos del arbol será el numero que nos pide el ejercicio.
// probablemente trate de usar prim para que no quepa ninguna posibilidad de que SALTE copia AL EnTREGAR
// no pude usar prim por que usa matriz de adyacencias y armé todo con lista de aristas

//kruskal con path compression 
class kruskal {
    vector<int> padre, rango;

public:
    kruskal(long long n) {
        padre.resize(n, -1);
        rango.resize(n, 1);
    }

    int encontrar(long long i) {
        if (padre[i] == -1)
            return i;
        return padre[i] = encontrar(padre[i]);
    }

    bool unite(long long  x, long long y) {
        int s1 = encontrar(x);
        int s2 = encontrar(y);

        if (s1 != s2) {
            if (rango[s1] < rango[s2]) {
                padre[s1] = s2;
            } else if (rango[s1] > rango[s2]) {
                padre[s2] = s1;
            } else {
                padre[s2] = s1;
                rango[s1]++;
            }
            return true;
        }
        return false; 
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    
    int piezas, ofertas;
    cin >> piezas >> ofertas;
    vector<long long> a(piezas);

    // el codigo tiro memory limit porque estoy agregando demasiadas aristas (2*10**10 en el peor caso)
    // optimizo para ocupar menos memoria buscando el nodo con minimo costo que lo encuentro casi gratis y conecto todas las piezas a ese nodo
    int nodominimo = 0;
    for (int i = 0; i < piezas; i++) {
        cin >> a[i];
        if(a[i] < a[nodominimo]){
            nodominimo = i;
        }
        }

    //si ofertas == 0 es decir, no hay ofertas, el resultado será simplemente conectar todas las aristas al nodo de menor costo, de esta forma el grafo resultará conexo y minimizará el costo
    if (ofertas == 0){
        long long costo = 0;
        for(long long i = 0; i < piezas; i++){
            if(i != nodominimo){
                costo += a[i] + a[nodominimo];
            }
        }
        cout << costo << endl;
        return 0;
    }

    vector<tuple<long long, long long, long long>> aristas;
    unordered_map<long long, long long> oferts;
    auto mapear = [](int x,int y){
        return(long long) min(x,y) * ((long long) 2e5 +1) + max(x, y);
    };

    //leer ofertas.
    for (int i = 0; i < ofertas; i++) {
        long long x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        long long clave = mapear(x, y);
        if (oferts.find(clave) == oferts.end() || w < oferts[clave]){
            oferts[clave] = w;
        }
    }
    //agrego ofertas
    for(auto [clave,costo] : oferts){
        int x = clave / ((long long) 2e5 + 1);
        int y = clave % ((long long) 2e5 + 1);
        if(x < piezas && y < piezas && x!=y){
            aristas.emplace_back(costo, x, y);}
    }
    
    // conecto nodos al de menor costo
    for(int i = 0; i < piezas; i++){
        if(i != nodominimo){
            long long costo = a[i] + a[nodominimo];
            long long clave = mapear(i, nodominimo);
            if (oferts.find(clave) != oferts.end()){
                costo = min(costo, oferts[clave]);
            }
            aristas.emplace_back(a[i] + a[nodominimo], i, nodominimo);
            }
        }

    sort(aristas.begin(), aristas.end());

    kruskal kruskal(piezas);
    long long costotoal = 0;
    for (auto [costo, u, v] : aristas) {
        if (kruskal.unite(u, v)) {
            costotoal += costo;
        }
    }

    cout << costotoal << endl;


}