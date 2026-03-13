#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(100, vector<int>(100, -1));

int f(int n, int k)
{
    if (k < 2)
    {
        return 1;
    }

    if (n == k)
    {
        return 1;
    }

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    memo[n][k] = f(n - 1, k) + f(n - 1, k - 2);
    return memo[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    if ((n < 2 || n > 1000) || (k < 2 || k > 1000) || (n < k))
    {
        return 0;
    }
    cout << f(n, k);
    return 0;
}