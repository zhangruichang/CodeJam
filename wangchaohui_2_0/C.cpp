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

namespace Dinic{

    static const int maxn = 100010;
    static const int maxw = 2000000000;

    struct Graph{
        typedef int W;
        struct edge{
            int y;
            W c;
            int op;

            edge(int y, W c, int op) :y(y), c(c), op(op){}
        };

        vector<edge> *e;

        const int n;

        Graph(int n) :n(n)
        {
            e = new vector<edge>[n];
        }

        ~Graph() { delete[] e; }

        void add_edge(int a, int b, W c)
        {
            if (a == b)return;
            edge ea(b, c, e[b].size());
            edge eb(a, 0, e[a].size());
            e[a].push_back(ea);
            e[b].push_back(eb);
        }
    };

    int level[maxn];
    int vs, vt;

    void make_level(const Graph &g)
    {
        queue<int> p;
        p.push(vs);
        for (int i = 0; i < g.n; i++)level[i] = -1;
        level[vs] = 1;
        while (!p.empty())
        {
            int tp = p.front(); p.pop();
            if (tp == vt)return;
            for (size_t i = 0; i<g.e[tp].size(); i++)
            {
                const Graph::edge &d = g.e[tp][i];
                if (level[d.y] == -1 && d.c>0)
                {
                    p.push(d.y);
                    level[d.y] = level[tp] + 1;
                }
            }
        }
    }

    ll maxflow;

    void dfs_maxflow(const Graph &g)
    {
        static int first[maxn];
        static Graph::edge *prt[maxn];
        vector<int> p;
        p.push_back(vs);
        memset(first, -1, sizeof(first));

        while (!p.empty())
        {
            int tp = p.back();
            if (tp == vt)
            {
                Graph::W mint = maxw;
                for (int i = (int)p.size()-1; i > 0; i--)
                {
                    mint = min(mint, prt[i]->c);
                }
                maxflow += mint;
                int t = 0;
                for (int i = (int)p.size()-1; i > 0; i--)
                {
                    Graph::edge *pre = prt[i];
                    pre->c -= mint;
                    g.e[pre->y][pre->op].c += mint;
                    if (pre->c == 0)t = i;
                }
                p.resize(t);
            }
            else
            {
                int &i = first[tp];
                for (i++; i<(int)(g.e[tp].size()); i++)
                {
                    Graph::edge &d = g.e[tp][i];
                    if (level[d.y] == level[tp] + 1 && d.c>0)
                    {
                        prt[p.size()] = &d;
                        p.push_back(d.y);
                        break;
                    }
                }
                if (i >= g.e[tp].size())p.pop_back();
            }
        }
    }

    void Dinic(const Graph &g)
    {
        maxflow = 0;
        while (1)
        {
            make_level(g);
            if (level[vt] == -1)break;
            dfs_maxflow(g);
        }
    }

}

int W, H, B;
int X0[1000], Y0[1000], X1[1000], Y1[1000];
int d[500][100];

void solve()
{
    scanf("%d %d %d", &W, &H, &B);
    memset(d, 0, sizeof(d));
    for0(i, B)
    {
        scanf("%d %d %d %d", &X0[i], &Y0[i], &X1[i], &Y1[i]);
        for (int a = X0[i]; a <= X1[i]; a++)
            for (int b = Y0[i]; b <= Y1[i]; b++)
                d[b][a] = 1;
    }
    Dinic::Graph g(W*H * 2 + 2);
    Dinic::vs = W*H * 2;
    Dinic::vt = W*H * 2 + 1;
    for0(i, H)for0(j, W)
    {
        if (!d[i][j])
        {
            g.add_edge((i*W + j) * 2, (i*W + j) * 2 + 1, 1);
            if (i == 0)g.add_edge(Dinic::vs, (i*W + j) * 2, 1);
            else if (!d[i - 1][j])
            {
                g.add_edge(((i - 1)*W + j) * 2 + 1, (i * W + j) * 2, 1);
                g.add_edge((i*W + j) * 2 + 1, ((i - 1) * W + j) * 2, 1);
            }
            if (i == H - 1)g.add_edge((i*W + j) * 2 + 1, Dinic::vt, 1);
            if (j > 0 && !d[i][j - 1])
            {
                g.add_edge((i*W + j) * 2 + 1, (i*W + j - 1) * 2, 1);
                g.add_edge((i*W + j - 1) * 2 + 1, (i*W + j) * 2, 1);
            }
        }
    }
    Dinic::Dinic(g);
    printf("%I64d\n", Dinic::maxflow);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    FRsmall(C, 1);
    //FRlarge(C);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d: ", TC);
        solve();
    }
    return 0;
}
