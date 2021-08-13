/*
	arr[] = {1, 1, 2, 3}
	diff = 1

	Possible subsets : [{1, 1, 2}, {3}], [{1, 3}, {1, 2}], [{1, 3}, {1, 2}]
	Answer = 3
*/

#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<int> arr;

void input() {
	cin >> n >> d;
	arr.resize(n + 1, -1);
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
}

int count(int s1) {
	int i, j, t[n + 1][s1 + 1];
	t[0][0] = 1;
	for (i = 1; i <= n; ++i)
		t[i][0] = 1;
	for (i = 1; i <= s1; ++i)
		t[0][i] = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= s1; ++j)
			if (j >= arr[i])
				t[i][j] = t[i - 1][j - arr[i]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
	return t[n][s1];
}

int solve() {
	int i, s = 0;
	for (i = 1; i <= n; ++i)
		s += arr[i];

	if ((s + d) & 1)
		return 0;

	int s1 = (s + d) / 2;
	return count(s1);
}

int main(int argc, char const *argv[])
{
	input();
	cout << solve() << '\n';
	return 0;
}