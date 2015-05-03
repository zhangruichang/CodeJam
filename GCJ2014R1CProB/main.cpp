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
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
bool v[26];
string str[100];
int cnt, n;
void dfs(int i)
{
    if(i==n)
    {
        memset(v, 0, sizeof v);
        string tmp;
        for(int j=0;j<n;j++) tmp+=str[j];
        //cout<<tmp<<endl;
        for(int j=0;j<tmp.size();j++)
        {
            //cout<<j<<" ";
            if(j && tmp[j]==tmp[j-1]);
            else
            {
                if(v[tmp[j]-'a']) return ;
                v[tmp[j]-'a']=1;
            }
        }
        cnt++;
        return ;
    }
    for(int j=i;j<n;j++)
    {
        swap(str[i], str[j]);
        dfs(i+1);
        swap(str[i], str[j]);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("B-small-practice.in" , "r" , stdin);
    freopen ("B-small-practice.out" , "w" , stdout);
#endif

    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;cnt=0;
        for(int i=0;i<n;i++) cin>>str[i];
        dfs(0);
        printf("Case #%d: %d\n", ti, cnt);
    }
	return 0;
}
