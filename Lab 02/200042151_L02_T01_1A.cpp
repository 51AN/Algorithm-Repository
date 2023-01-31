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
int min_step,chess[10][10];
int dx,dy;
int knight_moves[8][2]={2,1,2,-1,1,2,1,-2,
                        -1,2,-1,-2,-2,1,-2,-1};

struct node
{
    int x,y;
    int step;
};

void bfs(int x,int y)
{
    queue<node>q;
    node curr,nxt;
    curr.x=x;
    curr.y=y;
    curr.step=0;
    chess[curr.x][curr.y]=1;
    q.push(curr);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        if(curr.x == dx && curr.y == dy)
        {
            min_step=curr.step;
            return ;
        }
        for(int i=0;i<8;i++)
        {
            int xx = curr.x + knight_moves[i][0];
            int yy = curr.y + knight_moves[i][1];
            if(chess[xx][yy]||xx<1||yy<1||xx>8||yy>8)//out of bounds and if matched don't check
                continue;
            chess[xx][yy] = 1;//traversed
            nxt.x = xx;
            nxt.y = yy;
            nxt.step = curr.step+1;
            q.push(nxt);
        }
    }
    return ;
}


int main(){

    fastIO;
    char start[3],dest[3];
     while(scanf("%s %s",start,dest))
     {
         memset(chess,0,sizeof(chess));
         int x=start[0]-'a'+1;
         int y=start[1]-'0';
         dx=dest[0]-'a'+1;
         dy=dest[1]-'0';
         bfs(x,y);
         printf("To get from %s to %s takes %d knight moves.\n",start,dest,min_step);
     }



    re;

}