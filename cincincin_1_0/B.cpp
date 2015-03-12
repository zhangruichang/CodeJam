#include <iostream>

using namespace std;

const double EPS = 1e-6;

int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int t, num_farm;
	double c, f, x;
	double ans, v;
	scanf("%d", &t);
	for(int no = 1; no <= t; no++){
		
		scanf("%lf %lf %lf", &c, &f, &x);
		
		ans = 0.0;
		v = 2.0;
		num_farm = 0;
		while(x/v - (c/v + x/(v+f)) > 0){
			
			ans += c/v;
			v += f;
			
		//	cout << ans << endl;
			
		}
		ans += x/v;
		printf("Case #%d: %.7f\n", no, ans);
	}
	return 0;
}
