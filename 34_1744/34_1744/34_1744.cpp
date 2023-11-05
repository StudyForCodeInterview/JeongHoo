// 34_1744.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > negative_q;
priority_queue<int, vector<int>, less<int>> positive_q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int max_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;

        if (data <= 0)
            negative_q.push(data);
        else if(data > 1)
            positive_q.push(data);
        else
        {
            max_cnt++;
        }
    }

    while (positive_q.size() > 1)
    {
        int data_1 = positive_q.top();
        positive_q.pop();
        int data_2 = positive_q.top();
        positive_q.pop();

        max_cnt += data_1 * data_2;
    }
    
    if (positive_q.size() > 0)
    {
        max_cnt += positive_q.top();
        positive_q.pop();
    }

    while(negative_q.size() > 1)
    {
        int data_1 = negative_q.top();
        negative_q.pop();
        int data_2 = negative_q.top();
        negative_q.pop();

        max_cnt += data_1 * data_2;
    }

    if (negative_q.size() > 0)
    {
        max_cnt += negative_q.top();
        negative_q.pop();
    }

    cout << max_cnt << "\n";
    return 0;
}
