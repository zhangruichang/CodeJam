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
string in[150], out[150], tmp[150];
int mincnt, n, l;

void dfs(int i, int cnt)
{
    if(i==l)
    {
        for(int i=0;i<n;i++) tmp[i]=in[i];
        sort(tmp, tmp+n);
        for(int i=0;i<n;i++) if(tmp[i]!=out[i]) return ;
        mincnt=min(mincnt, cnt);
        return ;
    }
    dfs(i+1, cnt);
    for(int j=0;j<n;j++)
    {
        in[j][i]=(in[j][i]=='1'?'0':'1');
    }
    dfs(i+1, cnt+1);
    for(int j=0;j<n;j++)
    {
        in[j][i]=(in[j][i]=='1'?'0':'1');
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        hasht.clear();
        cin>>n>>l;
        for(int i=0;i<n;i++) cin>>in[i];
        for(int i=0;i<n;i++) cin>>out[i];
        sort(out, out+n);
        //for(auto e: out) cout<<e<<endl;
        mincnt=l+1;
        dfs(0, 0);
        /*
        int j, mincnt=0;
        for(j=0;j<l;j++)
        {
            int in0=0, in1=0, out0=0, out1=0;
            for(int i=0;i<n;i++)
            {
                if(in[i][j]=='0') in0++;
                else in1++;
                if(out[i][j]=='0') out0++;
                else out1++;
            }
            //cout<<in0<<" "<<in1<<" "<<out0<<" "<<out1<<endl;
            if(in0==out0 && in1==out1);
            else if(in0==out1 && in1==out0) mincnt++;
            else break;
        }
        */
        printf("Case #%d: ", ti);
        if(mincnt==l+1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<mincnt<<endl;
    }
	return 0;
}
