#include <iostream>
#include <vector>
#define INF 1e3

using namespace std;

vector<vector<int>> memo(INF, vector<int>(INF, -1));

int f(int n, int k)
{
    if (k < 2 || n == k)
    {
        return 1;
    }

    if (memo[n][k] == -1)
    {
        memo[n][k] = f(n - 1, k) + f(n - 1, k - 2);
    }

    return memo[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    if ((n < k) || (n < 2 || n > 1000) || (k < 2 || k > 1000))
    {
        return 0;
    }
    cout << f(n, k);
    return 0;
}