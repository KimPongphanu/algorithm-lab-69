#include <iostream>
#include <vector>

using namespace std;

void subset(vector<int> &A, int index, int k, int sum, vector<int> &currents)
{

    if (sum == k) // found Case
    {
        for (int i = 0; i < currents.size(); i++)
        {
            cout << currents[i] << " ";
        }
        cout << endl;
        return;
    }

    if (sum > k || A.size() == index)
    {
        return;
    }

    // select
    currents.push_back(A[index]);
    subset(A, index + 1, k, sum + A[index], currents);

    // no select
    currents.pop_back();
    subset(A, index + 1, k, sum, currents);
}

int main()
{
    int k, sum = 0;
    cin >> k;
    int n = 5;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> currents;
    subset(A, 0, k, sum, currents);
    return 0;
}