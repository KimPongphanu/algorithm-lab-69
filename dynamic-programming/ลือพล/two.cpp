#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100, -1);

int G(int n)
{
    // G(0)
    memo[0] = 0;
    // G(1) || G(2)
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
    cout << G(n);
    return 0;
}