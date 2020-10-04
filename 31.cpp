#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n;
		
		vector <int> p(n + 1);
		vector <int> q(n + 1);
		vector <int> d(n + 1);
		
		for(int j = 1; j <= n; j++) {
			cin >> p[j];
		}
		
		for(int j = 1; j <= n; j++) {
			cin >> q[j];
		}
		
		d[1] = max(p[1], q[1]);
		
		for(int j = 2; j <= n; j++) {
			d[j] = max(d[j - 1] + p[j], d[j - 2] + q[j]);
		}
		
		cout << "Case #" << i << '\n' << d[n] << endl;
	}
}
