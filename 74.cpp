#include<bits/stdc++.h>
using namespace std;
#define Max_N 200001

int n, t;
long long int d[Max_N];
long long int k;
bool chk[Max_N];

int main() {
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++) {
		scanf("%d %lld", &n, &k);
		
		for(int j = 0; j < n; j++) {
			scanf("%lld", &d[j]);
		}
		
		sort(d, d + n);
		
		long long int ans = 0;
		long long int cnt = 0;
		
		for(int j = 0; j < n; j++) {
			while(cnt < n && d[cnt] - d[j] <= k) {
				cnt++;
			}
			
			ans = max(ans, cnt - j);
		}
		
		printf("Case #%d\n%lld\n", i, ans);
	}
}
