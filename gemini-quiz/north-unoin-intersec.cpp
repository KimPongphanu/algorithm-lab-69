#include <iostream>
#include <vector>
using namespace std;

void process(vector<int> a, vector<int> b, int max_ab, int n)
{
    vector<int> check(max_ab + 1, 0);
    vector<int> uni;
    vector<int> inter;

    for (int i = 0; i < n; i++)
    {
        check[a[i]] += 1;
        if (check[a[i]] <= 1)
        {
            uni.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (check[b[i]] == 1)
        {
            inter.push_back(b[i]);
        }
        else if (check[b[i]] <= 1)
        {
            check[b[i]] += 1;
            uni.push_back(b[i]);
        }
    }
    cout << "Intersect : ";
    for (int i = 0; i < inter.size(); i++)
    {
        cout << inter[i] << " ";
    }
    cout << endl;
    cout << "Union : ";
    for (int i = 0; i < uni.size(); i++)
    {
        cout << uni[i] << " ";
    }
}

int main()
{
    int n, max_ab = 0;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (max_ab < a[i])
        {
            max_ab = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (max_ab < b[i])
        {
            max_ab = b[i];
        }
    }

    process(a, b, max_ab, n);

    return 0;
}