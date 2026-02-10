#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, m = 0;
	cin >> n >> m;
	if (n <= 0 || n > 100000 || m <= 0 || m > 100000) return 0;

	vector<string> pocketMon;
	pocketMon.reserve(n);
	unordered_map<string, int> idx;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s.size() < 2 || s.size() > 20) return 0;

		if (s[0] >= 'A' && s[0] <= 'Z') {
			for (int j = 1; j < s.size(); j++) {
				if (s[j] < 'a' || s[j] > 'z') j--;
			}
		}
		int x = s.size() - 1;

		if (s[x] >= 'A' && s[x] <= 'Z') {
			for (int j = 1; j < s.size(); j++) {
				if (s[j] < 'a' || s[j] > 'z') j--;
			}
		}

		pocketMon.push_back(s);
		idx[s] = i;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int check = 0;
		if (s[0] >= 'A' && s[0] <= 'z') {
			if (s.size() < 2 || s.size() > 20) return 0;
			auto iter = idx.find(s);
			if (iter == idx.end()) return 0;
			cout << iter->second + 1 << '\n';
		}

		else if (isdigit(s[0])) {
			for (int j = 1; j < s.size(); j++) {
				if (!isdigit(s[j])) return 0;
			}
			int num = stoi(s);
			if (num <= 0 || num > n) return 0;
			cout << pocketMon[num - 1] << '\n';
		}

		else return 0;
	}

	return 0;
}