#include<bits/stdc++.h>
using namespace std;

int tc, n;
int d[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> tc;
	
	for(int idx = 1; idx <= tc; idx++) {
		cin >> n;
		
		for(int i = 1; i <= n; i++) {
			cin >> d[i];
		}
		
		int cur = 0, res = 0;
		
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
		
		cout << "Case #" << idx << '\n' << res << endl;
	}
}