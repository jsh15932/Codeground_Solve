#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main() {
	cin >> t;
	
	for(int idx = 1; idx <= t; idx++) {
		cin >> n;
		
		int *p = new int[n];
		
		for(int i = 0; i < n; i++) {
			cin >> p[i];
		}
		
		cin >> k;
		
		int tmp = 0, cur = 0, res = 0;
		
		for(int i = 0; i < n; i++) {
			tmp = cur + k;
			
			if(tmp >= p[i]) {
				if(i == n - 1) {
					res++;
					
					break;
				}
				
				if(tmp < p[i + 1]) {
					res++;
					cur = p[i];
				}
			}
			
			else {
				res = -1;
			}
		}
		
		cout << "Case #" << idx << '\n' << res << endl;
	}
}