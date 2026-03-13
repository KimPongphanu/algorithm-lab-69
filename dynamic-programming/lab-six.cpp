// #include <iostream>
// #include <vector>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n, m;

vector<vector<int>> memo(1e3, vector<int>(1e3, -1));

int solve(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return matrix[x1][y1];
    if (x1 > x2 || y1 > y2 || x1 < 0 || x2 < 0)
    {
        return 1e3;
    }

    if (memo[x1][y1] != -1)
    {
        return memo[x1][y1];
    }

    memo[x1][y1] = matrix[x1][y1] + min(solve(matrix, x1, y1 + 1, x2, y2), solve(matrix, x1 + 1, y1, x2, y2));
    return memo[x1][y1];
}

int main()
{

    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << solve(matrix, x1, y1, x2, y2);
    return 0;
}