#include<bits/stdc++.h>
using namespace std;

int t, n;
int d[1000001];

void Solve(int x) {
	if(x % 2 == 0) {
		d[x] = d[x / 2] + 1;
	}
	
	else {
		d[x] = d[(x + 1) / 2] + 2;
	}
}

int main() {
	d[0] = 0, d[1] = 0;
	
	for(int i = 2; i < 1000001; i++) {
		Solve(i);
	}
	
	for(int i = 2; i < 1000001; i++) {
		d[i] += d[i - 1];
	}
	
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		int start, end;
		
		cin >> start >> end;
		
		int ans = d[end] - d[start - 1];
		
		cout << "Case #" << tc << '\n' << ans << endl;
	}
}
