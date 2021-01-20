#include<bits/stdc++.h>
using namespace std;

int t, a, b;
string s;

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {	
		a = 0, b = 0;
		
		cin >> s;
		
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == 'A') {
				a++;
			}
			
			else {
				b++;
			}
		}
		
		cout << "Case #" << tc << '\n';
		
		if(a == 21) {
			cout << "Alice" << endl;
		}
		
		else if(b == 21) {
			cout << "Bob" << endl;
		}
		
		else {
			cout << "Playing" << endl;
		}
	}
}
