#include <iostream>
#include <vector>

using namespace std;
// int dp[100][100] = {};
vector<vector<int>> dp(100, vector<int>(100, -1));

int binomial(int n, int k)
{
    if (k == 0 || n == k)
    {
        return 1;
    }

    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }

    dp[n][k] = binomial(n - 1, k - 1) + binomial(n - 1, k);

    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << binomial(n, k);
    // cout << dp[n][k];
    // cout << dp[0][0] << " " << dp[0][1];
    return 0;
}