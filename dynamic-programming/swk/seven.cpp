#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(1e3, vector<int>(1e3, -1));

int snapsack(vector<int> &price, int index, int l)
{
    if (l == 0)
    {
        return 0;
    }

    if (index == price.size() || l < 0)
    {
        return -1e3;
    }

    if (memo[index][l] != -1)
    {
        return memo[index][l];
    }

    int noSelect = snapsack(price, index + 1, l);

    int select = -1e3;
    if (l >= price[index])
    {
        select = 1 + snapsack(price, index + 1, l - price[index]);
    }

    return memo[index][l] = max(noSelect, select);
}

int main()
{
    int l;
    cin >> l;
    if (l < 1 || l > 1000)
    {
        return 0;
    }
    vector<int> price(l + 1);
    for (int i = 0; i < l; i++)
    {
        cin >> price[i];
    }
    cout << snapsack(price, 0, l);
    return 0;
}