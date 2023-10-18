// 8.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2000

long long num_array[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num_array[i];
    }

    sort(num_array, num_array + N);

    int target_num;
    for (int i = 0; i < N; i++)
    {
        int start_index = 0;
        int end_index = N - 1;

        target_num = num_array[i];

        while (start_index < end_index)
        {
            if (i == start_index)
            {
                start_index++;
                continue;
            }

            else if (i == end_index)
            {
                end_index--;
                continue;
            }

            int sum_ = num_array[start_index] + num_array[end_index];

            if (sum_ == target_num)
            {
                answer++;

                break;
            }
            else if (sum_ > target_num)
            {
                end_index--;
            }
            else
            {
                start_index++;
            }
        }
    }
    cout << answer << "\n";
}