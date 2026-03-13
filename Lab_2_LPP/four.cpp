#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;

    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int process(vector<int> &arr)
{
    if (arr.empty())
        return -1;
    vector<int> counting;
    int count = 1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if ((arr[i] + 1) == arr[i + 1])
        {
            count++;
        }
        else
        {
            counting.push_back(count);
            count = 1;
        }
    }
    counting.push_back(count);

    if (!counting.empty())
    {
        merge_sort(counting, 0, counting.size() - 1);
    }
    return counting.back();
}

void driver()
{
    int n;
    if (!(cin >> n))
        return;
    if (n < 1 || n > 10000)
        return;
    vector<int> members(n);
    for (int i = 0; i < n; i++)
    {
        cin >> members[i];
        if (members[i] < 0 || members[i] > 5000)
        {
            return;
        }
    }
    merge_sort(members, 0, members.size() - 1);
    int result = process(members);
    cout << result << endl;
}

int main() // O(n log n)
{
    driver();
    return 0;
}