#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> &arr, vector<int> currents, vector<bool> used, int &count)
{
    // base case
    if (currents.size() == arr.size())
    {
        for (int i : currents)
        {
            cout << i << " ";
        }
        count++;
        cout << endl;
        return;
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            currents.push_back(arr[i]);
            permutation(arr, currents, used, count);
            currents.pop_back();
            used[i] = false;
        }
    }
}

void permutation_swap(vector<int> &arr, int start)
{
    if (start == arr.size())
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    for (int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        permutation_swap(arr, start + 1);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> currents;
    vector<bool> used(arr.size(), false);
    int count = 0;
    // permutation(arr, currents, used, count);
    permutation_swap(arr, 0);
    // cout << count;
    return 0;
}