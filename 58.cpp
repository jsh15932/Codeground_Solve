#include<bits/stdc++.h>
using namespace std;

int t, n;
int d[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> n;
		
		for(int i = 1; i <= n; i++) {
			cin >> d[i];
		}
		
		int cur, cnt = 0, res = 0;
		
		for(int i = 1; i < n; i++) {
			if(d[i] < d[i + 1]) {
				cur = i + 1;
				
				while(d[cur] < d[cur + 1] && cur < n) {
					cur++;
				}
				
				res += 2;
				i = cur;
			}
		}
		
		cout << "Case #" << tc << '\n' << res << endl;
	}
}
