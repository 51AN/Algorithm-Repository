#include<bits/stdc++.h>

using namespace std;
// int numSquares1(int n){
//     vector<int>squareList;
//     queue<int>q;
//     vector<int>dis(n+1,INT16_MAX);
//     for(int i = 1; i*i <=n; i++){
//         squareList.push_back(i*i);
//         q.push(i*i);
//         dis[i*i] = 1;
//     }
//     while(!q.empty()){
//         int temp = q.front();
//         q.pop();

//         for(auto u:squareList){
//             int nxtVal = temp + u;
//             if(nxtVal>n) continue;
//             if(dis[temp] + 1 < dis[nxtVal]){
//                 dis[nxtVal] = dis[temp] + 1;
//                 q.push(nxtVal);
//             }
//         }
//     }

//     return dis[n];
    
// }

int numSquares(int n) {
        vector<int> dp(n + 1, (int) 1e9);
        dp[0] = 0;

        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; (j*j) < i + 1 ; j++){
                dp[i] = min(dp[i], dp[i - (j*j)] + 1);
            }
        }

        return dp[n];
    }

int main(){
    int n;
    cin>>n;
    cout<<numSquares(n)<<endl;
}