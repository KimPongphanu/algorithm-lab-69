#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo2(1e2, vector(1e2, -1));

int f_n(int n, vector<int> &memo)
{
    memo[0] = 0;
    memo[1] = 1;
    cout << memo[0] << endl;
    cout << memo[1] << endl;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
        cout << memo[i] << endl;
    }

    return memo[n];
}

int f(int n, vector<int> &memo)
{
    if (n < 2)
    {
        cout << memo[n] << endl;
        return n;
    }
    if (memo[n] != -1)
    {
        cout << memo[n] << endl;
        return memo[n];
    }

    memo[n] = f(n - 1, memo) + f(n - 2, memo);
    cout << memo[n] << endl;
    return memo[n];
}

int f1(int n, int k)
{
    if (k < 2 || n == k)
    {
        return 1;
    }

    if (memo2[n][k] != -1)
    {
        return memo2[n][k];
    }

    if (n >= k)
    {
        memo2[n][k] = f1(n - 1, k) + f1(n - 1, k - 2);
    }
    return memo2[n][k];
}

int f2(int n, vector<int> &memo)
{
    if (n == 0)
    {
        return 0;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = f2(n - 1, memo) + n;
    return memo[n];
}

int f3(int n, vector<int> &memo)
{
    if (n < 3)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = f3(n - 1, memo) + f3(n - 2, memo) + f3(n - 3, memo);
    return memo[n];
}

int f4(int n, vector<int> &memo)
{
    if (n == 0)
    {
        return 1;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = f4(n - 1, memo) + f4(n / 2, memo);
    return memo[n];
}

int f5(int n, vector<int> &memo)
{
    if (n == 0)
    {
        return 2;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] = f5(n - 1, memo) + (2 * f5(n - 1, memo));
    return memo[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> memo(n + 1, -1);

    // cout << f5(n, memo);
    cout << f1(n, k);
    return 0;
}
