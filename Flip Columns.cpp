#include <bits/stdc++.h>
using namespace std;

int cnt_zero(string a)
{
    int ans = 0;
    for (auto x : a)
        ans += (x == '0');
    return ans;
}

int main()
{

    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    unordered_map<string, int> freq;

    for (int i = 0; i < n; i++)
    {
        string now = "";
        for (int j = 0; j < m; j++)
            now += (a[i][j]) ? '1' : '0';

        freq[now]++;
    }

    int ans = 0;
    for (auto x : freq)
    {
        string row = x.first;

        int zero = cnt_zero(row);

        if (k < zero)
            continue;

        if ((zero & 1) && (k & 1)) // both even
            ans = max(ans, x.second);
        if (!(zero & 1) && !(k & 1)) // both odd
            ans = max(ans, x.second);
    }

    cout << ans;
}
