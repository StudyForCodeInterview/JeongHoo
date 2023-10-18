// 12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> data_stack;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> seq_vec(N);
    vector<int> nge_vec(N, -1);

    for (int i = 0; i < N; i++)
    {
        cin >> seq_vec[i];
    }
    
    for (int i = N - 1; i >= 0; i--)
    {
        while (data_stack.size() > 0)
        {
            if (data_stack.top() > seq_vec[i])
            {
                nge_vec[i] = data_stack.top();
                break;
            }
            else
            {
                data_stack.pop();
            }
        }
        data_stack.push(seq_vec[i]);
    }

    for (int i = 0; i < N; i++)
    {
        cout << nge_vec[i] << " ";
    }
    return 0;
}
