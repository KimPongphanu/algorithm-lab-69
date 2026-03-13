#include <iostream>
#include <vector>
using namespace std;

int DAC(vector<int> &arr, int l, int r)
{
    if (l == r)
        return arr[l];

    int mid = l + (r - l) / 2;
    int maxLeft = DAC(arr, l, mid);
    int maxRight = DAC(arr, mid + 1, r);

    if (maxLeft > maxRight)
    {
        return maxLeft;
    }
    else
    {
        return maxRight;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << DAC(array, 0, array.size() - 1);
    return 0;
}