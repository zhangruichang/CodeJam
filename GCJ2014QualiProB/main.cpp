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

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("B-large-practice.in" , "r" , stdin);
    freopen ("B-large-practice.out" , "w" , stdout);
#endif

    int t;double x, c,f;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>c>>f>>x;
        double nd=(x*f-2*c)/(c*f);int n;
        if(nd<0) n=0;
        else n=(int)nd;
        double sum=0;
        for(int i=0;i<=n-1;i++)
            sum+=c/(2+i*f);
        sum+=x/(2+n*f);
        printf("Case #%d: %.7f\n", ti, sum);
    }
	return 0;
}
