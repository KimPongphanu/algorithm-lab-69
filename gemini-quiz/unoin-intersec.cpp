#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n = 5;
    // cin >> n;
    // vector<int> A(n);
    // vector<int> B(n);
    vector<int> A = {6, 8, 7, 4, 1};
    vector<int> B = {3, 2, 7, 1, 2};
    vector<int> C;

    pair<bool, int> memo = {false, 0};

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> A[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> B[i];
    // }

    for (int i = 0; i < n; i++)
    {
        C.push_back(A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C.push_back(B[i]);
    }

    for (int i = 0; i < C.size(); i++)
    {
        cout << C[i] << " ";
    }

    return 0;
}