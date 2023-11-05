// 18_11399.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    int total = 0;
    vector<int> int_vec(N);

    for (int i = 0; i < int_vec.size(); i++)
    {
        cin >> int_vec[i];
    }

    // 삽입 정렬
    int i, j;
    for (i = 1; i < int_vec.size(); i++)
    {
        int key = int_vec[i];
        for (j = i; j > 0 && int_vec[j - 1] > key; j--)
        {
            int_vec[j] = int_vec[j - 1];
        }
        int_vec[j] = key;
    }

    for (int i = 0; i < int_vec.size(); i++)
    {
        sum += int_vec[i];
        total += sum;
    }
    cout << total << "\n";

    return 0;
}
