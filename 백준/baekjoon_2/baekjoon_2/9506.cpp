#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N;
	
	vector<int> count;
	int sum = 0;
	while(true)
	{
		cin >> N;
		if (N == -1)
			return 0;
		for (int i = 1; i < N; i++) {
			if (N % i == 0) {
				count.push_back(i);
			}
		}
		for (int i = 0; i < count.size(); i++) {
			sum += count[i];
		}
		if (sum == N) {
			cout << N << " = ";
			for (int i = 0; i < count.size() -1; i++) {
				cout << count[i] << " + ";
			}
			cout << count[count.size() - 1] << endl;
		}
		else {
			cout << N << " is NOT perfect." << endl;
		}
		sum = 0;
		count.clear();
	}


	return 0;
}