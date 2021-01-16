#include<bits/stdc++.h>
using namespace std;

int t, n, m;
int d[501][501];
int v[501][501];
int dp[501];

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = 987654321;
				v[i][j] = 0;
			}
			
			dp[i] = 0;
		}
		
		int x, y, l;
		
		while(m--) {
			cin >> x >> y >> l;
			
			d[x][y] = l;
			d[y][x] = l;
		}
		
		for(int i = 1; i <= n; i++) {
			d[i][i] = 0;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) {
					continue;
				}
				
				for(int k = j + 1; k <= n; k++) {
					if(i == k) {
						continue;
					}
					
					if(d[j][k] >= d[j][i] + d[i][k]) {
						dp[v[j][k]]--;
						
						if(d[j][k] > d[j][i] + d[i][k]) {
							d[j][k] = d[j][i] + d[i][k];
							d[k][j] = d[k][i] + d[i][j];
							v[j][k] = i;
							dp[i]++;
						}
						
						else {
							v[j][k] = 0;
						}
					}
				}
			}
		}
		
		int cnt = 0;
		
		for(int i = 1; i <= n; i++) {
			if(dp[i] > 0) {
				cnt++;
			}
		}
		
		cout << "Case #" << tc << '\n' << cnt << ' ';
		
		for(int i = 1; i <= n; i++) {
			if(dp[i] > 0) {
				cout << i << ' ';
			}
		}
		
		cout << endl;
	}
}
