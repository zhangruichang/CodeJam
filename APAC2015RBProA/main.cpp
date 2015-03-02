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
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19


LL dp[maxn][maxn];
const LL MOD=1e9+7;
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    LL t;
    cin>>t;
    for(LL ti=1;ti<=t;ti++)
    {
        LL m, n;
        cin>>m>>n;//m<=n
        for(LL j=1;j<=n;j++) dp[1][j]=1ll;
        for(LL i=2;i<=m;i++) dp[i][i]=(dp[i-1][i-1]*i)%MOD;
        for(int i=2;i<=m;i++) for(int j=i+1;j<=n;j++)
            dp[i][j]=(i*(dp[i][j-1]+dp[i-1][j-1]))%MOD;
        printf("Case #%d: ",ti);
        cout<<dp[m][n]<<endl;
    }

	return 0;
}
