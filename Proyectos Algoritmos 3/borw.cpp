#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> lista;
vector<vector<vector<int> > > M;

int minimoSinPintar(int i, int ultNegro, int ultBlanco) {
    if (i >= lista.size()) return 0; 

    if (M[i][ultNegro + 1][ultBlanco + 1] != -1 ) {
        return M[i][ultNegro + 1][ultBlanco + 1];
    }

    int pintarNegro = INT_MAX;
    if (ultNegro == -1 || lista[i] > lista[ultNegro]) {
        pintarNegro = minimoSinPintar(i + 1, i, ultBlanco);
    }
    
    
    int pintarBlanco = INT_MAX;
    if (ultBlanco == -1 || lista[i] < lista[ultBlanco]) {
        pintarBlanco = minimoSinPintar(i + 1, ultNegro, i);
    }
    int noPintar = 1 + minimoSinPintar(i + 1, ultNegro, ultBlanco);
    
    return M[i][ultNegro + 1][ultBlanco + 1] = min(pintarNegro, min(pintarBlanco, noPintar));
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;  

        lista = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> lista[i];
        }

        
        M = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

        cout << minimoSinPintar(0, -1, -1) << endl;
    }

    return 0;
}