#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        if ((A[i] == 1 && A[i + 1] == 2) || (A[i] == 2 && A[i + 1] == 1))
        {
            return true;
        }
    }
    return false;
}

void permute(vector<int> &A, int index, int &count)
{
    if (A.size() == index)
    {
        // for (int i = 0; i < A.size(); i++)
        // {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        if (isValid(A))
        { // wait
            count++;
        }
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        swap(A[index], A[i]);
        permute(A, index + 1, count);
        swap(A[index], A[i]);
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    ;
    if (n < 2 || n > 10)
        return 0;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    int count = 0;
    permute(A, 0, count);
    cout << count;
    return 0;
}
