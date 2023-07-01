#include <iostream>

using namespace std;

int arr[100010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int k;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		arr[i] = k;
		arr[i] += arr[i - 1];
	}
	int a, b;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		sum = 0;
		sum = arr[b] - arr[a-1];
		
		cout << sum << "\n";
	}
	return 0;
}