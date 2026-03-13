#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int> &arr, int index, int sum, int k, vector<int> &memo)
{
    if (sum == k)
    {
        for (const auto &i : memo)
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
    // can
    memo.push_back(arr[index]);
    findSubsets(arr, index + 1, sum + arr[index], k, memo);

    // can't
    memo.pop_back();
    findSubsets(arr, index + 1, sum, k, memo);
}
int main()
{
    int k = 12;
    vector<int> arr = {25, 10, 9, 2, 1};
    vector<int> memo;
    findSubsets(arr, 0, 0, k, memo);
    return 0;
}