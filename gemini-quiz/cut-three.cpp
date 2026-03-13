#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &arr, int l, int r, int m, int h)
{
    if (l > r)
        return h;
    int mid = l + (r - l) / 2;

    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }
    if (sum >= m)
    {
        return binary_search(arr, mid + 1, r, m, mid);
    }
    else
    {
        return binary_search(arr, l, mid - 1, m, h);
    }
}

int main()
{
    int n, m, h;
    cin >> n >> m;
    vector<int> trees(n);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        if (trees[i] > max)
        {
            max = trees[i];
        }
    }

    cout << binary_search(trees, 0, max, m, 0);

    return 0;
}
