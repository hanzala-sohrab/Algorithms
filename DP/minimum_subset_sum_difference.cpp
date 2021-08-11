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

int count() {
    int i, j, sum = 0;
    for (i = 1; i <= n; ++i)
        sum += arr[i];
    vector<vector<int>> t(n + 1, vector<int>(sum));
    t[0][0] = 1;
    for (i = 1; i <= n; ++i)
        t[i][0] = 1;
    for (i = 1; i < sum; ++i)
        t[0][i] = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j < sum; ++j)
            if (j >= arr[i])
                t[i][j] = t[i - 1][j - arr[i]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
    int ans = INT_MAX;
    for (i = sum / 2; i < sum; ++i)
        if (t[n][i])
            ans = min(ans, sum - 2 * i);
    return ans;
}

int main() {
    input();
    cout << count() << '\n';
    return 0;
}