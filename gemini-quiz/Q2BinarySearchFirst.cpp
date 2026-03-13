#include <iostream>
#include <vector>

using namespace std;

int findFirst(vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;
    int memo = -1;
    while (l <= r)
    {

        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            memo = mid;
            r = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return memo;
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findFirst(arr, k);
    return 0;
}