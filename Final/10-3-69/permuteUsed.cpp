#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<char> &A, int index, vector<char> &current, vector<bool> &used)
{
    if (A.size() == index)
    {
        for (const auto &a : current)
        {
            cout << a;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            current.push_back(A[i]);
            permute(A, index + 1, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n < 3 || n > 26)
    {
        return 0;
    }
    vector<char> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<bool> used(n, false);
    vector<char> currents;
    permute(A, 0, currents, used);
    return 0;
}