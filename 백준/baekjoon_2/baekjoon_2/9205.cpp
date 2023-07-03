#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define p pair<int, int>
struct c
{
	int cx;
	int cy;
	bool visit;
};
vector<c> con;

void bfs(int a, int b) {
	queue <p> q;
	q.push({ a, b });
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;

		q.pop();

		for (int i = 0; i < con.size(); i++) {
			if (!con[i].visit && (abs(con[i].cx - nx) + abs(con[i].cy - ny)) <= 1000) {
				q.push({ con[i].cx, con[i].cy });
				con[i].visit = true;
			}
		}
	}

}
int main() {

	int T, N, x, y, a, b;

	cin >> T;

	for (int i = 0; i < T; i++) {
		con.clear();
		cin >> N;
		cin >> x >> y;
		for (int j = 0; j <= N; j++) {
			cin >> a >> b;
			con.push_back({ a, b, 0});
		}
		bfs(x, y);
		if (con.back().visit) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}


	return 0;
}