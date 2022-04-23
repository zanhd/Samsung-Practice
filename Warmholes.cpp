// Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes/problem

#include <bits/stdc++.h>
using namespace std;

struct Edges
{
    pair<int, int> u;
    pair<int, int> v;
    int cost;
};

int distance(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second; // for min heap
}

vector<int> disktra(vector<vector<int>> &adj, int src, int n)
{
    vector<int> dis(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> Q(compare);

    bool vis[n + 1];
    memset(&vis, 0x00, sizeof(vis));

    Q.push({src, 0});

    while (!Q.empty())
    {
        pair<int, int> now = Q.top();
        Q.pop();

        int u = now.first;

        if (vis[u])
            continue;
        vis[u] = 1;
        dis[u] = now.second;

        for (int v = 1; v <= n; v++)
        {
            if (dis[v] > dis[u] + adj[u][v])
            {
                dis[v] = dis[u] + adj[u][v];
                Q.push({v, dis[v]});
            }
        }
    }

    return dis;
}

void solve()
{
    int n;
    cin >> n;

    map<pair<int, int>, int> indexOf;
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    int index = 1;
    indexOf[{sx, sy}] = index++;
    indexOf[{dx, dy}] = index++;

    Edges edges[n];

    for (int i = 0; i < n; i++)
    {
        int x[2], y[2], cost;
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> cost;

        edges[i].u = {x[0], y[0]};
        edges[i].v = {x[1], y[1]};
        edges[i].cost = cost;

        if (!indexOf[{x[0], y[0]}])
            indexOf[{x[0], y[0]}] = index++;
        if (!indexOf[{x[1], y[1]}])
            indexOf[{x[1], y[1]}] = index++;
    }

    int nodes = index - 1;

    vector<vector<int>> adj(nodes + 1, vector<int>(nodes + 1, INT_MAX));

    for (Edges e : edges)
    {
        adj[indexOf[e.u]][indexOf[e.v]] = e.cost;
        adj[indexOf[e.v]][indexOf[e.u]] = e.cost;
    }

    pair<int, int> Point[nodes + 1];
    for (auto x : indexOf)
        Point[x.second] = x.first;

    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            adj[i][j] = min(adj[i][j], distance(Point[i], Point[j]));
        }
    }

    vector<int> dis = disktra(adj, 1, nodes);

    cout << dis[2] << endl;
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int T = 1;
    cin >> T;
    while (T--)
        solve();
}
