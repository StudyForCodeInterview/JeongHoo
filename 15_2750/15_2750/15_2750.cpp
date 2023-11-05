// 15_2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int>& arr, int len);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> num_arr(N);

    for (int i = 0; i < num_arr.size(); i++)
    {
        cin >> num_arr[i];
    }
    Sort(num_arr, num_arr.size());
    for (int i = 0; i < num_arr.size(); i++)
    {
        cout << num_arr[i] << "\n";
    }
    return 0;
}
void Sort(vector<int>& arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}
