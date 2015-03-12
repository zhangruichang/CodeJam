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
LL stoi(string s)
{
    LL sum=0;
    for(auto e: s) sum=sum*10+e-'0';
    return sum;
}
LL GCD(LL m, LL n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}

int Find(LL p, LL q)
{
    double dn=log2(double(q));
    LL i,j,n=(int)dn, ans=1; if(n!=dn) return -1;
    for(j=n;j-1>=0;j--)
    {
        if(p>=(1LL<<(j-1))) break;
        ans++;
    }
    if(j<0) return -1;
    else return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int t;LL p, q;
    cin>>t; string str;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>str;int pos=str.find('/');
        p=stoi(str.substr(0, pos)), q=stoi(str.substr(pos+1, str.size()-pos-1));
        LL gcd=GCD(p, q);
        LL ans= Find(p/gcd, q/gcd);
        printf("Case #%d: ", ti);
        if(ans!=-1) cout<<ans<<endl;
        else cout<<"impossible"<<endl;
    }
	return 0;
}
