#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

void input() {
	cin >> n;
	arr.resize(n + 1, -1);
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
}

int solve() {
	int i, j, sum = 0;
	for (i = 1; i <= n; ++i)
		sum += arr[i];
	if (sum & 1)
		return false;

	sum >>= 1;
	bool t[n + 1][sum + 1];
	sort(arr.begin(), arr.end());
	t[0][0] = true;
	for (i = 1; i <= sum; ++i)
		t[0][i] = false;
	for (i = 1; i <= n; ++i)
		t[i][0] = true;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= sum; ++j)
			if (j >= arr[i])
				t[i][j] = t[i - 1][j - arr[i]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
	return t[n][sum];
}

int main() {
	input();
	cout << (solve() ? "Possible" : "Not possible") << '\n';
	return 0;
}
