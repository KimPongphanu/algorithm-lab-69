#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &arr, int start)
{
    int i = start - 1;
    for (int j = 0; j < i; j++)
    {
        if (arr[i] == arr[j])
        {
            return false;
        }

        if (abs(i - j) == abs(arr[i] - arr[j]))
        {
            return false;
        }
    }
    return true;
}

void permute(vector<int> &arr, int start = 0)
{
    if (start == arr.size())
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
        cout << "Win\n";
    }

    for (int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        if (isValid(arr, start + 1))
        {
            permute(arr, start + 1);
        }
        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    permute(arr);
    return 0;
}