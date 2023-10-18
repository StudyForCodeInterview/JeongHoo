// 5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// 문제 이해 못함
#include <iostream>

#define MAX_COUNT 1000001
using namespace std;

unsigned long long sub_total_array[MAX_COUNT];
unsigned long long remainder_count_array[MAX_COUNT];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    
    unsigned long long answer = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        unsigned long long input_data;
        unsigned long long remainder;
        
        cin >> input_data;
        sub_total_array[i] = sub_total_array[i - 1] + input_data;

        remainder = sub_total_array[i] % M;

        if (remainder == 0)
        {
            answer++;
        }
        
        remainder_count_array[remainder]++;
    }
    
    for (int i = 0; i < M; i++)
    {
        if(remainder_count_array[i] > 1)
        answer += remainder_count_array[i] * (remainder_count_array[i] - 1) / 2;
    }

    cout << answer << "\n";

    return 0;
}
