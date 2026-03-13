#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Slot
{
    int V;
    int W;
};

int findMaxVal(vector<Slot> &A, int index, int currentW, int currentV, int k)
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
    int select = findMaxVal(A, index + 1, A[index].W + currentW, A[index].V + currentV, k);
    // no select
    int noSelect = findMaxVal(A, index + 1, currentW, currentV, k);

    return max(select, noSelect);
}

int main()
{
    int k;
    cin >> k;
    int n = 4;
    vector<Slot> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].V;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].W;
    }

    cout << findMaxVal(A, 0, 0, 0, k);
    return 0;
}