//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing

#include <bits/stdc++.h>
#define coutpair(x) cout << "{" << x.first << "," << x.second << "}"
using namespace std;

const int N = 11;
int a[N][N];
map<pair<int, int>, vector<pair<int, int>>> adj;
bool vis[N][N];

pair<int, int> find_up(int r, int c, int n, int m)
{
    for (int i = r - 1; i >= 0; i--)
    {
        if (!a[i][c])
            continue;
        return {i, c};
    }
    return {-1, -1};
}

pair<int, int> find_down(int r, int c, int n, int m)
{
    for (int i = r + 1; i < n; i++)
    {
        if (!a[i][c])
            continue;
        return {i, c};
    }
    return {-1, -1};
}

pair<int, int> find_left(int r, int c, int n, int m)
{
    if (c > 0 && a[r][c - 1])
        return {r, c - 1};
    return {-1, -1};
}

pair<int, int> find_right(int r, int c, int n, int m)
{
    if (c < m - 1 && a[r][c + 1])
        return {r, c + 1};
    return {-1, -1};
}

void dfs(int i, int j, int path_mx_h, int &ans)
{

    vis[i][j] = 1;

    if (a[i][j] == 3)
        ans = min(ans, path_mx_h);
    else
    {
        for (auto x : adj[{i, j}])
        {
            if (vis[x.first][x.second])
                continue;

            int mxh = path_mx_h; // imp
            if (x.first < i)
            {
                // jump (up)
                mxh = max(mxh, i - x.first);
            }

            dfs(x.first, x.second, mxh, ans);
        }
    }

    vis[i][j] = 0;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    memset(&vis, 0x00, sizeof(vis));

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!a[i][j])
                continue;

            pair<int, int> up = find_up(i, j, n, m);
            pair<int, int> down = find_down(i, j, n, m);
            pair<int, int> left = find_left(i, j, n, m);
            pair<int, int> right = find_right(i, j, n, m);

            if (up.first != -1 && up.second != -1)
                adj[{i, j}].push_back(up);
            if (down.first != -1 && down.second != -1)
                adj[{i, j}].push_back(down);
            if (left.first != -1 && left.second != -1)
                adj[{i, j}].push_back(left);
            if (right.first != -1 && right.second != -1)
                adj[{i, j}].push_back(right);
        }
    }

    int ans = INT_MAX;
    dfs(n - 1, 0, 0, ans);
    cout << ans << endl;
}
