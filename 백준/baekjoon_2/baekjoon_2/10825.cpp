#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct member
{
	string name;
	int ko;
	int en;
	int ma;
};
bool compare(member a, member b) {
	if (a.ko == b.ko) {
		if (a.en == b.en) {
			if (a.ma == b.ma) {
				return a.name < b.name;
			}
			return a.ma > b.ma;
		}
		return a.en < b.en;
	}
	return a.ko > b.ko;
}
int main() {

	int N;
	cin >> N;

	vector<member> stu;

	int a, b, c;
	string m;
	for (int i = 0; i < N; i++) {
		cin >> m >> a >> b >> c;
		stu.push_back(member{ m, a, b, c });
	}

	sort(stu.begin(), stu.end(), compare);
	for (auto i : stu) {
		cout << i.name << "\n";
	}


	return 0;
}