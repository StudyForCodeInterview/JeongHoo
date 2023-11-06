// 35_1931.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pd;

struct cmp
{
    bool operator()(pd a, pd b)
    {
        // second 작은 순서부터.
        if(a.second != b.second)
        return a.second > b.second;

        // second가 같다면 first가 작은 순서로
        return a.first > b.first;
    }
};

priority_queue<pd, vector<pd>, cmp> g_queue;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        pd data;
        cin >> data.first >> data.second;

        g_queue.push(data);
    }

    int meeting_count = 0;

    pd data = g_queue.top();
    int start_time = data.first;
    int end_time = data.second;
    while (g_queue.size() > 0)
    {
        data = g_queue.top();
        g_queue.pop();

        if (start_time > data.first)
            continue;

        end_time = data.second;
        meeting_count++;
        start_time = end_time;
    }

    cout << meeting_count << "\n";

    return 0;
}