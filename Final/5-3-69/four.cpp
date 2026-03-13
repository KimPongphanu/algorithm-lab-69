#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isValid(vector<int> &X, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (abs(i - j) == abs(X[i] - X[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void permute(vector<int> &X, int start, int n)
{
    if (start == n + 1)
    {
        if (isValid(X, n))
        {
            for (int i = 1; i <= n; i++)
            {
                cout << X[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = start; i <= n; i++)
    {
        swap(X[start], X[i]);
        permute(X, start + 1, n);
        swap(X[start], X[i]);
    }
}

int main()
{
    int n = 3;
    vector<int> X = {-1, 1, 2, 3};

    permute(X, 1, n);
    return 0;
}