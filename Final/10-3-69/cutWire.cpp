#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMinVal(vector<int> &A, int index, int k, int sum, int count)
{
    if (sum == k)
    {
        return count;
    }

    if (sum > k)
    {
        return 1e9;
    }

    if (index == A.size())
    {
        return (sum > 0) ? count : 1e9;
    }
    int min_val = 1e9;

    for (int i = 0; i < A.size(); i++)
    {

        int res = findMinVal(A, index + 1, k, sum + A[i], count + 1);
        if (res != 1e9)
        {
            min_val = min(res, min_val);
        }
    }

    return min_val;
}

int main()
{
    int n = 3, k;
    cin >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << findMinVal(A, 0, k, 0, 0);
    return 0;
}