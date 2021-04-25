#include<bits/stdc++.h>
using namespace std;

int t, n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int d[1001][1001];
bool chk[1001][1001];

int turn(int dir, int m) {
	if(m == 1) {
		return 3 - dir;
	}
	
	else {
		return ((dir + 2) % 4);
	}
}

int main() {
	cin >> t;
	
	for(int idx = 1; idx <= t; idx++) {
		cin >> n;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%1d", &d[i][j]);
				chk[i][j] = false;
			}
		}
		
		int x = 0, y = 0, dir = 2;
		
		while(0 <= x && x < n && 0 <= y && y < n) {
			if(d[x][y] != 0) {
				chk[x][y] = true;
				dir = turn(dir, d[x][y]);
			}
			
			x += dx[dir];
			y += dy[dir];
		}
		
		int ans = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(chk[i][j]) {
					ans += 1;
				}
			}
		}
		
		cout << "Case #" << idx << '\n' << ans << endl;
	}
}