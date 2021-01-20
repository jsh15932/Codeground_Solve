#include<bits/stdc++.h>
using namespace std;

int t, num;
int a, b, c, d;

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> num;
		
		a = 0, b = 0, c = 0, d = 0;
		
		while(1) {
			if(num >= 500) {
				num -= 500;
				d++;
			}
			
			else if(num >= 100 && num < 500) {
				num -= 100;
				c++;
			}
			
			else if(num >= 50 && num < 100) {
				num -= 50;
				b++;
			}
			
			else if(num >= 10 && num < 150) {
				num -= 10;
				a++;
			}
			
			else {
				break;
			}
		}
		
		cout << "Case #" << tc << '\n' << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
}
