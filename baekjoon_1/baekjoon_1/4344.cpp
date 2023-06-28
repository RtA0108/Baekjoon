#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int C, k;
	vector<int> good;
	int sum = 0, count = 0;
	double av = 0;
	for (int i = 0; i < N; i++) {
		cin >> C;
		for (int j = 0; j < C; j++) {
			cin >> k;
			sum += k;
			good.push_back(k);
		}

		av = sum / C;

		for (int j = 0; j < C; j++) {
			if (av < good[j]) {
				count++;
			}
		}

		av = ((double)count / C) * 100;
		cout << fixed;
		cout.precision(3);
		cout << av << "%\n";
		sum = 0;
		count = 0;
		good.clear();

	}

	return 0;
}