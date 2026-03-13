#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> memo(100, vector<int>(100, -1));

int P(int i, int j)
{
    if (i == 0)
    {
        return 3 * j;
    }

    if (j == 0)
    {
        return 2 * i;
    }

    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int C = (2 * i) + j;

    memo[i][j] = min({P(i - 1, j) + 2, P(i, j - 1) + 3, P(i - 1, j - 1) + C});
    return memo[i][j];
}

int main()
{
    int n, m;
    cin >> n >> m;
    if ((n < 0 || n > 100) || (m < 0 || m > 100))
    {
        return 0;
    }
    cout << P(n, m);
    return 0;
}