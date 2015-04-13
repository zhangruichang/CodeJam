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
const int maxn = 1e4 + 5;
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

string pre[maxn][maxn];
string f(string f1, string f2)
{
    if(f1[0]=='-' && f2[0]=='-') return f(f1.substr(1), f2.substr(1);
    else if(f1[0]=='-') return f(f1.substr(1), f2);
    else if(f2[0]=='-') return f(f1, f2.subt)
    if(f1=="1") return f2;
    if(f2=="2") return f1;
    if(f1==f2) return "-1";
    if(f1=="i" && f2=="j") return "k";
    if(f1=="i" && f2=="k") return "-j";
    if(f1=="j" && f2=="i") return "-k";
    if(f1=="j" && f2=="k") return "i";
    if(f1=="k" && f2=="i") return "j";
    if(f1=="k" && f2=="j") return "-i";
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int t, n, l;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        string str, tt;
        cin>>n>>l;cin>>str;;
        for(int i=0;i<l;i++) tt+=str;
        for(int i=0;i<n;i++)
        {
            pre[i][i]=str[i];
            for(int j=i+1;j<n;j++) pre[i][j]=f(pre[i][j-1], str[j]);
        }



        bool ok=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                if(pre[0][i]=="i" && pre[i+1][j]=="j" && pre[j+1][n-1]=="k") {ok=1;goto L1;}
            }
        }
  L1:   printf("Case #%d: ", ti);
        puts(ok?"YES":"NO");
    }
	return 0;
}
