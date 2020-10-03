#include<bits/stdc++.h>
using namespace std;

int t, n, m, k, num, cost;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> m >> k;
		
		int d[n] = {0, };
		int dp[m] = {0, };
		
		for(int j = 1; j <= n; j++) {
			cin >> num;
			
			d[num]++;
		}
		
		for(int j = 1; j <= m; j++) {
			cin >> cost;
			
			dp[j] = cost;
		}
		
		int ans = 0;
		bool chk = true;
		
		for(int j = 1; j <= n; j++) {
			if(chk) {
				if(ans > k) {
					chk = false;
				}
				
				else {
					ans += d[j] * dp[j];
				}
			}
		}
		
		if(chk) {
			cout << "Case #" << i << '\n' << "Y" << endl;
		}
		
		else {
			cout << "Case #" << i << '\n' << "N" << endl;
		}
	}
}
