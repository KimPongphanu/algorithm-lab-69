#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(101, -1);

int G(int n)
{
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2] - memo[i - 3];
    }

    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    if (n < 2 || n > 1000)
    {
        return 0;
    }

    cout << G(n);
    return 0;
}