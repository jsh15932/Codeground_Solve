#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n;
		
		int ans = -1;
		
		for(int j = 2; j * j <= n; j++) {
			bool chk = true;
			
			int a = n % j;
			int b = n;
			
			while(b > 0) {
				if(b % j != a) {
					chk = false;
					break;
				}
				
				b /= j;
			}
			
			if(chk) {
				ans = j;
				break;
			}
		}
		
		if(ans == -1) {
			for(int j = 1; j * j <= n; j++) {
				if(n % j != 0) {
					continue;
				}
				
				int tmp = j;
				int p = (n / tmp) - 1;
				
				if(p > tmp) {
					ans = p;
				}
			}
		}
		
		if(ans == -1) {
			ans = n + 1;
		}
		
		cout << "Case #" << i << '\n' << ans << endl;
	}
}
