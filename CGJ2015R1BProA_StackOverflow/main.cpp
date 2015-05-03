
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
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long mem[1000001];

int min(int a, int b){
    return ( a < b ) ? a : b;
}

int reverse(int i){
    int r = 0, t;
    while(i > 0){
        r = 10 * r + i % 10;
        i /= 10;
    }
    return r;
}

int counts(int n){
    if(mem[n] == 0){
        int d, r, s = 0;
        d = n % 10;
        if(d > 0){
            r = reverse(n);
            if(r < n)
                mem[n] = 1 + min(counts(n - 1), counts(r));
            else
                mem[n] = 1 + counts(n - 1);
        } else {
            mem[n] = 1 + counts(n - 1);
        }
    }
    return mem[n];
}

int main(int, char**){
#ifndef ONLINE_JUDGE
    freopen ("E:/CodeJam/GCJ2015R1BProA_DP/A-small-practice.in" , "r" , stdin);
    freopen ("E:/CodeJam/GCJ2015R1BProA_DP/A-small-practice_StackOverflow.out" , "w" , stdout);
#endif
    int t, x, n;
    for(x = 0; x < 21; ++x)
        mem[x] = x;
    for(x = 21; x < 1000001; ++x)
        mem[x] = 0;
    cin >> t;
    for(x = 1; x <= t; x ++){
        cin >> n;
        cout << "Case #" << x << ": " << counts(n) << endl;
    }

    return 0;
}
