//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators

#include <bits/stdc++.h>
using namespace std;

int dp[10][1 << 11];

void global_reset()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < (1 << 11); j++)
            dp[i][j] = -1;
}

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int dfs(int u, pair<int, int> a[], int mask, int n, pair<int, int> &home)
{
    if (dp[u][mask] != -1)
        return dp[u][mask];

    int ans = INT_MAX;
    bool is = 0;
    for (int v = 0; v < n; v++)
    {
        if (mask & (1 << v))
            continue;
        is = 1;
        ans = min(ans, distance(a[u], a[v]) + dfs(v, a, mask + (1 << v), n, home));
    }

    if (!is)
        return dp[u][mask] = distance(a[u], home);
    return dp[u][mask] = ans;
}

int solve()
{
    global_reset();

    int n;
    cin >> n;

    pair<int, int> office, home;
    cin >> office.first >> office.second >> home.first >> home.second;

    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        ans = min(ans, distance(office, a[i]) + dfs(i, a, mask + (1 << i), n, home));
    }

    return ans;
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int T = 10;
    for (int i = 0; i < T; i++)
        cout << "#" << i + 1 << " " << solve() << endl;
}
