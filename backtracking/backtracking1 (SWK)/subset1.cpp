#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> &A, int sum, int &target, vector<int> &currents, int start)
{
    if (sum == target)
    {
        for (int i = 0; i < currents.size(); i++)
        {
            cout << currents[i] << " ";
        }
        cout << endl;
        return;
    }

    if (sum > target)
    {
        return;
    }

    for (int i = start; i < A.size(); i++)
    {
        currents.push_back(A[i]);
        permutation(A, sum + A[i], target, currents, i + 1);
        currents.pop_back();
    }
}

int main()
{
    int k = 12;
    int sum = 0;
    vector<int> currents;
    int start = 0;
    vector<int> A = {25, 10, 9, 2, 1};
    permutation(A, sum, k, currents, start);
    return 0;
}