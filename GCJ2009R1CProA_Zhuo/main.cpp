#include <stack>
#include <cstdio>
#include <list>
#include <cassert>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define X first
#define Y second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 50001;
const int MOD = 9901;
const int dir[][2] = { {-1, 0}, {0, -1}, { 1, 0 }, { 0, 1 } };
int cases = 0;
typedef pair<int, int> pii;

map<char, int> mp;

int main()
{
    ROP;
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cout << "Case #" << ++cases << ": ";
        mp.clear();
        vector<int> ans;
        string str;
        cin >> str;
        int pos = 0;
        for (int i = 0; i < SZ(str); i++)
        {
            if (i == 0) mp[str[i]] = 1, ans.PB(mp[str[i]]);
            else if (mp.count(str[i])) ans.PB(mp[str[i]]);
            else
            {
                mp[str[i]] = pos++;
                ans.PB(mp[str[i]]);
            }
            if (pos == 1) pos++;
        }
        if (SZ(mp) == 1) pos = 2;
        LL base = pos, curWeigh = 1;
        reverse(ans.begin(), ans.end());
        LL res = 0;
        for (int i = 0; i < SZ(ans); i++)
        {
            res += curWeigh * ans[i];
            curWeigh *= base;
        }
        cout << res << endl;
    }
    return 0;
}
