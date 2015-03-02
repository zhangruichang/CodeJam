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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

ULL n, k, kth;;
string ans;
void Ge(string x, ULL a, ULL b)
{
    if(a+b==2*n)
    {
        if(kth==k) ans=x;
        kth++;
    }
    else
    {
        if(a<n) Ge(x+"(", a+1, b);
        if(b<a) Ge(x+")", a, b+1);
    }
}

int main()
{
    int t;cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>k;kth=1;ans="";
        Ge("", 0,0);
        cout<<"Case #"<<ti<<": "<<(ans==""? "Doesn't Exist!" : ans)<<endl;
    }
	return 0;
}
