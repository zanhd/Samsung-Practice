Ques : https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level

#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data = 0;
    string left = "";
    string right = "";
};

Tree fetch(string a)
{
    Tree tree;
    int n = a.length();

    int beg = 1;
    int end = n - 2;

    string now = "";
    for (int i = 1; i < n; i++)
    {
        if (a[i] == '(' || a[i] == ')')
            break;
        now += a[i];
        beg = i + 1;
    }

    tree.data = stoi(now);

    if (beg == n - 1)
        return tree;

    int pf[n];
    pf[beg] = 1;
    for (int i = beg + 1; i <= end; i++)
    {
        if (a[i] == '(')
            pf[i] = pf[i - 1] + 1;
        else if (a[i] == ')')
            pf[i] = pf[i - 1] - 1;
        else
            pf[i] = pf[i - 1];
    }

    int sf[n];
    sf[end] = 1;
    for (int i = end - 1; i >= beg; i--)
    {
        if (a[i] == ')')
            sf[i] = sf[i + 1] + 1;
        else if (a[i] == '(')
            sf[i] = sf[i + 1] - 1;
        else
            sf[i] = sf[i + 1];
    }

    vector<int> zero;
    for (int i = beg; i <= end; i++)
    {
        if (pf[i] == 0 || sf[i] == 0)
            zero.push_back(i);
    }

    tree.left = a.substr(zero[0], zero[1] - zero[0] + 1);  // zero[0] .... zero[1]
    tree.right = a.substr(zero[2], zero[3] - zero[2] + 1); // zero[2] .... zero[3]

    return tree;
}

void dfs(string a, int &sum, int k)
{
    if (a.length() <= 2)
        return;

    Tree tree = fetch(a);

    if (k == 0)
        sum += tree.data;
    else
    {
        dfs(tree.left, sum, k - 1);
        dfs(tree.right, sum, k - 1);
    }
}

int main()
{
    // setbuf(stdout, NULL);
    // freopen("input.txt", "r", stdin);

    int k;
    cin >> k;
    string a;
    cin >> a;

    int sum = 0;
    dfs(a, sum, k);
    cout << sum << endl;
}
