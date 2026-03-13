#include <iostream>
#include <vector>

using namespace std;

struct Player
{
    int id;
    int h;
    int m;
};

class Sort
{
private:
    void merge(vector<Player> &arr, int l, int mid, int r)
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
            arr[k++] = leftArr[i++];
        while (j < n2)
            arr[k++] = rightArr[j++];
    }

public:
    void merge_sort(vector<Player> &arr, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
};

bool binary_search(vector<Player> &arr, int l, int r, int key, vector<Player> &foundPlayer)
{
    if (l > r)
        return false;

    int mid = l + (r - l) / 2;

    if (arr[mid].id == key && arr[mid].h > -1 && arr[mid].m > -1 && arr[mid].h <= 6)
    {
        if (arr[mid].h == 6 && arr[mid].m == 0)
        { // Spacial Case
            foundPlayer.push_back(arr[mid]);
        }
        else if (arr[mid].h < 6)
        {
            foundPlayer.push_back(arr[mid]);
        }
        return true;
    }

    if (arr[mid].id < key)
    {
        return binary_search(arr, mid + 1, r, key, foundPlayer);
    }
    else
    {
        return binary_search(arr, l, mid - 1, key, foundPlayer);
    }

    return false;
}

int main()
{
    Sort s;
    int k;
    if (!(cin >> k))
        return 0;
    if (k < 0 || k > 100)
        return 0;

    vector<int> bobby_friends(k);
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0 || temp > 1000000)
            return 0;
        bobby_friends[i] = temp;
    }
    // บรรทัด 3
    int n;
    if (!(cin >> n))
        return 0;
    if (n < k || n > 1000)
        return 0;

    vector<Player> rawData(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> rawData[i].id >> rawData[i].h >> rawData[i].m;
        if (rawData[i].id < k || rawData[i].id > 1000 || rawData[i].h > 23 || rawData[i].m > 59 || rawData[i].h < -1 || rawData[i].m < -1)
            return 0;
    }
    s.merge_sort(rawData, 0, rawData.size() - 1);

    vector<Player> foundPlayer;
    int pass = 0;
    int topPlayer = 0;
    for (int i = 0; i < k; i++)
    {
        int search_player = binary_search(rawData, 0, rawData.size() - 1, bobby_friends[i], foundPlayer);
        if (search_player)
        {
            pass++;
        }
    }

    for (int i = 0; i < foundPlayer.size() - 1; i++)
    {
        if (foundPlayer[i].h < foundPlayer[i + 1].h)
        {
            topPlayer = foundPlayer[i].id;
        }
        else if (foundPlayer[i].h == foundPlayer[i + 1].h)
        {
            if (foundPlayer[i].m < foundPlayer[i + 1].m)
            {
                topPlayer = foundPlayer[i].id;
            }
        }
    }

    cout << topPlayer << " " << pass << endl;
    return 0;
}
