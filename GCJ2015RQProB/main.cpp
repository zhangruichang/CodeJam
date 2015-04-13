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
typedef vector<int> vi;
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
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
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("B-large.in" , "r" , stdin);
    freopen ("B-large.out" , "w" , stdout);
#endif

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        int n, maxVal = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            maxVal = max(maxVal, a[i]);
        }
        int ans = INF;
        for (int j = 1; j <= maxVal; j++)
        {
            int curAns = 0;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0, tmp = a[i];
                if(tmp>j) cnt=( (tmp%j==0) ? (tmp/j-1) : (tmp/j));
                curAns += cnt;
            }
            ans = min(ans, curAns + j);
        }
        printf("Case #%d: %d\n", ti, ans);
    }
	return 0;
}
