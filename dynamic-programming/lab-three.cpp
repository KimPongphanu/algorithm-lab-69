#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(1e2, vector<int>(1e2, -1));
int m, n;

int blackTiger(int i, int j)
{
    if (i == m && j == n)
        return 1;
    if (i > m || j > n)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    return memo[i][j] = blackTiger(i, j + 1) + blackTiger(i + 1, j);
}

int main()
{
    cin >> m >> n;
    cout << blackTiger(1, 1);
    return 0;
}