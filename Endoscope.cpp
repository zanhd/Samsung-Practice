//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope

#include <bits/stdc++.h>
using namespace std;

int a[50][50];

bool up(int i, int j)
{
    if (i == 0)
        return 0;
    return (a[i][j] == 1 || a[i][j] == 2 || a[i][j] == 4 || a[i][j] == 7);
}

bool down(int i, int j, int n)
{
    if (i == n - 1)
        return 0;
    return (a[i][j] == 1 || a[i][j] == 2 || a[i][j] == 5 || a[i][j] == 6);
}

bool left(int i, int j)
{
    if (j == 0)
        return 0;
    return (a[i][j] == 1 || a[i][j] == 3 || a[i][j] == 6 || a[i][j] == 7);
}

bool right(int i, int j, int m)
{
    if (j == m - 1)
        return 0;
    return (a[i][j] == 1 || a[i][j] == 3 || a[i][j] == 4 || a[i][j] == 5);
}

int solve()
{
    int n, m, r, c, l;
    cin >> n >> m >> r >> c >> l;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    queue<pair<int, int>> Q;
    map<pair<int, int>, int> vis;

    Q.push({r, c});
    vis[{r, c}] = 1;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        Q.pop();

        int i = u.first;
        int j = u.second;

        if (up(i, j) && down(i - 1, j, n) && !vis[{i - 1, j}])
        {
            Q.push({i - 1, j});
            vis[{i - 1, j}] = vis[{i, j}] + 1;
        }

        if (down(i, j, n) && up(i + 1, j) && !vis[{i + 1, j}])
        {
            Q.push({i + 1, j});
            vis[{i + 1, j}] = vis[{i, j}] + 1;
        }

        if (left(i, j) && right(i, j - 1, m) && !vis[{i, j - 1}])
        {
            Q.push({i, j - 1});
            vis[{i, j - 1}] = vis[{i, j}] + 1;
        }

        if (right(i, j, m) && left(i, j + 1) && !vis[{i, j + 1}])
        {
            Q.push({i, j + 1});
            vis[{i, j + 1}] = vis[{i, j}] + 1;
        }
    }

    int ans = 0;
    for (auto x : vis)
        ans += (x.second > 0 && x.second <= l);
    return ans;
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
}
