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
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int getint(){
	int t = 0, flag = 1;
	char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		t = t * 10 + c - '0';
		c = getchar();
	}
	return t*flag;
}
char b[50][50], ans[50][50];
bool ok=0;
bool v[50][50];
int solved, r,c,m,t;
bool outrange(int i, int j)
{
    return i>=r || i<0 || j>=c || j<0;
}
int getnei(int i, int j)
{
    int minecnt=0;
    for(int ii=i-1;ii<=i+1;ii++) for(int jj=j-1;jj<=j+1;jj++)
    {
        if(i==ii && j==jj || (outrange(ii, jj))) continue;
        if(b[ii][jj]=='*') minecnt++;
    }
    return minecnt;
}
int mine(int i, int j)
{
    if(v[i][j]||b[i][j]=='*') return 0;
    v[i][j]=1;
    int minecnt=getnei(i, j);
    if(minecnt) return 1;
    int revcnt=1;
    for(int ii=i-1;ii<=i+1;ii++) for(int jj=j-1;jj<=j+1;jj++)
    {
        if(i==ii && j==jj || (outrange(ii, jj))) continue;
        revcnt+=mine(ii, jj);
    }
    //v[i][j]=0;
    return revcnt;
}
void dfs(int i, int last)
{
    if(i==m)
    {
        for(int row=0;row<r;row++) for(int col=0;col<c;col++)
        {
            if(b[row][col]=='*') continue;
            memset(v, 0, sizeof(v));
            //unsolved=r*c-m;
            if(mine(row, col)==r*c-m)
            {
                for(int ii=0;ii<r;ii++) for(int jj=0;jj<c;jj++)
                    ans[ii][jj]=b[ii][jj];
                ans[row][col]='c';
                ok=1;
            }
        }
        return;
    }
    for(int j=last+1;j<r*c;j++)
    {
        b[j/c][j%c]='*';
        dfs(i+1, j);
        b[j/c][j%c]='.';
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("C-large-practice.in" , "r" , stdin);
    freopen ("C-large-practice.out" , "w" , stdout);
#endif

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        ok=0;
        cin>>r>>c>>m;
        for(int i=0;i<r;i++) memset(b[i], '.', sizeof b[i]);
        dfs(0, -1);
        printf("Case #%d:\n", ti);
        if(!ok) cout<<"Impossible"<<endl;
        else
        {
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
    }
	return 0;
}
