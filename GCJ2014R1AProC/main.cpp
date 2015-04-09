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
void GOOD(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int ri=rand()%(n-i)+i;
        swap(a[i], a[ri]);
    }
}
void BAD(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int ri=rand()%n;
        swap(a[i], a[ri]);
    }
}
int F(int a[], int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=i) cnt++;
    }
    return cnt;
}

int a[maxn], n, t, m;
int gcnt[1001], bcnt[1001];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("C-small-practice.in" , "r" , stdin);
    freopen ("C-small-practice.out" , "w" , stdout);
#endif
*/
    srand(time(NULL));
    int n=1000;

    int times=1000;
    ofstream g("gcnt.txt"), b("bcnt.txt");
    memset(gcnt, 0, sizeof(gcnt));
    for(int i=0;i<times;i++)
    {
        for(int i=0;i<n;i++) a[i]=i;
        GOOD(a, n);
        gcnt[F(a, n)]++;
    }
    memset(bcnt, 0, sizeof(bcnt));
    for(int i=0;i<times;i++)
    {
        for(int i=0;i<n;i++) a[i]=i;
        BAD(a, n);
        bcnt[F(a, n)]++;
    }
    for(int i=0;i<=n;i++) g<<gcnt[i]<<" ";
    for(int i=0;i<=n;i++) b<<bcnt[i]<<" ";
    /*
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int sum=0;
        for(int i=0;i<n;i++) if(a[i]<=i) sum++;
        printf("Case #%d: ", ti);
        puts(sum<(500+472)/2 ? "BAD" : "GOOD");
    }*/
	return 0;
}
