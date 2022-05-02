//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing

#include <bits/stdc++.h>
using namespace std;

int a[50][5];
int b[50][5];
int dp[50][5];

int find_score(int n)
{
    memset(&dp, 0x00, sizeof(dp));
    for (int j = 0; j < 5; j++)
    {
        if (b[0][j] == 2)
            dp[0][j] = 0;
        else
            dp[0][j] = b[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (b[i][j] == 2)
                continue;

            dp[i][j] = b[i][j];
            if (b[i - 1][j] != 2)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + b[i][j]);
            if (j > 0 && b[i - 1][j - 1] != 2)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + b[i][j]);
            if (j < 4 && b[i - 1][j + 1] != 2)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + b[i][j]);
        }
    }

    return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
}

int solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];

    int ans = 0;
    for (int row = 0; row < n; row++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                b[i][j] = a[i][j];

        for (int i = row; i < min(n, row + 5); i++)
            for (int j = 0; j < 5; j++)
                if (b[i][j] == 2)
                    b[i][j] = 0;

        ans = max(ans, find_score(n));
    }

    return ans;
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "#" << i + 1 << " " << solve() << endl;
    }
}
