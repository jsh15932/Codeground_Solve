#include<bits/stdc++.h>
using namespace std;

int t, k, l, n, m;
int d[101][101];
bool visited[101];
vector <int> vc;

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		memset(d, 0, sizeof(d));
		memset(visited, false, sizeof(visited));
		vc.clear();
		
		int cnt = 0;
		
		cin >> k >> l;
		cin >> n >> m;
		
		for(int i = 0; i < m; i++) {
			int from, to;
			
			cin >> from >> to;
			
			d[from][to] = 1;
			d[to][from] = 1;
		}
		
		int v = n;
		
		while(1) {
			cnt++;
			
			for(int i = 1; i <= n; i++) {
				if(visited[i]) {
					continue;
				}
				
				int p = 0;
				
				for(int j = 1; j <= n; j++) {
					p += d[i][j];
				}
				
				if(p < k || p > v - l - 1) {
					visited[i] = true;
					v--;
					vc.push_back(i);
					
					for(int j = 1; j <= n; j++) {
						d[i][j] = 0;
						d[j][i] = 0;
					}
					
					break;
				}
			}
			
			if(cnt == n) {
				break;
			}
		}
		
		int res = 0;
		
		for(int i = 0; i < vc.size(); i++) {
			res += vc[i];
		}
		
		cout << "Case #" << tc << '\n' << res << endl; 
	}
}
