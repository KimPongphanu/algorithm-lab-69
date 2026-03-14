#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class dynamicProgramming
{
private:
    int one(int n, int k, vector<vector<int>> &memo)
    {
        if (k < 2 || n == k)
            return 1;
        if (memo[n][k] != -1)
            return memo[n][k];

        return memo[n][k] = one(n - 1, k, memo) + one(n - 1, k - 2, memo);
    }

    int two(int n, vector<int> &memo)
    {
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            memo[i] = memo[i - 1] + memo[i - 2] - memo[i - 3];
        }
        return memo[n];
    }

    int three(int n, int m, int r, int c, vector<vector<int>> &memo)
    {
        if (n == r && m == c)
        {
            return 1;
        }

        if (r > n || c > m)
        {
            return 0;
        }

        if (memo[r][c] != -1)
        {
            return memo[r][c];
        }

        int right = three(n, m, r, c + 1, memo);
        int down = three(n, m, r + 1, c, memo);
        memo[r][c] = right + down;
        return memo[r][c];
    }

    int four(const vector<int> &price, int n, int k, vector<vector<int>> &memo, int index)
    {
        if (k == 0)
        {
            return 0;
        }

        if (price.size() == index || k < 0)
        {
            return 0;
        }

        if (memo[index][k] != -1)
        {
            return memo[index][k];
        }

        int noSelect = four(price, n, k, memo, index + 1);
        int select = -1e3;
        if (k >= price[index])
        {
            select = 1 + four(price, n, k - price[index], memo, index + 1);
        }

        return memo[index][k] = max(select, noSelect);
    }

    int five(int i, int j, vector<vector<int>> &memo)
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

        return memo[i][j] = min({(five(i - 1, j, memo) + 2), (five(i, j - 1, memo) + 3), (five(i - 1, j - 1, memo) + C)});
    }

    int six(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2, vector<vector<int>> &memo)
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

        int down = six(matrix, x1 + 1, y1, x2, y2, memo);
        int right = six(matrix, x1, y1 + 1, x2, y2, memo);

        return memo[x1][y1] = matrix[x1][y1] + min(down, right);
    }

    int seven(vector<int> &matrix, int L, vector<int> &memo)
    {
        if (L == 0)
        {
            return 0;
        }

        if (L < 0)
        {
            return -1e3;
        }

        if (memo[L] != -1)
        {
            return memo[L];
        }
        int maxPrice = -1e3;
        for (int i = 1; i <= L; i++)
        {
            int select = matrix[i - 1] + seven(matrix, L - i, memo);
            maxPrice = max(maxPrice, select);
        }
        return memo[L] = maxPrice;
    }

    int eight(vector<int> &coins, int n, int k, vector<int> &memo)
    {
        memo[0] = 1;

        for (int i = 0; i < k; i++)
        {
            for (int j = coins[i]; j <= n; j++)
            {
                memo[j] += memo[j - coins[i]];
            }
        }

        return memo[n];
    }

public:
    void oneDriver()
    {
        int n, k;
        cin >> n >> k;
        if ((n < 2 || n > 1000) || (k < 2 || k > 1000) || (n < k))
        {
            return;
        }
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        cout << one(n, k, memo);
        return;
    }

    void twoDriver()
    {
        int n;
        cin >> n;
        if (n < 2 || n > 1000)
        {
            return;
        }
        vector<int> memo(n + 1, -1);
        cout << two(n, memo);
        return;
    }

    void threeDriver()
    {
        int n, m;
        cin >> n >> m;
        if ((n < 2 || n > 50) || (m < 2 || m > 50))
        {
            return;
        }
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        cout << three(n, m, 1, 1, memo);
        return;
    }

    void fourDriver()
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        vector<int> price(n);
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        cout << four(price, n, k, memo, 0);
        return;
    }

    void fiveDriver()
    {
        int i, j;
        cin >> i >> j;
        vector<vector<int>> memo(i + 1, vector<int>(j + 1, -1));
        cout << five(i, j, memo);
        return;
    }

    void sixDriver()
    {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m;
        vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        cin >> x1 >> y1 >> x2 >> y2;
        cout << six(matrix, x1, y1, x2, y2, memo);
        return;
    }

    void sevenDriver()
    {
        int L;
        cin >> L;
        vector<int> matrix(L);
        for (int i = 0; i < L; i++)
        {
            cin >> matrix[i];
        }
        vector<int> memo(L + 1, -1);
        cout << seven(matrix, L, memo);
        return;
    }
    void eightDriver()
    {
        int k, n;
        cin >> n >> k;
        vector<int> coins(k);
        for (int i = 0; i < k; i++)
        {
            cin >> coins[i];
        }
        vector<int> memo(n + 1, 0);
        cout << eight(coins, n, k, memo);
        return;
    }
};

int main()
{
    dynamicProgramming dp;
    // dp.oneDriver();
    // dp.twoDriver();
    // dp.threeDriver();
    // dp.fourDriver();
    // dp.fiveDriver();
    // dp.sixDriver();
    // dp.sevenDriver();
    dp.eightDriver();

    return 0;
}