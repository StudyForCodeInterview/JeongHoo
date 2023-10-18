// 11.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> data_stack;
queue<char> op_queue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 스택 푸쉬 값
    int push_data = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        // 입력 값
        int input_data;
        cin >> input_data;

        while (push_data < input_data)
        {
            data_stack.push(++push_data);
            op_queue.push('+');
        }

        if (data_stack.top() == input_data)
        {
            data_stack.pop();
            op_queue.push('-');
        }
    }


    if (!data_stack.empty())
    {
        cout << "NO" << "\n";
    }
    else 
    {
        while (!op_queue.empty())
        {
            cout << op_queue.front() << "\n";
            op_queue.pop();
        }
    }

    return 0;

}
