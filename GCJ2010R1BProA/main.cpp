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
#include<sstream>
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
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
//int a[maxn], n;
int n, m;
string str[100], query[100];
struct Node
{
    string val;
    unordered_map<string, Node*> next;
    Node():val("")
    {
        next.clear();
    }
};
Node* root;
void BuildTree()
{
    for(int i=0;i<n;i++)
    {
        Node* p=root;
        istringstream istr(str[i]);
        string cur;
        while(getline(istr, cur, '/'))
        {
            if(cur=="") continue;
            if(p->next.find(cur)==p->next.end())
            {
                Node* tmp=new Node();
                p->next[cur]=tmp;;
                p=tmp;
            }
            else
                p=p->next[cur];
        }
    }
}

int QueryTree()
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        Node*p=root;
        istringstream istr(query[i]);
        string cur;
        while(getline(istr, cur, '/'))
        {
            if(cur=="") continue;
            if(p->next.find(cur)==p->next.end())
            {
                Node* tmp=new Node();
                p->next[cur]=tmp;;
                p=tmp;ans++;
            }
            else
                p=p->next[cur];
        }
    }
    return ans;
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
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<m;i++) cin>>query[i];
        root=new Node();
        BuildTree();
        int ans=QueryTree();
        printf("Case #%d: %d\n", ti, ans);
    }
	return 0;
}
