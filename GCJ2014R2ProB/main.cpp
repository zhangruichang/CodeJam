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
int a[maxn], n;
inline int RevCnt1(int a[], int low, int high)
{
    int cnt=0;
    for(int i=low;i<=high;i++) for(int j=i+1;j<=high;j++)
        if(a[i]>a[j]) cnt++;
    return cnt;
}
inline int RevCnt2(int a[], int low, int high)
{
    int cnt=0;
    for(int i=low;i<=high;i++) for(int j=i+1;j<=high;j++)
        if(a[i]<a[j]) cnt++;
    return cnt;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("B-large-practice.in" , "r" , stdin);
    freopen ("B-large-practice.out" , "w" , stdout);
#endif

    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;for(int i=0;i<n;i++) cin>>a[i];int cnt=0;
        for(int low=0, high=n-1; low<high;)
        {
            int mini=min_element(a+low, a+high+1)-a;
            int leftdis=mini-low, rightdis=high-mini;
            if(leftdis<rightdis)
            {
                for(int i=mini;i>=(low+1);i--) swap(a[i-1], a[i]), cnt++;
                low++;
            }
            else
            {
                for(int i=mini;i<=(high-1);i++) swap(a[i], a[i+1]), cnt++;
                high--;
            }
        }
        /*
        int maxe=0, maxi=-1;for(int i=0;i<n;i++)
        {
            if(a[i]>maxe) maxi=i, maxe=a[i];
        }
        int mincnt=-1;
        int b[n];
        for(int maxpos=0;maxpos<=n-1;maxpos++)
        {
            for(int i=0;i<n;i++) b[i]=a[i];
            int cnt=0;
            if(maxpos<maxi)
            {
                for(int i=maxi;i>=maxpos+1;i--)
                    swap(b[i-1], b[i]);
                cnt+=(maxi-maxpos);
            }
            else
            {
                for(int i=maxi;i<=maxpos-1;i++)
                    swap(b[i], b[i+1]);
                cnt+=(maxpos-maxi);
            }
            //for(int i=0;i<n;i++) cout<<b[i]<<" ";cout<<endl;
            //cout<<cnt<<" "<<RevCnt1(b, 0, maxpos-1)<<" "<<RevCnt2(b, maxpos+1, n-1)<<endl;
            cnt+=(RevCnt1(b, 0, maxpos-1)+RevCnt2(b, maxpos+1, n-1));
            //cout<<cnt<<endl;
            if(mincnt==-1) mincnt=cnt;
            else mincnt=min(mincnt, cnt);
        }
        */

        /*
        int cnt=0;
        for(int i=0;i<maxi-1;i++) for(int j=0;j<maxi-i-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j], a[j+1]), cnt++;
        }
        for(int i=maxi+1;i<n-1;i++) for(int j=maxi+1;j<n-i+maxi;j++)
        {
            if(a[j]<a[j+1]) swap(a[j], a[j+1]), cnt++;
        }*/
        printf("Case #%d: %d\n", ti, cnt);
    }
	return 0;
}
