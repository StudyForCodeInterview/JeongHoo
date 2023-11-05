// 33_1715.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comp
{
    bool operator() (int a, int b)
    {
        return a > b;
    }
};
priority_queue<int,vector<int>, comp> data_queue;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        data_queue.push(data);
    }

    int sum = 0;

    while (data_queue.size() > 1)
    {
        int data1 = data_queue.top();
        data_queue.pop();
        int data2 = data_queue.top();
        data_queue.pop();

        sum += data1 + data2;

        data_queue.push(data1 + data2);
    }  

    cout << sum << "\n";
    return 0;
}