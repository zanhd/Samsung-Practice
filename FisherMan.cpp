//Ques :  https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman

#include <bits/stdc++.h>
using namespace std;

int distance(int i, int gate)
{
    return abs(i - gate) + 1;
}

int find(int beg, int end, int gate)
{
    int ans = 0;
    for (int i = beg; i <= end; i++)
        ans += distance(i, gate);
    return ans;
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    pair<int, int> a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i].first;
    for (int i = 0; i < 3; i++)
        cin >> a[i].second;

    int ans = INT_MAX;

    for (int i = 0; i <= n - (a[0].second + a[1].second + a[2].second); i++)
    {
        for (int j = i + a[0].second; j <= n - (a[1].second + a[2].second); j++)
        {
            for (int k = j + a[1].second; k <= n - a[2].second; k++)
            {
                int part_one = find(i, i + a[0].second - 1, a[0].first - 1);
                int part_two = find(j, j + a[1].second - 1, a[1].first - 1);
                int part_three = find(k, k + a[2].second - 1, a[2].first - 1);

                ans = min(ans, part_one + part_two + part_three);
            }
        }
    }

    cout << ans << endl;
}
