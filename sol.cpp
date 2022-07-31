#include <bits/stdc++.h>
using namespace std;

void test_cases() {
	string s;
	cin >> s;
	int n = s.size();
	char dir[] = {'D', 'L', 'U', 'R'};
	vector<int> freq(4, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == dir[j]) {
				freq[j]++;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (freq[i] > 0) {
			cnt++;
		}
	}
	if (cnt <= 1) {
		cout << "0\n";
		return;
	}
	if (cnt <= 3) {
		if (freq[0] > 0 && freq[2] > 0) {
			cout << "2\nDU\n";
			return;
		}
		if (freq[1] > 0 && freq[3] > 0) {
			cout << "2\nRL\n";
			return;
		}
	}
	freq[0] = min(freq[0], freq[2]);
	freq[2] = freq[0];
	freq[1] = min(freq[1], freq[3]);
	freq[3] = freq[1];
	int sz = 0;
	for (int i = 0; i < 4; i++) {
		sz += freq[i];
	}
	cout << sz << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < freq[i]; j++) {
			cout << dir[i];
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_cases();
	}
}
