#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
const int N = 505;
const int MOD = 1000000007;
struct  Edge {
    int v , w , next;
}e[N * N * 4];
int way[4][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0};
int source , sink , cur[N * N] , level[N * N];
int w , h , k , a[N][N];
int head[N * N] , tot;
void _add (int u , int v , int w) {
    e[tot].v = v;e[tot].w = w;e[tot].next = head[u];head[u] = tot ++;
}
void add (int u , int v , int w) {
    _add (u , v , w);
    _add (v , u , 0);
}
bool bfs(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[source] = 0;
    q.push(source);
    while(! q.empty()){
        int u = q.front();q.pop();
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v;
            if(e[i].w && level[v] == -1){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}
int dfs(int u,int flow){
    if(u == sink) return flow;
    int tmp = flow;
    for(int &i = cur[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(e[i].w && level[v] == level[u] + 1){
            int add = dfs(v,min(e[i].w,tmp));
            tmp -= add;
            e[i].w -= add;
            e[i ^ 1].w += add;
            if(! tmp) break;
        }
    }
    return flow - tmp;
}
int dinic(){
    int maxFlow = 0;
    while(bfs()){
        for(int i = 0;i < N * N ;i ++)
            cur[i] = head[i];
        maxFlow += dfs(source,int(1e9));
    }
    return maxFlow;
}

int main(){
    // freopen("input.txt" , "r" , stdin);
    // freopen("B.out" , "w" , stdout);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = 0;
        memset (head , -1  , sizeof (head));
        scanf ("%d %d %d" , &w , &h , &k);
        memset (a , 0 , sizeof (a));
        memset (cur , 0 , sizeof (cur));
        for (int i = 0 ; i < k ; i ++) {
            int lx , rx , ly , ry;
            scanf ("%d %d %d %d" , &lx , &ly , &rx , &ry);
            for (int x = lx ; x <= rx ; x ++) {
                for (int y = ly ; y <= ry ; y ++)
                    a[x][y] = 1;
            }
        }
        source = N * N - 1;
        sink = N * N - 2;
        int remain = w * h + 5;
        for (int i = 0 ; i < w ; i ++) {
            add (source , i * h , 1);
            add (i * h + h - 1 , sink , 1);
        }
        for (int i = 0 ; i < w ; i ++) {
            for (int j = 0 ; j < h ; j ++) {
                if (a[i][j]) continue;
                add (i * h + j , remain + i * h + j , 1);
                for (int dir = 0 ; dir < 4 ; dir ++) {
                    int x = i + way[dir][0] , y = j + way[dir][1];
                    if (x >= 0 && x < w && y >= 0 && y < h && !a[i][j] && !a[x][y]) {
                        add (remain + i * h + j , x * h + y , 1);
                    }
                }
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , dinic ());
    }
    return 0;
}
