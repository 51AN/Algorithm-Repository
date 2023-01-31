#include<bits/stdc++.h>
#define ll                                               long long int
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0));
#define re                        return 0;
#define nl                                                "\n"
#define f(i,n)                                           for(int i = 0 ; i < n ; i ++)
#define f1(i,n)                                          for(int i = 1 ; i <= n ; i ++)
#define fb(i,n)                                          for(int i = n - 1 ; i => 0 ; i --)
#define v(i)                                             vector<int>v[i];
#define sortv(a)                                         sort(a.begin(),a.end())
#define test(t)                                          ll t; cin>>t; while(t--)
#define YES                                              cout<<"YES"<<endl
#define NO                                               cout<<"NO"<<endl

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    map<int, vector<int>> graph;
        vector <int> inOrder(numCourses,0);
        queue<int> q;
        for(auto v:prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            inOrder[v[0]]++;
        }
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(inOrder[i]==0)
            q.push(i);
        }
        vector<int> out;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            out.push_back(temp);
            for(int i:graph[temp])
            {
                inOrder[i]--;
                if(inOrder[i]==0)
                q.push(i);
            }
        }
        if(out.size() == numCourses)
            return out;
        else return {};
}


int main(){
    fastIO;
    vector<vector<int>>preq = {{1,0},{2,0},{3,1},{3,2}} ;
    // vector<vector<int>>preq = {{2,1},{3,1},{7,2},{7,3},{9,7},{8,7},{4,5},{6,4},{8,6}} ;
    vector<int> output = findOrder(4, preq);
    f(i,output.size()){
        cout<<output[i]<<" ";
    }
    re;
}