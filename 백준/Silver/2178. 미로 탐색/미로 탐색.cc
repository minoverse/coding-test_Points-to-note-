#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	vector<vector<int>> dist(n, vector<int>(m, 0));
	dist[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({0, 0}); 
	int rd[4] = {-1, 1, 0 , 0};
	int cd[4] = {0, 0 , 1, -1};
	while(!q.empty()) {
		// no need to int r, c;
		auto[r, c] = q.front(); q.pop();
		if (r == n - 1 && c == m - 1) break;
		for (int i = 0; i < 4; i ++) {
			int nr = r + rd[i];
			int nc = c + cd[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (grid[nr][nc] == '0') continue;
			if (dist[nr][nc] != 0) continue;
			dist[nr][nc] =  dist[r][c] + 1;
			q.push({nr, nc});
		}
	}
	cout << dist[n - 1][m - 1] << "\n";
	return 0;
}