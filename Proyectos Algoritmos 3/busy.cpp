#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int cantMinima(vector<pair<int, int> > acts, int n) {
    int i, j;
    i = 0;
    int minimo = 1;

    for(j = 1; j < n; j++){
        if((acts[j]).first >= (acts[i]).second){
            i = j;
            minimo = minimo + 1;
        }
    }
    return minimo;
}
bool compararSegundo (pair<int, int> t1, pair<int,int>t2){
        return t1.second < t2.second;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int acts;
        cin >> acts;
        vector<pair<int, int> > actividades(acts, make_pair(0, 0));
        for (int j = 0; j < acts; j++){
            int a, b;
            cin >> a >> b;
            pair<int, int> t = make_pair(a, b);
            actividades[j] = t;
        }
        sort(actividades.begin(), actividades.end(), compararSegundo);
        cout << cantMinima(actividades, acts) << endl;
    }
    return 0;
  }

