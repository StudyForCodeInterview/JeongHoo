// 6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int start_index = 1;
    int end_index = 1;
    int sum = 1;
    int answer = 1;

    while (end_index < N)
    {
        if (sum < N)
        {
            sum += ++end_index;
        }
        else if (sum > N) 
        {
            sum -= start_index++;
        }
        else // sum == N
        { 
            sum += ++end_index;
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}