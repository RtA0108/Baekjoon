#include <iostream>

using namespace std;


int N, M, cnt;
int arr[500500];
int tmp[500500];
void merge(int p, int q, int r);
void merge_sort(int p, int r) {
	
	
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
	
	

}


void merge(int p, int q, int r) {


	int i = p, j = q + 1, t = 1;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}

	}

	while (i <= q) {
		tmp[t++] = arr[i++];
	}
	while (j <= r) {
		tmp[t++] = arr[j++];
	}
	i = p; t = 1;
	while (i <= r) {
		arr[i++] = tmp[t++];
		cnt++;
		if (M==cnt) {
			cout << arr[i-1];
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		arr[i] = k;
	}

	merge_sort(1, N);
	if (M > cnt) {
		cout << -1;
	}
	return 0;
}