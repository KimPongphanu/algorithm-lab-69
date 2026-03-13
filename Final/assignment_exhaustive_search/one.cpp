#include <iostream>
#include <vector>

using namespace std;

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

void permute(vector<int> &arr, int start, int end, int &count)
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

        permute(arr, start + 1, end, count);

        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n;
    int count = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    permute(arr, 0, n - 1, count);
    cout << count << endl;
    return 0;
}