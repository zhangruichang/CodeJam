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
int Index(char c)
{
    return ((c<='9' && c>='0') ? (c-'0') : (c-'a'+10));
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-small-practice.in" , "r" , stdin);
    freopen ("A-small-practice.out" , "w" , stdout);
#endif

    int t;string str;
    cin>>t;
    int mp[36];
    for(int ti=1;ti<=t;ti++)
    {
        fill(mp, mp+36, -2);
        cin>>str;LL cnt=0;LL n=str.size();
        for(LL i=0;i<n;i++)
        {
            int index=Index(str[i]);
            if(mp[index]==-2) mp[index]=-1,cnt++;;
        }
        LL wei=pow(cnt, n-1);
        int index=Index(str[0]);
        LL sum=wei;wei/=cnt;mp[index]=1;LL dig=0;
        for(LL i=1;i<n;i++)
        {
            int index=Index(str[i]);
            LL w;
            if(mp[index]==-1)
            {
                mp[index]=w=dig;
                dig++;
                if(dig==1) dig++;
            }
            else w=mp[index];
            sum+=(wei*w);
            wei/=cnt;
        }
        printf("Case #%d: %I64d\n", ti, sum);
    }
	return 0;
}
