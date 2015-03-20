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
int a[maxn], n;
string str[maxn];
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int l, n, t;string pat;
    cin>>l>>n>>t;
    for(int i=0;i<n;i++) cin>>str[i];
    for(int ti=1;ti<=t;ti++)
    {
        unordered_set<char> mp[500];
        cin>>pat;int mpi=0;bool inpar=0;
        for(int i=0;i<pat.size();i++)
        {
            if(pat[i]=='(') inpar=1;
            else if(pat[i]==')') inpar=0, mpi++;
            else
            {
                mp[mpi].insert(pat[i]);
                if(!inpar) mpi++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=0;j<l;j++)
            {
                if(mp[j].find(str[i][j])==mp[j].end()) break;
            }
            if(j==l) cnt++;
        }
        printf("Case #%d: %d\n", ti, cnt);
    }
	return 0;
}
