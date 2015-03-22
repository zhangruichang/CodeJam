/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], n, t, m, maxcnt, repcnt;
vector<string> v[1000+1];
string str[1000+1];
void dfs(int i)
{
    if(i==m)
    {
        for(int j=0;j<n;j++) if(v[j].size()==0) return ;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            unordered_set<string> mp;
            for(int num=0;num<v[j].size();num++)
            {
                for(int l=1;l<=v[j][num].size();l++)
                    mp.insert(v[j][num].substr(0, l));
            }
            cnt+=mp.size();
        }
        cnt+=n;
        if(cnt>maxcnt) maxcnt=cnt,repcnt=1;
        else if(cnt==maxcnt) repcnt++;
        return ;
    }
    for(int j=0;j<n;j++)
    {
        if(v[j].size()>=(m-(n-1))) continue;
        v[j].push_back(str[i]);
        dfs(i+1);
        v[j].pop_back();
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("D-large-practice.in" , "r" , stdin);
    freopen ("D-large-practice.out" , "w" , stdout);
#endif

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        for(int i=0;i<n;i++) v[i].clear();
        cin>>m>>n;for(int i=0;i<m;i++) cin>>str[i];
        maxcnt=-1;
        dfs(0);
        printf("Case #%d: %d %d\n", ti, maxcnt, repcnt);
    }
	return 0;
}
