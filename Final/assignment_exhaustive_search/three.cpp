#include <iostream>
#include <vector>

using namespace std;

struct input
{
    vector<int> v;
    vector<int> w;
};

int findMaxValue(input &in, int k, int index, int current_w)
{
    if (index == in.v.size())
    {
        return 0;
    }

    // no case
    int exclude_val = findMaxValue(in, k, index + 1, current_w);

    // yes case
    int include_val = 0;
    if (current_w + in.w[index] <= k)
    {
        include_val = in.v[index] + findMaxValue(in, k, index + 1, current_w + in.w[index]);
    }

    return max(exclude_val, include_val);
}

int main()
{
    int n = 5, k;
    if (!(cin >> k))
        return 0;
    input in;
    int v_input, w_input;
    for (int i = 0; i < n - 1; i++)
    {

        cin >> v_input;
        in.v.push_back(v_input);
    }
    for (int i = 0; i < n - 1; i++)
    {

        cin >> w_input;

        in.w.push_back(w_input);
    }
    cout << findMaxValue(in, k, 0, 0);
    return 0;
}