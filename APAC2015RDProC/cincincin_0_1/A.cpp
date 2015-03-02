#include <iostream>

using namespace std;

const int MAX_N = 300;

char map[MAX_N + 1][MAX_N + 1];
int mark[MAX_N + 1][MAX_N + 1];
bool vis[MAX_N + 1][MAX_N + 1];
int n;
int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

inline bool ok(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < n) return true;
	return false;
}

inline int calculate(int i, int j){
	if(map[i][j] == '*') return -1;

	int x, y, sum;
	sum = 0;
	for(int k = 0; k < 8; ++k){
		x = i + dir[k][0];
		y = j + dir[k][1];
		if(ok(x, y) && map[x][y] == '*')
			sum++;
	}
	return sum;
}

void dfs(int i, int j){
	//if(vis[i][j] || mark[i][j] != 0) return;

	int x, y;
	for(int k = 0; k < 8; ++k){
		x = i + dir[k][0];
		y = j + dir[k][1];
		if(ok(x, y) && !vis[x][y] && mark[x][y] == 0){
			vis[x][y] = true;
			dfs(x, y);
		}
	}
}

void solve(int t){

	cin >> n;
	for(int i = 0; i < n; ++i){
		getchar();
		scanf("%s", map[i]);
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			mark[i][j] = calculate(i, j);
	}

	memset(vis, false, sizeof(vis));

	int ans = 0;
	int x, y, sum;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(mark[i][j] == 0 && !vis[i][j]){
				ans++;
				vis[i][j] = true;
				dfs(i, j);
			}else if(mark[i][j] != -1 && !vis[i][j]){
				sum = 0;
				for(int k = 0; k < 8; ++k){
					x = i + dir[k][0];
					y = j + dir[k][1];

					if(ok(x, y) && mark[x][y] == 0)
						sum++;
				}
				if(sum == 0) ans++;
			}
		}
	}

	printf("Case #%d: %d\n", t, ans);
    //cout << ans << endl;

 //    for(int i = 0; i < n; ++i){
	// 	for(int j = 0; j < n; ++j)
	// 		cout << vis[i][j] << " ";
	// 	cout << endl;
	// }
	// for(int i = 0; i < n; ++i){
	// 	for(int j = 0; j < n; ++j)
	// 		cout << mark[i][j] << " ";
	// 	cout << endl;
	// }

	// for(int i = 0; i < n; ++i)
	// 	cout << map[i] << endl;


}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int cases;
	cin >> cases;
	for(int t = 1; t <= cases; ++t){
		solve(t);
	}
	return 0;
}
