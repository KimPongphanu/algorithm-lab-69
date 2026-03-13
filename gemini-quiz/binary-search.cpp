#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &array, int left, int right, int key)
{
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (array[mid] == key)
    {
        return mid;
    }
    else if (array[mid] < key)
    {
        return binary_search(array, mid + 1, right, key);
    }
    else
    {
        return binary_search(array, left, mid - 1, key);
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << binary_search(array, 0, array.size() - 1, k);
    return 0;
}
