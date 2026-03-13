#include <iostream>
#include <vector>

using namespace std;

bool isChecked(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < i; j++)
        {
            if (abs(j - i) == abs(arr[i] - arr[j]))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    if (isChecked(arr, n))
    {
        cout << "Win\n";
    }
    else
    {
        cout << "Lose\n";
    }
    return 0;
}