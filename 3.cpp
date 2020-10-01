#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> k;
		
		vector <int> vc(n);
		
		for(int j = 0; j < n; j++) {
			cin >> vc[j];
		}
		
		sort(vc.begin(), vc.end());
		reverse(vc.begin(), vc.end());
		
		int ans = 0;
		
		for(int j = 0; j < k; j++) {
			ans += vc[j];
		}
		
		cout << "Case #" << i << '\n' << ans << endl;
	}
}
