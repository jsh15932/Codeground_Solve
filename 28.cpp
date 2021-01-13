#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define Max_N 100001

int t, n, m, k;
int dp[Max_N];
vector < pair < int, int > > vc[Max_N];

pair < int, int > dijkstra() {
	priority_queue < pair < int, int > > pq;
	vector <int> d(Max_N, INF);
	pq.push(make_pair(0, 0));
	d[0] = 0;
	
	while(!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if(d[cur] < cost) {
			continue;
		}
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i].first;
			int next_cost = vc[cur][i].second + cost;
			
			if(d[next] > next_cost) {
				d[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
				
				if(cur != 0) {
					dp[next] = dp[cur];
				}
			}
			
			else if(d[next] == next_cost) {
				dp[next] = min(dp[next], dp[cur]);
			}
		}
	}
	
	int p = 0, q = 0;
	
	for(int i = 1; i <= n; i++) {
		p += d[i];
		q += dp[i];
	}
	
	pair < int, int > res;
	
	res.first = p;
	res.second = q;
	
	return res;	
}

int main() {
	cin >> t;
	
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++) {
			dp[i] = INF;
		}
		
		for(int i = 0; i < n; i++) {
			vc[i].clear();
		}
		
		for(int i = 0; i < m; i++) {
			int u, v, w;
			
			cin >> u >> v >> w;
			
			vc[u].push_back(make_pair(v, w));
			vc[v].push_back(make_pair(u, w));
		}
		
		for(int i = 0; i < k; i++) {
			int start;
			
			cin >> start;
			
			vc[0].push_back(make_pair(start, 0));
			dp[start] = start;
		}
		
		pair < int, int > res = dijkstra();
		
		cout << "Case #" << tc << '\n' << res.first << '\n' << res.second << endl;
	}
}
