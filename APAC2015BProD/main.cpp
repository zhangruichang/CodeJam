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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))


LL cat;
LL par[201][201];
const LL maxn=2e+18;
void add(LL &a, LL b)
{
	a += b;
	if (a >= maxn)
		a = maxn;
}

int main()
{
	freopen ("D-large-practice.in","r",stdin);
	freopen ("D-large-practice.out","w",stdout);

	par[1][1] = 1;
	for (int i=2;i<=200;i++){
		for (int j=0;j<i;j++){

			add(par[i][j+1],par[i-1][j]);
			if (j) add(par[i][j-1],par[i-1][j]);
		}
	}

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int n; LL k;
		scanf ("%d %lld",&n,&k); n *= 2;

		if (par[n][0] < k)
        {
			puts("Doesn't Exist!");
			continue;
		}

		k--;
		int u = 0;
		for (int i=0;i<n;i++)
        {
			if (k < par[n-i-1][u+1])
			{
				printf ("(");
				u++;
			}
			else
			{
				printf (")");
				k -= par[n-i-1][u+1];
                u--;
			}
		}
		puts("");
	}
	return 0;
}
