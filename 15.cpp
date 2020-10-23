#include<bits/stdc++.h>
using namespace std;
#define Max_N 1001

int t, n, m;
bool chk[Max_N];
vector < pair < int, int > > vc[Max_N];

void dijkstra(int start) {
	priority_queue < pair < int, int > > que;
	vector <int> d(Max_N, 1e9);
	que.push(make_pair(0, start));
	d[start] = 0;
	
	while(!que.empty()) {
		int cur = que.top().second;
		int cost = que.top().first;
		que.pop();
		
		if(d[cur] < cost) {
			continue;
		}
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int end = vc[cur][i].first;
			int end_cost = vc[cur][i].second + cost;
			
			if(d[end] > end_cost) {
				d[end] = end_cost;
				que.push(make_pair(-end_cost, end));
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < vc[i].size(); j++) {
			int next = vc[i][j].first;
			int cost = vc[i][j].second;
			
			if(d[i] == d[next] + cost && next != start) {
				chk[next] = true;
			}
		}
	}
}

int main() {
	cin >> t;
	
	for(int i = 1; i <= t; i++) {
		cin >> n >> m;
		
		memset(chk, 0, sizeof(chk));
		
		for(int j = 1; j <= n; j++) {
			vc[j].clear();
		}
		
		for(int j = 0; j < m; j++) {
			int u, v, w;
			
			cin >> u >> v >> w;
			
			vc[u].push_back(make_pair(v, w));
			vc[v].push_back(make_pair(u, w));
		}
		
		for(int j = 1; j <= n; j++) {
			dijkstra(j);
		}
		
		int res = 0;
		
		for(int j = 1; j <= n; j++) {
			res += chk[j];
		}
		
		cout << "Case #" << i << '\n' << n - res << ' ';
		
		for(int j = 1; j <= n; j++) {
			if(!chk[j]) {
				cout << j << ' ';
			}
		}
		
		cout << endl;
	}
}
