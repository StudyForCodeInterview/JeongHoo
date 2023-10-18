// 10.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>

using namespace std;
deque<pair<int, int>> deq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    int input_data;
    int i = 0;
    int win_start_index = -L +1;
    
    while (i < N)
    {
        cin >> input_data;

        // 앞에서 걸러주기
        if (deq.size() > 0 && deq.front().first < win_start_index)
            deq.pop_front();

        // 뒤에서 걸러주기
        while (deq.size() > 0 && deq.back().second > input_data)
            deq.pop_back();

        deq.push_back(pair<int, int>(i, input_data));

        cout << deq.front().second << " ";

        win_start_index++;
        i++;

    }

    return 0;
}
