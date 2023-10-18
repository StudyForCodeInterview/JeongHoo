#include <iostream>
#include <queue>

using namespace std;

queue<int> data_queue;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        data_queue.push(i);
    }

    while (data_queue.size() > 1)
    {
        data_queue.pop();
        
        int front_data = data_queue.front();
        
        data_queue.pop();
        data_queue.push(front_data);
    }
    cout << data_queue.front();

    return 0;
}
