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
#define inf 0x3f3f3f3f
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
	int t = 0, flag = 1; char c = getchar();
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
string x, y;
int dp[101][101];
int MinEdit()
{
    int m=x.size(), n=y.size();
    dp[0][0]=0;
    for(int i=1;i<=m;i++) dp[i][0]=inf;
    for(int j=1;j<=n;j++) dp[0][j]=inf;
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++)
    {
        dp[i][j]=inf;
        if(x[i-1]==y[j-1])
            dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
        if(i>=2 && x[i-1]==x[i-2]) dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
        if(j>=2 && y[j-1]==y[j-2]) dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
    }
    return dp[m][n];
}

int chcnt[100][100];
int n, l;
string str[100];
int ch[100];
int MulEdit()
{

    int repcnt=0, chi=0, chcnti=0;
    for(int j=0;j<str[0].size();j++)
    {
        if(j && str[0][j]==str[0][j-1]) repcnt++;
        else
        {
            if(!j) repcnt++;
            else chcnt[chcnti++][0]=repcnt, repcnt=1;
            ch[chi++]=str[0][j]-'a';
        }
    }
    chcnt[chcnti++][0]=repcnt;
    l=chcnti;



    for(int i=1;i<n;i++)
    {
        repcnt=0;chcnti=0;chi=0;
        for(int j=0;j<str[i].size();j++)
        {
            if(j && str[i][j]==str[i][j-1]) repcnt++;
            else
            {
                if(!j) repcnt++;
                else chcnt[chcnti++][i]=repcnt, repcnt=1;
                if(chi<l && ch[chi++]==str[i][j]-'a');
                else
                {
                    return -1;
                }
            }
        }
        chcnt[chcnti++][i]=repcnt;
        if(chcnti!=l) return -1;
    }

    int transcnt=0;
    for(int i=0;i<l;i++)
    {
        sort(chcnt[i], chcnt[i]+n);
        int median=chcnt[i][n/2];
        for(int j=0;j<n;j++) transcnt+=abs(median-chcnt[i][j]);
    }
    return transcnt;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int t;

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>str[i];
        printf("Case #%d: ", ti);
        int ans=MulEdit();
        if(ans!=-1) cout<<ans<<endl;
        else cout<<"Fegla Won"<<endl;
    }
	return 0;
}
