#include <iostream>
#include <vector>

using namespace std;

void deleteDuplicate(vector<int> &arr, vector<int> &output)
{

    for (int i = 0; i < arr.size(); i++)
    {
        bool used = false;
        for (int j = 0; j < output.size(); j++)
        {
            if (output[j] == arr[i])
            {
                used = true;
                break;
            }
        }
        if (!used)
        {
            output.push_back(arr[i]);
        }
    }
}

int main()
{
    int n = 5;
    // cin >> n;
    vector<int> A = {6, 8, 7, 4, 1};
    vector<int> B = {3, 2, 7, 1, 2};

    vector<int> rawInter, rawUnion;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                rawInter.push_back(A[i]);
                break;
            }
        }
    }

    for (int x : A)
    {
        rawUnion.push_back(x);
    }
    for (int x : B)
    {
        rawUnion.push_back(x);
    }

    vector<int> intersecArr, unionArr;
    deleteDuplicate(rawInter, intersecArr);
    deleteDuplicate(rawUnion, unionArr);

    for (int i : intersecArr)
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