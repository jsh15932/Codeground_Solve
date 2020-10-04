#include<bits/stdc++.h>
using namespace std;

int t, n, m, p;
bool chk[10001];

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> m;
		
		for(int j = 1; j <= m; j++) {
			chk[j] = false;
		}
		
		for(int j = 0; j < n; j++) {
			cin >> p;
			
			chk[0] = true;
			
			for(int k = 0; k <= m; k++) {
				if(chk[k] && k + p <= m) {
					chk[k + p] = true;
				}
			}
		}
		
		int ans = 0;
		
		for(int j = m; j >= 0; j--) {
			if(chk[j]) {
				ans = j;
				break;
			}
		}
		
		cout << "Case #" << i << '\n' << ans << endl;
	}
}
