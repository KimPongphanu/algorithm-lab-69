#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Item
{
    int V;
    int W;
};

int knapsack(vector<Item> &A, int index, int k, int currentV, int currentW)
{

    if (index == A.size())
    {
        return currentV;
    }

    if (currentW > k)
    {
        return -1e9;
    }

    // select
    int select = knapsack(A, index + 1, k, currentV + A[index].V, currentW + A[index].W);
    // no select
    int noSelect = knapsack(A, index + 1, k, currentV, currentW);

    return max(select, noSelect);
}

main()
{
    int n, k;
    cin >> n >> k;
    if (n < 1 || n > 10 || k < 1 || k > 100)
    {
        return 0;
    }
    vector<Item> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].V;
        if (A[i].V < 1 || A[i].V > 100)
        {
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].W;
        if (A[i].W < 1 || A[i].W > 100)
        {
            return 0;
        }
    }
    cout << knapsack(A, 0, k, 0, 0);
    return 0;
}