#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(100, vector<int>(100, -1));

int F(int n, int k)
{
    if (k < 2 || n == k)
    {
        return memo[n][k] = 1;
    }

    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    memo[n][k] = F(n - 1, k) + F(n - 1, k - 2);
    return memo[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << F(n, k);
    return 0;
}