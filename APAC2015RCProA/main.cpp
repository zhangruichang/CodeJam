#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
//bool v[maxn][maxn];
int n;
string board[maxn];
const int dx[]={-1, 0, 1, -1, 1, -1, 0, 1}, dy[]={-1,-1,-1,0,0,1,1,1};

bool out(int i, int j)
{
    if(i<0 || i>=n ||j<0 || j>=n) return 1;
    return 0;
}
int neigh(int i, int j)
{
    int cnt=0;
    for(int k=0; k<8;k++)
    {
        int nx=i+dx[k], ny=j+dy[k];
        if(out(nx, ny))continue;
        if(board[nx][ny]=='*') cnt++;
    }
    return cnt;
}

void dfs(int i, int j)
{
    if(out(i, j)) return ;
    if(board[i][j]!='.') return ;
    int cnt=neigh(i, j);
    board[i][j]='0'+cnt;
    if(cnt) return ;
    for(int k=0;k<8;k++)
    {
        int nx=i+dx[k], ny=j+dy[k];
        dfs(nx, ny);
    }
}

int main()
{
    freopen("A-small-practice.in","r",stdin);
    freopen("A-small-practice.out","w",stdout);
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>board[i];
        int cnt=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.' && neigh(i,j)==0) cnt++, dfs(i, j);
        }
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]=='.') cnt++;
        cout<<"Case #"<<ti<<": "<<cnt<<endl;
    }
	return 0;
}
