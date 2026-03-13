#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<char> &X, vector<char> &currents, vector<bool> &used)
{
    if (X.size() == currents.size())
    {
        for (char c : currents)
            cout << c;
        cout << endl;
        return;
    }

    for (int i = 0; i < X.size(); i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        currents.push_back(X[i]);

        permute(X, currents, used);

        currents.pop_back();
        used[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    vector<bool> used(n, false);
    vector<char> currents;
    permute(X, currents, used);
    return 0;
}