#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;

    int pi = partition(arr, l, r);

    quick_sort(arr, l, pi - 1);
    quick_sort(arr, pi + 1, r);
}

bool binary_search(vector<int> &arr, int l, int r, int key)
{
    if (l >= r)
        return false;
    int mid = l + (r - l) / 2;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] < key)
    {
        return binary_search(arr, mid + 1, r, key);
    }
    else
    {
        return binary_search(arr, l, mid - 1, key);
    }
    return false;
}

int main()
{
    vector<int> A = {6, 8, 7, 4, 1};
    vector<int> B = {3, 2, 7, 1, 2};
    quick_sort(A, 0, A.size() - 1);
    quick_sort(B, 0, B.size() - 1);
    vector<int> ArrIntersecion;
    vector<int> ArrUnoin;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == B[i])
        {
            ArrIntersecion.push_back(A[i]);
            ArrUnoin.push_back(A[i]);
        }
        else if (A[i] != B[i])
        {
            bool checkA = binary_search(ArrUnoin, 0, ArrUnoin.size() - 1, A[i]);
            if (!checkA)
            {
                ArrUnoin.push_back(A[i]);
            }
            bool checkB = binary_search(ArrUnoin, 0, ArrUnoin.size() - 1, B[i]);
            if (!checkB)
            {
                ArrUnoin.push_back(B[i]);
            }
        }
    }

    for (int i : ArrIntersecion)
        cout << i << " ";
    cout << endl;
    for (int i : ArrUnoin)
        cout << i << " ";
    cout << endl;
    return 0;
}