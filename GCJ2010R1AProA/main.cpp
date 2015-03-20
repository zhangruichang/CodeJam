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
const int dx[8]={0, 0, -1, 1, -1, 1, -1, 1}, dy[8]={-1, 1, 0 ,0, -1, 1, 1, -1};
bool inrange(int i, int j)
{
    return i<n && i>=0 && j<n && j>=0;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int t, K;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>K;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int j=n-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                if(str[i][j]=='.') continue;
                int k=j+1;
                while(k<n && str[i][k]=='.') k++;
                if(k==j+1) continue;
                str[i][k-1]=str[i][j];
                str[i][j]='.';
            }
        }
        //cout<<endl;
        //for(int i=0;i<n;i++) cout<<str[i]<<endl;
        bool r=0, b=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        {
            char cur=str[i][j];
            if(cur=='.') continue;
            int rowc=1, colc=1, first=1, second=1;
            for(int k=0;k<8;k++)
            {
                int ii=i, jj=j;
                int cnt=0;
                while(inrange(ii+dx[k], jj+dy[k]) && str[ii+dx[k]][jj+dy[k]]==cur) ii+=dx[k], jj+=dy[k], cnt++;
                if(k<2) rowc+=cnt;
                else if(k<4) colc+=cnt;
                else if(k<6) first+=cnt;
                else second+=cnt;
            }
            if(rowc>=K || colc>=K ||first>=K || second>=K)
            {
                //cout<<i<<" "<<j<<" "<<rowc<<" "<<colc<<" "<<first<<" "<<second<<endl;
                if(cur=='R') r=1;
                else if(cur=='B') b=1;
            }
        }
        printf("Case #%d: ", ti);
        if(r && b) cout<<"Both"<<endl;
        else if(!r && b) cout<<"Blue"<<endl;
        else if(r && !b) cout<<"Red"<<endl;
        else cout<<"Neither"<<endl;
    }
	return 0;
}
