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

void permute(vector<int> &A, int index, int n, int &count)
{
    if (index == n)
    {
        if (isValid(A))
        {
            count++;
        }
    }

    for (int i = index; i < n; i++)
    {
        swap(A[index], A[i]);
        permute(A, index + 1, n, count);
        swap(A[index], A[i]);
    }
}

int main()
{
    int count = 0;
    int n;
    cin >> n;
    if (n < 2 || n > 10)
        return 0;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    permute(A, 0, n, count);
    cout << count << endl;
    return 0;
}