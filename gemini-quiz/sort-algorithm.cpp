#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[i + low];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[j + mid + 1];
        }

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2)
        {
            if (L[i] < R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void merge_sort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return;
        }

        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void shell_sort(vector<int> &arr)
    {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                int temp = arr[i];
                int j = 0;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    void select_median(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[low])
            {
                swap(arr[mid], arr[low]);
            }
            if (arr[high] < arr[low])
            {
                swap(arr[high], arr[low]);
            }
            if (arr[high] < arr[mid])
            {
                swap(arr[high], arr[mid]);
            }

            swap(arr[mid], arr[high]);
        }
    }

    int partition(vector<int> &arr, int low, int high)
    {
        select_median(arr, low, high);
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
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
};

int main()
{
    vector<int> A = {3, 2, 1, 5, 4, 7, 6, 9, 8};
    Sort s;
    // s.merge_sort(A, 0, A.size() - 1);
    // s.shell_sort(A);
    s.quick_sort(A, 0, A.size() - 1);
    for (int i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}