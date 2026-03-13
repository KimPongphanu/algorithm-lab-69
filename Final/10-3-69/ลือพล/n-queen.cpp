#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (abs(i - j) == abs(A[i] - A[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void permute(vector<int> &A, int index)
{
    if (index == A.size())
    {
        if (isValid(A))
        {
            for (const auto &a : A)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        swap(A[index], A[i]);
        permute(A, index + 1);
        swap(A[index], A[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n < 3 || n > 8)
    {
        return 0;
    }
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
    permute(A, 0);
    return 0;
}