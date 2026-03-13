#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(1e3, vector<int>(1e3, -1));

int f(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
    {
        return matrix[x1][y1];
    }

    if (x1 > x2 || y1 > y2)
    {
        return 1e3;
    }

    if (memo[x1][y1] != -1)
    {
        return memo[x1][y1];
    }

    memo[x1][y1] = matrix[x1][y1] + min(f(matrix, x1 + 1, y1, x2, y2), f(matrix, x1, y1 + 1, x2, y2));
    return memo[x1][y1];
}

int main()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    if ((n < 2 || n > 50) || (m < 2 || m > 50))
    {
        return 0;
    }
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    cout << f(matrix, x1, y1, x2, y2);
    return 0;
}