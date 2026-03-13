#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<char> &A, int index, vector<char> &currents, vector<bool> &used)
{
    if (index == A.size())
    {
        for (int i = 0; i < currents.size(); i++)
        {
            cout << currents[i];
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            currents.push_back(A[i]);

            permute(A, index + 1, currents, used);

            currents.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n < 3 || n > 26)
        return 0;
    vector<char> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<char> currents;
    vector<bool> used(n, false);
    sort(A.begin(), A.end());
    permute(A, 0, currents, used);

    return 0;
}