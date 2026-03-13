#include <iostream>
#include <vector>

using namespace std;
int count = 0;

bool isValid(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if ((arr[i] == 1 && arr[i + 1] == 2) || (arr[i] == 2 && arr[i + 1] == 1))
        {
            return true;
        }
    }
    return false;
}

void permute(vector<int> &arr, int start, int end)
{

    if (start == end)
    {
        if (isValid(arr))
        {
            count++;
        }

        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(arr[start], arr[i]);

        permute(arr, start + 1, end);

        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n < 2 || n >= 10)
    {
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    permute(arr, 0, n - 1);
    cout << count;
    return 0;
}