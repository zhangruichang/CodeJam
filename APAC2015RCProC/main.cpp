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
bool work[10];
int dp[maxn];
int F(int x)
{
    if(dp[x]) return dp[x];
    if(1<=x && x<=3)
    {
        if(!work[x]) return dp[x]=-1;
        return dp[x]=1;
    }
    dp[x]=INT_MAX;
    int tmp=x, digcnt=0;
    while(tmp)
    {
        if(!work[tmp%10])break;
        tmp/=10;
        digcnt++;
    }
    if(!tmp) return dp[x]=digcnt;
    for(int i=2;i<x;i++)
    {
        if(x%i) continue;
        int ans1=F(i), ans2=F(x/i);
        if(ans1==-1 || ans2==-1) continue;
        dp[x]=min(dp[x], F(i)+F(x/i)+1);
    }
    return dp[x]=(dp[x]==INT_MAX ? -1 : dp[x]);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("C-large-practice.in" , "r" , stdin);
    freopen ("C-large-practice.out" , "w" , stdout);
#endif
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        memset(dp, 0, sizeof dp);
        for(int i=0;i<10;i++) cin>>work[i];
        int x;
        cin>>x;
        int ans=F(x);
        printf("Case #%d: ",ti);
        if(ans!=-1) cout<<ans+1<<endl;//equal
        else cout<<"Impossible"<<endl;
    }
	return 0;
}
