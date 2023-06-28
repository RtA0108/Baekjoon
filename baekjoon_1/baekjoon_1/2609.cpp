#include <iostream>

using namespace std;

int eucl(int a, int b) {
	if (b == 0) {
		return a;
	}
	int t = a % b;
	a = b;
	b = t;
	return eucl(a, b);

}

int main() {

	int N, M, a;
	cin >> N >> M;
	if (N < M) {
		a = eucl(M, N);
	}
	else {
		a = eucl(N, M);
	}
	
	int max = (N * M) / a;

	cout << a << "\n" << max;

	return 0;
}