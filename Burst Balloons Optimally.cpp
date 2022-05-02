//Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }

    int dp[n][n];
    memset(&dp, 0x00, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            dp[i][i] = a[i + 1];
        else if (i == n - 1)
            dp[i][i] = a[i - 1];
        else
            dp[i][i] = a[i - 1] * a[i + 1];
    }

    for (int c = 1; c < n; c++)
    {
        int i = 0;
        int j = c;
        while (i < n && j < n)
        {
            if (i == 0 && j == n - 1)
            {
                // special case
                for (int k = i; k <= j; k++)
                {
                    if (k == 0)
                        dp[i][j] = max(dp[i][j], dp[i + 1][j] + a[i]);
                    else if (k == n - 1)
                        dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[j]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k]);
                }
            }
            else if (i == 0)
            {
                for (int k = i; k <= j; k++)
                {
                    if (k == i)
                        dp[i][j] = max(dp[i][j], dp[k + 1][j] + a[j + 1]);
                    else if (k == j)
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + a[j + 1]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[j + 1]);
                }
            }
            else if (j == n - 1)
            {
                for (int k = i; k <= j; k++)
                {
                    if (k == i)
                        dp[i][j] = max(dp[i][j], dp[k + 1][j] + a[i - 1]);
                    else if (k == j)
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + a[i - 1]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1]);
                }
            }
            else
            {
                for (int k = i; k <= j; k++)
                {
                    if (k == i)
                        dp[i][j] = max(dp[i][j], dp[k + 1][j] + a[i - 1] * a[j + 1]);
                    else if (k == j)
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + a[i - 1] * a[j + 1]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1] * a[j + 1]);
                }
            }

            i++;
            j++;
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
