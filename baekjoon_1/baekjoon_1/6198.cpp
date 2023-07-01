#include <iostream>
#include <stack>
using namespace std;

int main() {

	int N, h;
	cin >> N;
	stack<int> s;
	long long int count = 0;
	int a = 0;
	int high = 0;
	for (int i = 0; i < N; i++) {
		cin >> h;
		if (s.empty()) {
			s.push(h);
			continue;
		}

		if (s.top() <= h) {
			while (s.top() <= h)
			{
				s.pop();
				if (s.empty()) {
					break;
				}
			}
		}
		
		count += s.size();
		s.push(h);

	}


	cout << count;
	return 0;

}