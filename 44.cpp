#include<bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
vector <int> vc[1001];
int d[1001];
bool visited[1001];
bool chk = false;

void dfs(int x, int y) {
	for(int i = 0; i < vc[x].size(); i++) {
		if(!visited[vc[x][i]]) {
			visited[vc[x][i]] = true;
			
			if(y == 1) {
				dfs(vc[x][i], 2);
				d[vc[x][i]] = 2;
			}
			
			else {
				dfs(vc[x][i], 1);
				d[vc[x][i]] = 1;
			}
		}
		
		else {
			if(d[vc[x][i]] == y) {
				chk = true;
			}
		}
	}
}

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> m;
		
		for(int j = 1; j <= n; j++) {
			visited[j] = false;
			vc[j] = 0;
			d[j] = -1;
		}
		
		for(int j = 0; j < m; j++) {
			cin >> a >> b;
			
			vc[a].push_back(b);
			vc[b].push_back(a);
		}
		
		for(int j = 1; j <= n; j++) {
			if(!visited[j]) {
				visited[j] = true;
				d[j] = 1;
				dfs(j, 1);
			}
		}
		
		cout << "Case #" << i << '\n';
		
		if(chk) {
			cout << 0 << endl;
		}
		
		else {
			cout << 1 << endl;
		}
	}
}
