#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> s;
		
		int h = 0;
		int e = 0;
		int l = 0;
		int o = 0;
		
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == 'h') {
				h++;
			}
			
			if(s[j] == 'e') {
				e++;
			}
			
			if(s[j] == 'l') {
				l++;
			}
			
			if(s[j] == 'o') {
				o++;
			}
		}
		
		l /= 2;
		
		if(h > e) {
			h = e;
		}
		
		if(h > l) {
			h = l;
		}
		
		if(h > o) {
			h = o;
		}
		
		cout << "Case #" << i << '\n' << h << endl;
	}
}
