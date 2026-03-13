#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // สำหรับ swap

using namespace std;

// เปลี่ยนเป็น vector<string> ให้ตรงกับข้อมูลที่รับมา
void permute(vector<string> &arr, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(arr[start], arr[i]);

        // --- เพิ่มเงื่อนไขเช็ก (Pruning) ---
        bool canGoDeeper = true;
        // ถ้าตำแหน่งที่เพิ่งวาง (start) กับตัวก่อนหน้า (start-1) เป็นผู้หญิงทั้งคู่
        if (start > 0)
        {
            if (arr[start][0] == 'G' && arr[start - 1][0] == 'G')
            {
                canGoDeeper = false;
            }
        }

        if (canGoDeeper)
        {
            permute(arr, start + 1, end);
        }
        // -------------------------------

        swap(arr[start], arr[i]); // Backtrack กลับคืน
    }
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // รับค่า เช่น B G G
    }

    permute(arr, 0, n - 1);

    return 0;
}