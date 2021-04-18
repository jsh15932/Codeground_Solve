#include<bits/stdc++.h>
using namespace std;

bool chk1[1000001];
int tc;

bool chk2(char a, char b) {
	if(a == '(' && b == ')') {
		return true;
	}
	
	if(a == '[' && b == ']') {
		return true;
	}
	
	if(a == '{' && b == '}') {
		return true;
	}
	
	return false;
}

int main() {
	cin >> tc;
	
	for(int idx = 1; idx <= tc; idx++) {
		int ans = 0;
		
		vector< pair <char, int> > vc;
		string s;
		
		cin >> s;
		
		memset(chk1, false, sizeof(chk1));
		
		for(int i = 0; i < s.size(); i++) {
			vc.push_back(make_pair(s[i], i));
			
			if(vc.size() >= 2 && chk2(vc[vc.size() - 2].first, vc[vc.size() - 1].first)) {
				chk1[vc[vc.size() - 1].second] = true;
				chk1[vc[vc.size() - 2].second] = true;
				
				vc.pop_back();
				vc.pop_back();
			}
		}
		
		int tmp = 0;
		
		for(int i = 0; i < s.size(); i++) {
			if(chk1[i]) {
				tmp++;
			}
			
			else {
				tmp = 0;
			}
			
			if(tmp > ans) {
				ans = tmp;
			}
		}
		
		cout << "Case #" << idx << '\n' << ans << endl;
	}
}