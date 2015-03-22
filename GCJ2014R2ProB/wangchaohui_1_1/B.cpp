#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime> 
using namespace std;
#define FRsmall(x,y) do{freopen(#x"-small-attempt"#y".in","r",stdin);freopen(#x"-small-attempt"#y".out","w",stdout);}while(0)
#define FRlarge(x) do{freopen(#x"-large.in","r",stdin);freopen(#x"-large.out","w",stdout);}while(0)
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin( 
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax( 
#define SIZE(x) ((int)(x).size()) 
#define for0(i,n) for(int i=0;i<(n);i++) 
#define for1(i,n) for(int i=1;i<=(n);i++) 
#define for0r(i,n) for(int i=(n)-1;i>=0;i--) 
#define for1r(i,n) for(int i=(n);i>=1;i--) 
typedef long long ll;
typedef vector<int> vi;

int d[1000];

void solve()
{
    int n;
    scanf("%d", &n);
    for0(i, n)scanf("%d", &d[i]);
    int ans = 0;
    while (n)
    {
        int mmin = numeric_limits<int>::max();
        int mi = -1;
        for0(i, n)
        {
            if (d[i] < mmin)
            {
                mmin = d[i];
                mi = i;
            }
        }
        ans += min(mi, n - 1 - mi);
        for (int i = mi; i < n - 1; i++)
        {
            d[i] = d[i + 1];
        }
        n--;
    }
    printf("%d\n", ans);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //FRsmall(B, 0);
    FRlarge(B);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d: ", TC);
        solve();
    }
    return 0;
}
