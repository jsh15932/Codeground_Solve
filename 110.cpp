#include<bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> a >> b >> c;
		
		int ans = 0;
		
		while(1) {
			if(a < 2 || b < 1 || c < 3) {
				break;
			}
			
			a -= 2;
			b -= 1;
			c -= 3;
			ans++;
		}
		
		cout << "Case #" << tc << '\n' << ans << endl;
	}
}
