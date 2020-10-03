#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n;
		
		vector <int> v(n + 2);
		vector <int> vc(n + 2);
		
		for(int j = 1; j <= n; j++) {
			cin >> v[j];
		}
		
		int k = 0;
		
		for(int j = 1; j <= n; j++) {
			k = min(k, v[j] - j);
			vc[j] = j + k;
		}
		
		k = n + 1;
		
		for(int j = n; j >= 1; j--) {
			k = min(k, v[j] + j);
			vc[j] = min(vc[j], k - j);
		}
		
		int ans = 0;
		
		for(int j = 1; j <= n; j++) {
			ans = max(ans, vc[j]);
		}
		
		cout << "Case #" << t << '\n' << ans << endl; 
	}
}
