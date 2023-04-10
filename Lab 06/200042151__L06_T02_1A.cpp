#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int n, mat[MAXN][MAXN], dp[1<<MAXN];

int maxim = -1;

bool isOn(int N,int pos){
    return (bool)(N & (1<<pos)) ;
}
int turnOn(int N,int pos){
    return (N | (1<<pos));
}

int bitMarriage(int mask, int k){
    if(mask == (1<<n) - 1)
        return 0;
    maxim = 0;
    for(int i = 0; i<n; i++){
        if(!(isOn(mask,i))){
            maxim = max(bitMarriage(turnOn(mask, i), k +  1 ) + mat[k][i], maxim);
        }
    }
    return maxim;
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
        }
    }
    cout<<"Output : "<<bitMarriage(0, 0);
    return 0;
}
