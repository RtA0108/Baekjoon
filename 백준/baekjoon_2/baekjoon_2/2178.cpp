#include <iostream>
#include <queue>

using namespace std;
struct p
{
	int x;
	int y;
	int dis;
};
char maze[101][101];
bool visit[101][101];
int N, M;
queue<p> save;
int moving[4][2] = { {1, 0}, {0, 1}, { -1,0}, {0,-1} };
int escape() {
	int ret;
	int newX, newY, newDis;
	save.push({ 1, 1, 1 });
	visit[1][1] = true;
	
	while (true) {
		p a = save.front();
		save.pop();

		if (a.x == N && a.y == M) {
			ret = a.dis;
			break;
		}

		for (int i = 0; i < 4; i++) {
			newX = a.x + moving[i][0];
			newY = a.y + moving[i][1];
			newDis = a.dis + 1;
			if(newX < 1 || newY < 1 || newX > N || newY > M || maze[newX][newY] == '0' || visit[newX][newY]){
				continue;
				
			}

			save.push({ newX, newY, newDis });
			visit[newX][newY] = true;
		}

	}
	
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}
	

	cout << escape();
	return 0;
}