#include <iostream>
#include <vector>

using namespace std;

int search_rotate(vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[l] <= arr[mid])
        {
            if (arr[l] <= target && target < arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (arr[r] >= target && target > arr[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << search_rotate(arr, target);
    return 0;
}
