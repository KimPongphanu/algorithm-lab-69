#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int v;
    int w;
};

int solve(const vector<item> &arr, int index, int current_v, int current_w, int k)
{
    if (index == arr.size())
    {
        return current_v;
    }

    int exclude = solve(arr, index + 1, current_v, current_w, k);

    int include = -1;
    if (current_w + arr[index].w <= k)
    {
        include = solve(arr, index + 1, current_v + arr[index].v, current_w + arr[index].w, k);
    }

    return max(exclude, include);
}

int main()
{
    int k = 18;
    vector<item> items = {{12, 8}, {5, 7}, {4, 4}, {2, 2}};
    cout << solve(items, 0, 0, 0, k);
    return 0;
}