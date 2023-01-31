#include<bits/stdc++.h>

using namespace std;

int numSquares(int n){
    vector<int>squareList;
    queue<int>q;
    vector<int>dis(n+1,INT16_MAX);
    for(int i = 1; i*i <=n; i++){
        squareList.push_back(i*i);
        q.push(i*i);
        dis[i*i] = 1;
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(auto u:squareList){
            int nxtVal = temp + u;
            if(nxtVal>n) continue;
            if(dis[temp] + 1 < dis[nxtVal]){
                dis[nxtVal] = dis[temp] + 1;
                q.push(nxtVal);
            }
        }
    }

    return dis[n];
    
}

int main(){
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
}