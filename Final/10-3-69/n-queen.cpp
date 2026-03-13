#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &X)
{
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = i + 1; j < X.size(); j++)
        {
            if (abs(i - j) == abs(X[i] - X[j]))
            {
                return false;
            }
        }
    }
    return true;
}

void permute(vector<int> &X, int index)
{
    if (X.size() == index)
    {
        if (isValid(X))
        {
            for (const auto &i : X)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    for (int i = index; i < X.size(); i++)
    {
        swap(X[index], X[i]);
        permute(X, index + 1);
        swap(X[index], X[i]);
    }
}

int main()
{

    vector<int> X = {-1, 1, 2, 3};

    permute(X, 0);
    return 0;
}