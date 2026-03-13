#include <iostream>
#include <vector>

using namespace std;

int findHeight(vector<int> &arr, int l, int r, int m, int h)
{
    if (l > r)
    {
        return h;
    }
    int mid = l + (r - l) / 2;

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }
    if (sum >= m)
    {
        return findHeight(arr, mid + 1, r, m, mid);
    }
    else
    {
        return findHeight(arr, l, mid - 1, m, h);
    }
    return h;
}

int main()
{
    int n = 0, m = 0, max = 0, h = 0;
    cin >> n >> m;
    vector<int> trees(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        if (trees[i] > max)
        {
            max = trees[i];
        }
    }
    cout << findHeight(trees, 0, max, m, h);
    return 0;
}
