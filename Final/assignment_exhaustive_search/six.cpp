#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<string> &arr, vector<string> &current, vector<bool> used)
{
    if (arr.size() == current.size())
    {
        for (const auto &i : current)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (used[i])
        {
            continue;
        }

        used[i] = true;
        current.push_back(arr[i]);

        permute(arr, current, used);

        current.pop_back();
        used[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<string> current;
    vector<bool> used(n, false);
    permute(arr, current, used);
    return 0;
}