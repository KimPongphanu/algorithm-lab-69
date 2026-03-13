#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    if (n < 1 || n > 100)
        return 0;
    vector<bool> A(101, false);
    vector<bool> B(101, false);

    // A
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 1)
            return 0;
        A[temp] = true;
    }

    // B
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 1)
            return 0;
        B[temp] = true;
    }

    vector<int> intersectionArr;
    vector<int> unionArr;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] && B[i])
        {
            intersectionArr.push_back(i);
            unionArr.push_back(i);
        }
        else if (A[i] || B[i])
        {
            unionArr.push_back(i);
        }
    }

    for (int i : intersectionArr)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i : unionArr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}