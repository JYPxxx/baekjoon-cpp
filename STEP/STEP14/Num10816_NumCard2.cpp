#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	if (n > 500000 || n < 1) return 0;
	unordered_map<int, int> idx;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (-10000000 > a || 10000000 < a) continue;
		auto iter = idx.find(a);
		if (iter == idx.end()) {
			idx[a] = 1;
		}
		else idx[a]++;
	}
	cin >> m;
	if (m > 500000 || m < 1) return 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (-10000000 > a || 10000000 < a) continue;
		auto iter = idx.find(a);
		if (iter == idx.end()) cout << "0 ";
		else cout << iter->second << " ";
	}

	return 0;
}