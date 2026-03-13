#include <iostream>
#include <vector>
using namespace std;

class Search
{
private:
    vector<int> array = {10, 25, 32, 45, 50, 68, 72, 85, 91, 100};
    int key = 11;

public:
    int size()
    {
        return array.size();
    }

    int binary_search_recursive(int l, int r)
    {
        if (l > r)
        {
            return -1;
        }

        int mid = l + (r - l) / 2;
        if (array[mid] == key)
        {
            return mid;
        }

        if (array[mid] < key)
        {
            return binary_search_recursive(mid + 1, r);
        }
        else
        {
            return binary_search_recursive(l, mid - 1);
        }
        return -1;
    }

    int binary_search()
    {
        int l = 0;
        int r = size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (array[mid] == key)
            {
                return mid;
            }

            if (array[mid] < key)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }

    int sequential_search()
    {
        for (int i = 0; i < size(); i++)
        {
            if (array[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    int interpolation_search_recursive(int l, int r)
    {
        if (l > r && key < array[l] && key > array[r])
        {
            return -1;
        }

        int mid = l + (((double)(r - l) / (array[r] - array[l])) * (key - array[l]));
        if (array[mid] == key)
        {
            return mid;
        }

        if (array[mid] < key)
        {
            return interpolation_search_recursive(mid + 1, r);
        }
        else
        {
            return interpolation_search_recursive(l, mid - 1);
        }

        return -1;
    }

    int interpolation_search()
    {
        int l = 0;
        int r = size() - 1;

        while (l <= r && key >= array[l] && key <= array[r])
        {
            if (array[l] == array[r])
            {
                return (array[l] == key) ? l : -1;
            }
            int mid = l + (((double)(r - l) / (array[r] - array[l])) * (key - array[l]));

            if (array[mid] == key)
            {
                return mid;
            }

            if (array[mid] < key)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Search search;
    cout << search.binary_search_recursive(0, search.size() - 1);
    return 0;
}
