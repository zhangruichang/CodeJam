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
const int maxn = 1e2 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
unordered_map<string,int> StrIndex;
int color[maxn];//0 not visit, 1 color1, 2 color2
vector<pair<string, string>> v;
bool A[maxn][maxn];
int n;
bool dfs(int cur, int c)
{
    if(color[cur]) return 1;
    color[cur]=3-c;
    //auto cur=StrIndex[s];
    //if(cur.second) return ;
    for(int i=0;i<n;i++)
    {
        if(A[cur][i])
        {
            if(color[cur]==color[i] || (!color[i] &&!dfs(i, color[cur]))) return 0;
        }
    }
    return 1;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("A-small-practice-2.in" , "r" , stdin);
    freopen ("A-small-practice-2.out" , "w" , stdout);
#endif

    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        v.clear();StrIndex.clear();int m;
        cin>>m;n=0;
        for(int i=0;i<m;i++)
        {
            string str1, str2;
            cin>>str1>>str2;
            v.push_back({str1,str2});
            if(StrIndex.find(str1)==StrIndex.end()) StrIndex[str1]=n++;
            if(StrIndex.find(str2)==StrIndex.end()) StrIndex[str2]=n++;
        }
        memset(A, 0, sizeof A);
        for(int i=0;i<m;i++)
            A[StrIndex[v[i].first]] [StrIndex[v[i].second]]=1,A[StrIndex[v[i].second]] [StrIndex[v[i].first]]=1;
        memset(color,0,sizeof color);
        //color[0]=1;
        //0 node color 1
        printf("Case #%d: ", ti);
        puts(dfs(0,2)?"YES":"NO");
    }
	return 0;
}
