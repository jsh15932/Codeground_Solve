#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n;
		
		vector <int> vc(n);
		
		for(int i = 0; i < n; i++) {
			cin >> vc[i];
		}
		
		sort(vc.begin(), vc.end());
		
		int max_N = 0;
		
		for(int i = 0; i < n; i++) {
			if(vc[i] + n - i > max_N) {
				max_N = vc[i] + n - i;
			}
		}
		
		int ans = 0;
		
		for(int i = 0; i < n; i++) {
			if(vc[i] + n >= max_N) {
				ans += 1;
			}
		}
		
		cout << "Case #" << i << '\n';
		cout << ans << endl;
	}
}
