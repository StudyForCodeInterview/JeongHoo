// 52_2252.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<queue<int>> g_graph;
vector<int> g_in_degree;
priority_queue<int> g_start_q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    g_graph = vector<queue<int>>(N + 1);
    g_in_degree = vector<int>(N + 1);
    int proc_count = 0;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        g_graph[a].push(b);
        g_in_degree[b]++;
    }
    
    for (int i = 1; i < g_in_degree.size(); i++)
    {
        if (g_in_degree[i] == 0)
        {
            g_start_q.push(i);
        }
    }

    while (g_start_q.size() > 0)
    {
        int data = g_start_q.top();

        g_start_q.pop();

        cout << data << "\n";
        
        while (g_graph[data].size() > 0)
        {
            int next_data = g_graph[data].front();

            g_graph[data].pop();

            g_in_degree[next_data]--;

            if (g_in_degree[next_data] == 0)
            {
                g_start_q.push(next_data);
            }
        }
    }

    return 0;
}