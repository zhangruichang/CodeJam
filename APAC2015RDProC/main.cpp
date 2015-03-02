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
int t, n, k;

int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n>>k;
        vector<int> v;int x;
        for(int i=0;i<n;i++) cin>>x, v.push_back(x);
        while(1)
        {
            bool ok=0;
            for(int i=0;(i+2)<v.size();i++)
            {
                if(v[i]+k==v[i+1] &&v[i+1]+k==v[i+2])
                {
                    ok=1;
                    v.erase(v.begin()+i, v.begin()+i+3);
                    break;
                }
            }
            if(!ok) break;
        }
        cout<<"Case #"<<ti<<": "<<v.size()<<endl;
    }
	return 0;
}
