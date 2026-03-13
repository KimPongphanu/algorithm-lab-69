#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 1; j <= arr.size() - 1; j++)
        {
            if (arr[i] + arr[j] < k)
            {
                return true;
            }
        }
    }
    return false;
}

void findSubset(vector<int> &arr, int index, int sum, int &k, vector<int> &currents)
{

    if (sum == k)
    {
        for (const auto &i : currents)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    if (sum > k || index == arr.size())
    {
        return;
    }

    if (isValid(arr, k))
    {
        currents.push_back(arr[index]);
    }
    findSubset(arr, index + 1, sum + arr[index], k, currents);

    currents.pop_back();
    findSubset(arr, index + 1, sum, k, currents);
}

int main()
{
    int k = 12;
    vector<int> A = {25, 10, 9, 2, 1};
    vector<int> currents;
    int sum = 0;
    findSubset(A, 0, sum, k, currents);
    return 0;
}