#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(100, vector<int>(100, -1));
int m, n;

int f(int i, int j)
{
    if (i == m && j == n)
    {
        return 1;
    }

    if ((i < 0 || i > m) || (j < 0 || j > n))
    {
        return 0;
    }

    if (memo[i][j] == -1)
    {
        memo[i][j] = f(i, j + 1) + f(i + 1, j);
    }

    return memo[i][j];
}

int main()
{
    cin >> m >> n;
    if ((m < 2 || m > 50) || (n < 2 || m > 50))
    {
        return 0;
    }
    cout << f(1, 1);
    return 0;
}