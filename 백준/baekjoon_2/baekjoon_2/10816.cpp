#include <iostream>
#include <map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> card;
	int N;
	cin >> N;
	int k;
	
	for (int i = 0; i < N; i++) {
		cin >> k;
		if (card.find(k) != card.end()) {
			card[k] += 1;
		}
		else
		{
			card.insert({ k, 1 });
		}
	}
	


	int M;
	int a;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (card.find(k) != card.end()) {
			a = card[k];
			cout << a << " ";
		}
		else
			cout << 0 << " ";
	}

	return 0;
}