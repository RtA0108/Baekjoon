#include <iostream>
#include <queue>
#include <stack>

using namespace std;
bool gra[1010][1010];
bool check[1010];
int N, M, V;

queue<int> ret;
queue<int> BFS;

void DFS(int a) {
	ret.push(a);
	check[a] = true;

	for (int i = 1; i <= N; i++) {
		if (gra[a][i] && !check[i]) {
			DFS(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		gra[a][b] = true;
		gra[b][a] = true;
	}

	//DFS
	DFS(V);
	for (int i = 1; i <= N; i++) {
		check[i] = false;
	}

	while (!ret.empty()) {
		cout << ret.front() << " ";
		ret.pop();
	}
	cout << "\n";
	//BFS
	BFS.push(V);
	check[V] = true;
	int k = V;
	while (true) {
		for (int i = 1; i <= N; i++) {
			if (gra[k][i] && !check[i]) {
				BFS.push(i);
				check[i] = true;
			}
		}
		
		cout << BFS.front() << " ";
		BFS.pop();
		if (BFS.empty()) {
			break;
		}
		k = BFS.front();

	}

	return 0;
}