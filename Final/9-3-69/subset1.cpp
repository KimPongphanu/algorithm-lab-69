#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int> &A, int index, vector<int> &currents, int currentSum, int k)
{
    if (currentSum == k)
    {
        for (int i = 0; i < currents.size(); i++)
        {
            cout << currents[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index == A.size() || currentSum > k)
    {
        return;
    }

    // select way
    currents.push_back(A[index]);
    findSubsets(A, index + 1, currents, A[index] + currentSum, k);

    // no select way
    currents.pop_back();
    findSubsets(A, index + 1, currents, currentSum, k);
}

int main()
{
    int k;
    int n = 5;
    vector<int> A(n);
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> currents;
    findSubsets(A, 0, currents, 0, k);
    return 0;
}