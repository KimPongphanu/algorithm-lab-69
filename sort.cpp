#include <iostream>
#include <vector>
using namespace std;

class Sort
{
private:
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
            if (leftArr[i] <= rightArr[j])
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

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

public:
    void merge_sort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

    void quick_sort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quick_sort(arr, low, pi - 1);
            quick_sort(arr, pi + 1, high);
        }
    }

    void shell_sort(vector<int> &arr)
    {
        int n = arr.size();

        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)

                        {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
};

int main()
{
    vector<int> data = {45, 12, 8, 99, 3, 76, 24, 1, 55, 33, 89, 7, 10, 62, 18};
    int size = data.size() - 1;
    Sort sort;
    // sort.merge_sort(data, 0, size);
    // sort.quick_sort(data, 0, size);
    sort.shell_sort(data);
    for (int i : data)
    {
        cout << i << " ";
    }
    return 0;
}