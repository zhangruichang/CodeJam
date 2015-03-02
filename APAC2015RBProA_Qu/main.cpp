#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL mod = 1e9 + 7;
LL dp[101][101];/*dp[i][j] choose i num to j heap and ervery num should at least once*/

void init()
{
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;

    for(LL i=1; i<=100; ++i)dp[i][i] = (dp[i-1][i-1]*i)%mod;
    for(LL i=1; i<=100; ++i) {
        for(LL j=i+1; j<=100; ++j) {
            dp[i][j] = i*(dp[i][j-1]+dp[i-1][j-1])%mod;
        }
    }
}

int main()
{
    //freopen("A-large-practice.in", "r",stdin);
    //freopen("A-large-practice.out","w",stdout);
    int n, m;
    init();int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin >> m >> n;
        printf("Case #%d: ",ti);
        cout<< dp[m][n] << endl;
    }


    return 0;
}
