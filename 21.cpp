#include<bits/stdc++.h>
using namespace std;

int t, n, r, L, d[100010], ans;

int solve(int mid) {
	int p = r;
	int q = 0;
	
	for(int i = 0; i < n; i++) {
		if(d[i] <= p) {
			if(p - d[i] > mid) {
				q = max(0, mid + d[i] + r);
				
				if(mid + d[i] + r < p) {
					p -= r * 2;
				}
			}
				
			else {
				q = p + r;
			}
		}
			
		else {
			if(d[i] - q > mid + r) {
				return 0;
			}
			
			else {
				q += 2 * r;
			}
		}
		
		if(q >= L) {
			return 1;
		}
		
		p = q + r;
	}
	
	if(q < L) {
		return 0;
	}
	
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int low, high, mid;
	
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> r >> L;
		
		for(int i = 0; i < n; i++) {
			cin >> d[i];
		}
		
		if(r * n * 2 < L) {
			ans = -1;
		}
		
		else {
			low = 0;
			high = 2 * 1000000000;
			
			while(low < high) {
				mid = (low + high) / 2;
				
				if(solve(mid)) {
					high = mid;
				}
				
				else {
					low = mid + 1;
				}
			}
			
			ans = high;
		}
		
		cout << "Case #" << tc << '\n' << ans << endl;
	}
}
