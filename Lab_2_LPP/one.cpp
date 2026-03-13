#include <iostream>
#include <vector>

using namespace std;

void shell_sort_sedgewick(vector<int> &arr)
{
    int n = arr.size();
    vector<int> gaps = {5, 3, 2, 1};

    for (int g = 0; g < gaps.size(); g++)
    {
        int gap = gaps[g];
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    shell_sort_sedgewick(array);
    return 0;
}