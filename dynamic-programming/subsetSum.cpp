#include <iostream>
#include <vector>

using namespace std;

bool subsets(vector<int> &A, int n, int k)
{
    vector<vector<bool>> memo(n + 1, vector<bool>(k + 1));

    // case f(n, 0)
    for (int i = 0; i <= n; i++)
    {
        memo[i][0] = true;
    }

    // case f(0, k);
    for (int j = 0; j <= k; j++)
    {
        memo[0][j] = false;
    }

    // process
    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (j < A[i])
            {
                memo[i][j] = memo[i - 1][j];
            }
            else
            {
                memo[i][j] = memo[i - 1][j] || memo[i - 1][j - ]
            }
        }
    }
}

int main()
{
    int k = 6;
    vector<int> A = {3, 4, 5, 2};
    vector<vector<int>> memo(A.size(), vector<int>(k, -1));
    return 0;
}