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
//unordered_set<set> sure, unsure;
bool Dif(string str1, string str2, unordered_set<int>& sure, unordered_set<int>& unsure)//str1-str2
{
    sure.clear(), unsure.clear();
    for(int i=0;i<7;i++)
    {
        if(str1[i]!=str2[i])
        {
            if(str1[i]=='0' && str2[i]=='1') return 0;
            sure.insert(i);
        }
        else if(str1[i]=='0') unsure.insert(i);
    }
    return 1;
}
string str[101];
string led[20]={"1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011",
"1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"};
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int t;cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        unordered_set<int> ssure, sunsure;
        int n;cin>>n;
        for(int i=0;i<n;i++) cin>>str[i];
        //for(int i=0;i<n;i++) cout<<str[i]<<" ";
        bool ok=0;int i;string startdif;n%=10;
        for(i=19;i>=10;i--)
        {
            ssure.clear(), sunsure.clear();
            if(!Dif(led[i], str[0], ssure, sunsure)) continue;
            int ii, j;for(ii=i-1, j=1; j<n;)
            {
                unordered_set<int> curset, curunsure;
                if(!Dif(led[ii],str[j], curset, curunsure)) break;
                bool match=1;
                for(auto e: curset)
                {
                    if(sunsure.find(e)==sunsure.end() && ssure.find(e)==ssure.end()) {match=0;break;}
                    else if(sunsure.find(e)!=sunsure.end() && ssure.find(e)==ssure.end())
                        sunsure.erase(e), ssure.insert(e);
                }
                if(!match) break;
                unordered_set<int> ansunsure;
                for(auto e: curunsure)
                {
                    if(sunsure.find(e)!=sunsure.end() && ssure.find(e)==ssure.end()) ansunsure.insert(e);
                }
                sunsure=ansunsure;
                ii--, j++;
            }
            if(!sunsure.size()) {ok=1;break;}
        }
        string result;
        if(!ok) result="ERROR!";
        else
        {
            result=led[i-n];
            for(auto e: ssure) result[e]='0';
        }
        printf("Case #%d: ", ti);
        cout<<result<<endl;
    }
	return 0;
}
