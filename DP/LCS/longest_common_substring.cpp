#include<bits/stdc++.h>
using namespace std;

string x, y;

void input() {
    cin >> x >> y;
}

void output() {
    int n, m, i, j, ans, t[n+1][m+1];
    n = x.size();
    m = y.size();
    ans = 0;
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            ans = max(ans, t[i][j]);
        }
    }
    cout << ans << '\n';
}

int main(int argc, char const *argv[]) {
    input();
    output();
    return 0;
}
