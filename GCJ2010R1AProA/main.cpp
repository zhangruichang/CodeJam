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
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int t, n, K;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>K;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int j=n-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                int k=j+1;
                while(k<n && str[i][k]=='.') k++;
                if(k==j+1) continue;
                str[i][k-1]=str[i][j];
                str[i][j]='.';
            }
        }
        for(int i=0;i<n;i++) cout<<str[i]<<endl;

        bool r=0, b=0;
        int rcnt, bcnt;
        for(int i=0;i<n;i++)
        {
            rcnt=0, bcnt=0;
            for(int j=0;j<n;j++)
            {
                if(str[i][j]=='R') rcnt++;
                else if(str[i][j]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }
        for(int j=0;j<n;j++)
        {
            rcnt=0, bcnt=0;
            for(int i=0;i<n;i++)
            {
                if(str[i][j]=='R') rcnt++;
                else if(str[i][j]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }


        for(int i=n-1;i>=0;i--)
        {
            rcnt=0, bcnt=0;
            for(int j=0, k=i;j<n && k<n;j++, k++)
            {
                if(str[k][j]=='R') rcnt++;
                else if(str[k][j]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }
        for(int j=1;j<n;j++)
        {
            rcnt=0, bcnt=0;
            for(int i=0, k=j;k<n && i<n;i++, k++)
            {
                if(str[i][k]=='R') rcnt++;
                else if(str[i][k]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }



        for(int i=0;i<n;i++)
        {
            rcnt=0, bcnt=0;
            for(int j=0, k=i;j<n && k>=0;j++, k--)
            {
                if(str[k][j]=='R') rcnt++;
                else if(str[k][j]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }
        for(int j=1;j<n;j++)
        {
            rcnt=0, bcnt=0;
            for(int i=n-1, k=j;k<n && i>=0;i--, k++)
            {
                if(str[i][k]=='R') rcnt++;
                else if(str[i][k]=='B') bcnt++;
            }
            if(rcnt==K) r=1;
            if(bcnt==K) b=1;
        }
        printf("Case #%d: ", ti);
        if(r && b) cout<<"Both"<<endl;
        else if(!r && b) cout<<"Blue"<<endl;
        else if(r && !b) cout<<"Red"<<endl;
        else cout<<"Neither"<<endl;
    }
	return 0;
}
