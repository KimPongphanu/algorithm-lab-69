#include <iostream>
#include <vector>

using namespace std;

struct Player
{
    int id = 0;
    int h = 0;
    int m = 0;
};

class Sort
{
private:
    void merge(vector<int> &arr, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0,
            j = 0,
            k = l;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] < rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void merge_player(vector<Player> &arr, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<Player> leftArr(n1);
        vector<Player> rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0,
            j = 0,
            k = l;
        while (i < n1 && j < n2)
        {
            if (leftArr[i].id < rightArr[j].id)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void merge_min_time(vector<Player> &arr, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<Player> leftArr(n1);
        vector<Player> rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            bool isLeft = false;

            if (leftArr[i].h >= 0 && rightArr[j].h >= 0 && leftArr[i].h < rightArr[j].h)
            {
                isLeft = true;
            }
            else if (leftArr[i].h >= 0 && rightArr[j].h >= 0 && leftArr[i].h == rightArr[j].h)
            {
                if (leftArr[i].m >= 0 && rightArr[j].m >= 0 && leftArr[i].m < rightArr[j].m)
                {
                    isLeft = true;
                }
            }

            if (isLeft)
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }

            k++;
        }

        while (i < n1)
        {
            arr[k++] = leftArr[i++];
        }

        while (j < n2)
        {
            arr[k++] = rightArr[j++];
        }
    }

public:
    void merge_sort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            merge_sort(arr, l, mid);
            merge_sort(arr, mid + 1, r);

            merge(arr, l, mid, r);
        }
    }

    void merge_sort_player(vector<Player> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            merge_sort_player(arr, l, mid);
            merge_sort_player(arr, mid + 1, r);

            merge_player(arr, l, mid, r);
        }
    }

    void merge_sort_min_time(vector<Player> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            merge_sort_min_time(arr, l, mid);
            merge_sort_min_time(arr, mid + 1, r);

            merge_min_time(arr, l, mid, r);
        }
    }
};

class Search
{
public:
    bool binary_search_Player(vector<Player> &arr, vector<Player> &foundArr, int l, int r, int key)
    {
        if (l > r)
            return false;
        int mid = l + (r - l) / 2;
        if (arr[mid].id == key)
        {
            if (arr[mid].h <= 6 && arr[mid].h >= 0)
            {
                foundArr.push_back(arr[mid]);
                return true;
            }
        }

        if (arr[mid].id < key)
        {
            return binary_search_Player(arr, foundArr, mid + 1, r, key);
        }
        else
        {
            return binary_search_Player(arr, foundArr, l, mid - 1, key);
        }
        return false;
    }
};

void driver()
{
    Sort sort;
    Search search;
    unsigned short t; // <=10 cases
    if (!(cin >> t))
        return;
    if (t < 1 || t > 10)
        return;
    int k; // 1 < k <= 100 players
    vector<int> bobby_friends(t);
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        if (k > 1000000)
            return;
        bobby_friends[i] = k;
    }
    sort.merge_sort(bobby_friends, 0, bobby_friends.size() - 1);
    int n;
    if (!(cin >> n))
        return;
    vector<Player> rawData(n);
    for (int i = 0; i < n; i++)
    {
        if (!(cin >> rawData[i].id >> rawData[i].h >> rawData[i].m))
            break;
        if (rawData[i].id > 1000000 || rawData[i].h > 23 || rawData[i].m > 59)
            break;
    }
    sort.merge_sort_player(rawData, 0, rawData.size() - 1);
    vector<Player> FoundArr;
    int topScore = 0, pass = 0;
    for (int i = 0; i < bobby_friends.size(); i++)
    {
        bool x = search.binary_search_Player(rawData, FoundArr, 0, rawData.size() - 1, bobby_friends.at(i));
        if (x == true)
        {
            pass++;
        }
    }
    if (!FoundArr.empty())
    {
        sort.merge_sort_min_time(FoundArr, 0, FoundArr.size() - 1);
        topScore = FoundArr.front().id;
    }
    else
    {
        topScore = -1;
    }

    cout
        << topScore << " " << pass << endl;
}

int main()
{

    driver();
    return 0;
}
