#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(100, vector<int>(100, -1));
int n, k;
int snapsack(vector<int> &price, int index, int k)
{
    if (k == 0)
    {
        return 0;
    }

    if (index == price.size() || k < 0)
    {
        return -1e3;
    }

    if (memo[n][k] != -1)
    {
        return memo[index][k];
    }

    int noSelect = snapsack(price, index + 1, k);

    int select = -1e3;
    if (k >= price[index])
    {
        select = 1 + snapsack(price, index + 1, k - price[index]);
    }
    return max(noSelect, select);
}

int main()
{
    cin >> n >> k;
    vector<int> price(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << snapsack(price, 0, k);
    return 0;
}