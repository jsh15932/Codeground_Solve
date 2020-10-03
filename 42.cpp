#include<bits/stdc++.h>
using namespace std;

int t, n, s;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		int Min_N = 100000;
		int d[100001];
		int num;
		
		cin >> n >> s;
		
		for(int j = 1; j <= n; j++) {
			cin >> num;
			d[j] = num;
		}
		
		int sum = 0;
		int len_s = 0;
		
		for(int j = 1; j <= n; j++) {
			sum += d[j];
			len_s++;
			
			while(sum >= s) {
				if(Min_N > len_s) {
					Min_N = len_s;
				}
				
				sum -= d[j - len_s + 1];
				len_s--;
			}
		}
		
		cout << "#testcase" << t << '\n';
		
		if(Min_N == 100000) {
			cout << 0 << endl;
		}
		
		else {
			cout << Min_N << endl;
		}
	}
}
