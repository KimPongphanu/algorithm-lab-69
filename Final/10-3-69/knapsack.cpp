#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Item
{
    int V;
    int W;
};

int findMaxVal(vector<Item> &A, int index, int k, int currentV, int currentW)
{

    if (currentW > k)
    {
        return -1e9;
    }

    if (A.size() == index)
    {
        return currentV;
    }

    // select
    int select = findMaxVal(A, index + 1, k, currentV + A[index].V, currentW + A[index].W);

    // no select
    int noSelect = findMaxVal(A, index + 1, k, currentV, currentW);

    return max(select, noSelect);
}

int main()
{
    int k;
    cin >> k;
    int n = 4;
    vector<Item> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].V;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].W;
    }

    cout << findMaxVal(A, 0, k, 0, 0);
    return 0;
}