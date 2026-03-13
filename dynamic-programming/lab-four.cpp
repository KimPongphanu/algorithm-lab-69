#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo(1e3, vector<int>(1e3, -1));

int solve(vector<int> &price, int index, int k)
{
    if (k == 0)
    { // เงินโดนตัดหมดพอดี
        return 0;
    }
    if (index == price.size() || k < 0)
    { // หาหมดแล้ว หรือ เงินติดลบ
        return -1e3;
    }

    int noSelect = solve(price, index + 1, k);

    int select = -1e9;
    if (price[index] <= k)
    {
        select = 1 + solve(price, index + 1, k - price[index]);
    }

    return max(select, noSelect);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << solve(price, 0, k);
    return 0;
}