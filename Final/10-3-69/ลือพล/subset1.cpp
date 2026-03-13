#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int> &A, int index, int sum, vector<int> &currents, int k)
{
    if (sum == k)
    {
        for (int i = 0; i < currents.size(); i++)
        {
            cout << currents[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index == A.size() || sum > k)
    {
        return;
    }

    // select
    currents.push_back(A[index]);
    findSubsets(A, index + 1, sum + A[index], currents, k);

    // no select
    currents.pop_back();
    findSubsets(A, index + 1, sum, currents, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (n < 1 || k > 100)
    {
        return 0;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> currents;
    findSubsets(A, 0, 0, currents, k);
    return 0;
}