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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
int mincnt, n, l;
string cur[151], str[151], out[151], tmp[151];
void dfs(int i, int cnt)
{
    if(i==l)
    {
        for(int i=0;i<n;i++) cur[i]=str[i];
        sort(cur, cur+n);
        for(int i=0;i<n;i++) if(cur[i]!=out[i]) return ;
        mincnt=min(mincnt, cnt);
        return ;
    }
    dfs(i+1, cnt);
    for(int j=0;j<n;j++) str[j][i]=(str[j][i]=='1' ? '0' : '1');
    dfs(i+1, cnt+1);
    for(int j=0;j<n;j++) str[j][i]=(str[j][i]=='1' ? '0' : '1');
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-large-practice.in" , "r" , stdin);
    freopen ("A-large-practice.out" , "w" , stdout);
#endif

    int t;cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>l;for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<n;i++) cin>>out[i];
        sort(out, out+n);int mincnt=l+1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) tmp[j]=str[j];
            int cnt=0;
            for(int j=0;j<l;j++)
            {
                if(tmp[i][j]!=out[0][j])
                {
                    cnt++;
                    for(int k=0;k<n;k++)
                    {
                        tmp[k][j]=(tmp[k][j]=='1' ? '0' : '1');
                    }
                }
            }
            sort(tmp, tmp+n);int j;
            //for(int j=0;j<n;j++) cout<<"str: "<<tmp[j]<<" "<<out[j]<<endl;
            for(j=0;j<n;j++) if(tmp[j]!=out[j]) break;
            //cout<<"mincnt: "<<mincnt<<" cnt: "<<cnt<<" j"<<j<<endl;
            if(j==n) mincnt=min(mincnt, cnt);
        }
        printf("Case #%d: ", ti);
        if(mincnt==(l+1)) cout<<"NOT POSSIBLE"<<endl;
        else cout<<mincnt<<endl;
    }
	return 0;
}
