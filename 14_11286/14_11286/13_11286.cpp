// 14_11286.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <queue>
using namespace std;

// a > b이면 오름차순. 모르면 외워
// 우선 순위 큐 구현, 활용 공부 필요
struct PriorityQueueCompareStruct
{
    bool operator()(int a, int b)
    {
        int abs_a = abs(a);
        int abs_b = abs(b);
        if (abs_a != abs_b)
        {
            return abs_a > abs_b;
        }
        else
        {
            return a > b;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, PriorityQueueCompareStruct> pri_queue;


    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        if (data > 0)
        {
            pri_queue.push(data);
        }
        else if(data < 0)
        {
            pri_queue.push(data);
        }
        else // data == 0
        {
            if (pri_queue.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pri_queue.top()<< "\n";
                pri_queue.pop();
            }
        }
    }
    return 0;
}
