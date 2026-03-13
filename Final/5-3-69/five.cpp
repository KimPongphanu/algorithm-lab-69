#include <iostream>
#include <vector>
#include <cmath>
const int INF = 1e6;
using namespace std;

int solve(vector<int> &X, int index, int sum, int k)
{
    if (sum == k)
    {
        return 0;
    }

    if (index == X.size() || sum > k)
    {
        return INF;
    }

    int exclude = solve(X, index + 1, sum, k);

    int include = 1 + solve(X, index + 1, sum + X[index], k);

    return min(exclude, include);
}

int main()
{
    int k = 8;
    vector<int> X = {2, 3, 5};
    int result = solve(X, 0, 0, k);
    if (result >= INF)
    {
        cout << "no solution\n";
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}