#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool puedoPoner(vector<int> arr,int distancia, int vacas){
    int cantVacas = 1;
    int ultVaca = arr[0];
    for(int i = 1;i < arr.size();i++){
        if (arr[i]- ultVaca >= distancia){
            cantVacas +=1;
            ultVaca = arr[i];
        }
    }
    if (cantVacas >= vacas){
        return true;

    } else {
        return false;
    }
}
int distMinima(vector<int> arr, int vacas){
    int bajo = 0;
    int alto = arr[arr.size() - 1] - arr[0];
    while (bajo <= alto){
        int medio = (alto + bajo) / 2;
        if (puedoPoner(arr, medio, vacas) == true){
            int ans = medio;
            bajo = medio + 1;
        } else {
            alto = medio - 1;
        }
    }
    return alto;
    }

int main(){
    int testCases;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        int stalls;
        int cows;
        cin >> stalls >> cows;
        vector< int > stall(stalls, 0);
        for (int j = 0; j < stalls; j++){
            int a;
            cin  >> a;
            stall[j] = a;
        }
    sort(stall.begin(),stall.end());
    cout << distMinima(stall, cows)<<endl;
}
return 0;
}