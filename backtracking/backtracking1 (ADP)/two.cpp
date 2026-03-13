#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(j - i) == abs(arr[i] - arr[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void permute(vector<int> &arr, int start)
{
    if (start == arr.size())
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
        if (isValid(arr, arr.size()))
        {
            cout << "Win\n";
        }
        else
        {
            cout << "Lose\n";
        }
    }
    for (int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        permute(arr, start + 1);
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
    permute(arr, 0);

    return 0;
}