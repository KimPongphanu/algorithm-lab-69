#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class backtracking
{
private:
    void one(vector<int> &A, int idx)
    {
        if (idx == A.size())
        {
            for (int i = 0; i < A.size() - 1; i++)
            {
                if ((A[i] == 1 && A[i + 1] == 2) || (A[i] == 2 && A[i + 1] == 1))
                {
                    for (const auto &item : A)
                    {
                        cout << item << " ";
                    }
                    cout << endl;
                }
            }
        }

        for (int i = idx; i < A.size(); i++)
        {
            swap(A[i], A[idx]);
            one(A, idx + 1);
            swap(A[i], A[idx]);
        }
    }

    void two(vector<int> &A, int k, int idx, int sum, vector<int> &currents)
    {

        if (sum == k)
        {
            for (const auto &item : currents)
            {
                cout << item << " ";
            }
            cout << endl;
            return;
        }

        if (idx == A.size() || sum > k)
        {
            return;
        }

        currents.push_back(A[idx]);
        two(A, k, idx + 1, sum + A[idx], currents);
        currents.pop_back();

        two(A, k, idx + 1, sum, currents);
    }

    int three(vector<pair<int, int>> &A, int k, int idx, int currentV, int currentW)
    {
        if (k == currentW)
        {
            return currentV;
        }

        if (currentW > k)
        {
            return -1e3;
        }

        if (idx == A.size())
        {
            return 0;
        }

        int select = A[idx].first + three(A, k, idx + 1, currentV + A[idx].first, currentW + A[idx].second);
        int noSelect = three(A, k, idx + 1, currentV, currentW);

        return max(select, noSelect);
    }

    void four(vector<int> &A, int index)
    {
        if (index == A.size())
        {
            bool isValid = true;
            for (int i = 0; i < A.size(); i++)
            {
                for (int j = i + 1; j < A.size(); j++)
                {
                    if (abs(i - j) == abs(A[i] - A[j]))
                    {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid)
                {
                    break;
                }
            }
            if (isValid)
            {
                for (const auto &item : A)
                {
                    cout << item << " ";
                }
                cout << endl;
            }
            return;
        }

        for (int i = index; i < A.size(); i++)
        {
            swap(A[i], A[index]);
            four(A, index + 1);
            swap(A[i], A[index]);
        }
    }

    int five(vector<int> &A, int k, int index, int sum, int count)
    {
        if (sum == k)
        {
            return 0;
        }
        if (index == A.size() || sum > k)
        {
            return 1e3;
        }

        int noSelect = five(A, k, index + 1, sum, count);

        int select = 1e3;
        if (k >= sum + A[index])
        {
            select = 1 + five(A, k, index + 1, sum + A[index], count);
        }

        return min(select, noSelect);
    }

    void six(vector<char> &A, int index, vector<char> &currents, vector<bool> &used)
    {
        if (index == A.size())
        {
            for (const auto &item : currents)
            {
                cout << item << "";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < A.size(); i++)
        {
            if (!used[i])
            {
                used[i] = true;
                currents.push_back(A[i]);
                six(A, index + 1, currents, used);
                currents.pop_back();
                used[i] = false;
            }
        }
    }

public:
    void oneDriver()
    {
        int n;
        cin >> n;
        if (n < 2 || n > 10)
        {
            return;
        }
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            A[i] = i + 1;
        }
        one(A, 0);
        return;
    }
    void twoDriver()
    {
        int n, k;
        cin >> n >> k;
        if ((n < 0 || n > 100) || (k < 0 || k > 100))
        {
            return;
        }
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<int> currents;
        two(A, k, 0, 0, currents);
        return;
    }

    void threeDriver()
    {
        int n, k;
        cin >> n >> k;
        if ((n < 1 || n > 100) || (k < 1 || k > 100))
        {
            return;
        }
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> A[i].second;
        }

        cout << three(A, k, 0, 0, 0);
        return;
    }

    void fourDriver()
    {
        int n;
        cin >> n;
        if (n < 3 || n > 8)
        {
            return;
        }
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            A[i] = i + 1;
        }

        four(A, 0);
        return;
    }
    void fiveDriver()
    {
        int k;
        cin >> k;
        vector<int> A(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> A[i];
        }
        int count;
        cout << five(A, k, 0, 0, count);
        return;
    }
    void sixDriver()
    {
        int n;
        cin >> n;
        vector<char> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            A[i] = toupper(A[i]);
        }
        sort(A.begin(), A.end());
        vector<char> currents;
        vector<bool> used(n, false);
        six(A, 0, currents, used);
        return;
    }
};

int main()
{
    backtracking bt;
    // bt.oneDriver();
    // bt.twoDriver();
    // bt.threeDriver();
    // bt.fourDriver();
    // bt.fiveDriver();
    // bt.sixDriver();
    return 0;
}