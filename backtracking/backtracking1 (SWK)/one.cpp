#include <iostream>
#include <vector>

using namespace std;
int count = 0;
void permutation(vector<int> &data, vector<int> &currents, vector<bool> &used)
{
    if (currents.size() == data.size())
    {
        for (int i = 0; i < currents.size() - 1; i++)
        {
            if (currents[i] == 1 && currents[i + 1] == 2 || currents[i] == 2 && currents[i + 1] == 1)
            {
                count++;
                break;
            }
        }
        return;
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            currents.push_back(data[i]);
            permutation(data, currents, used);
            currents.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    vector<int> currents;
    vector<bool> used(data.size(), false);
    for (int i = 1; i <= n; i++)
    {
        data[i - 1] = i;
    }
    permutation(data, currents, used);
    cout << count;
    return 0;
}