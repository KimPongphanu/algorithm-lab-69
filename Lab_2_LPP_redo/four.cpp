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
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    if (n < 1 || n > 10000)
        return 0;
    vector<int> array(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0 || temp > 5000)
            return 0;
        array[i] = temp;
    }
    merge_sort(array, 0, array.size() - 1);

    int count = 1;
    int max = 0;
    vector<int> fequenceArr;
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] + 1 == array[i + 1])
        {
            count++;
        }
        else
        {
            fequenceArr.push_back(count);
            count = 1;
        }
    }

    merge_sort(fequenceArr, 0, fequenceArr.size() - 1);
    cout << fequenceArr.back() << endl;

    return 0;
}