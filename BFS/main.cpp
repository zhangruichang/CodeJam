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
#include<sstream>
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
#define iOS  ios_base::sync_with_stdio(false)
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
LL a[maxn], n, t, m;

int getnum(LL n)
{
    int cnt=0;
    while(n) cnt++, n/=10;
    return cnt;
}
LL reversenum(LL n)
{
    LL ans=0;
    while(n) ans=ans*10+(n%10), n/=10;
    return ans;
}
int highbit(LL n)
{
    int cnt=getnum(n);
    return n/(LL)pow(10, cnt-1);
}


int main()
{

#ifndef ONLINE_JUDGE
    freopen ("E:\\CodeJam\\GCJ2015R1BProA\\A-small-attempt3.in" , "r" , stdin);
    freopen ("E:\\CodeJam\\GCJ2015R1BProA\\A-small-attempt3.out" , "w" , stdout);
#endif

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;
        queue<int> q;
        q.push(1);LL l=1;
        while(!q.empty())
        {
            int qsize=q.size();
            for(int qi=1;qi<=qsize;qi++)
            {
                int cur=q.front();q.pop();
                if(cur==n) goto L1;
                if(cur<reversenum(cur) && reversenum(cur)<=n)
                    q.push(reversenum(cur));
                q.push(cur+1);
            }
            l++;
        }
        L1:printf("Case #%d: %d\n", ti, l);
        //cout
    }
	return 0;
}
