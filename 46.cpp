#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int t, n, m, k, p;
int d[101][101];

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> m >> k;
		
		int from, to, cost;
		
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				d[j][k] = INF;
			}
			
			d[j][j] = 0;
		}
		
		for(int j = 1; j <= m; j++) {
			cin >> from >> to >> cost;
			
			d[from][to] = cost;
			d[to][from] = cost;
		}
		
		for(int l = 1; l <= n; l++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					if(d[j][k] > d[j][l] + d[l][k]) {
						d[j][k] = d[j][l] + d[l][k];
					}
				}
			}
		}
		
		cin >> p;
		
		int ans = 0;
		
		for(int j = 0; j < p; j++) {
			cin >> from >> to;
			
			if(d[from][to] > k) {
				ans++;
			}
		}
		
		cout << "Case #" << i << '\n' << ans << endl;
	}
}
