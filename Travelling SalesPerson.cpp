//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4

#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int dis[N][N];
int dp[N][1 << 12];

void global_reset()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << 12); j++)
            dp[i][j] = -1;
}

int dfs(int u, int mask, int n)
{
    if (dp[u][mask] != -1)
        return dp[u][mask];

    int ans = INT_MAX;
    bool is = 0;

    for (int v = 1; v < n; v++)
    {
        if (mask & (1 << v))
            continue;
        is = 1;
        ans = min(ans, dis[u][v] + dfs(v, mask + (1 << v), n));
    }

    if (!is)
        return dp[u][mask] = dis[u][0];
    return dp[u][mask] = ans;
}

int solve()
{
    global_reset();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dis[i][j];

    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        int mask = 0;
        ans = min(ans, dis[0][i] + dfs(i, mask + (1 << i), n));
    }

    return ans;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
}
