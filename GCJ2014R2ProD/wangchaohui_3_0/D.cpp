#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime> 
using namespace std;
#define FRsmall(x,y) do{freopen(#x"-small-attempt"#y".in","r",stdin);freopen(#x"-small-attempt"#y".out","w",stdout);}while(0)
#define FRlarge(x) do{freopen(#x"-large.in","r",stdin);freopen(#x"-large.out","w",stdout);}while(0)
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin( 
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax( 
#define SIZE(x) ((int)(x).size()) 
#define for0(i,n) for(int i=0;i<(n);i++) 
#define for1(i,n) for(int i=1;i<=(n);i++) 
#define for0r(i,n) for(int i=(n)-1;i>=0;i--) 
#define for1r(i,n) for(int i=(n);i>=1;i--) 
typedef long long ll;
typedef vector<int> vi;

char s[8][11];
int m, n;
set<string> S[4];
int c[8];
int mmax;
int mc;

void dfs(int now)
{
    if (now == m)
    {
        for0(i, n)S[i].clear();
        for0(i, m)
        {
            for (int j = -1; j == -1 || s[i][j]; j++)
            {
                S[c[i]].insert(string(s[i], j + 1));
            }
        }
        int cc = 0;
        for0(i, n)
        {
            if (S[i].empty())return;
            cc += S[i].size();
        }
        if (cc > mmax)
        {
            mmax = cc;
            mc = 1;
        }
        else if (cc == mmax)
            mc++;
        return;
    }
    for (c[now] = 0; c[now] < n; c[now]++)
        dfs(now + 1);
}

void solve()
{
    scanf("%d %d", &m, &n);
    for0(i, m)scanf("%s", s[i]);
    mmax = 0;
    dfs(0);
    printf("%d %d\n", mmax, mc);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    FRsmall(D, 0);
    //FRlarge(D);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d: ", TC);
        solve();
    }
    return 0;
}
