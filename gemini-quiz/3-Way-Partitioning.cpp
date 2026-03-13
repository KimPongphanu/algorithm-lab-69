#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int l = 0;
    int mid = 0;
    int r = n - 1;

    while (mid <= r)
    {
        if (A[mid] == 0)
        {
            swap(A[l], A[mid]);
            l++;
            mid++;
        }
        else if (A[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(A[mid], A[r]);
            r--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
