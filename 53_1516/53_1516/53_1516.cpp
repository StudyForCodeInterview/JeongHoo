// 53_1516.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> g_graph;
vector<int> g_in_degree;
vector<int> g_each_time;
vector<int> g_min_time;
struct cmp
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    g_graph = vector<vector<int>>(N + 1);
    g_in_degree = vector<int>(N + 1, 0);
    g_min_time = vector<int>(N + 1, 0);
    g_each_time = vector<int>(N + 1);
    for (int i = 1; i < g_in_degree.size(); i++)
    {
        int time,need;
        cin >> time;
        g_each_time[i] = time;
        while (1)
        {
            cin >> need;
            if (need == -1)
                break;
            
            g_in_degree[i]++;
            g_graph[need].push_back(i);
        }
    }

    queue<int> start_q;
    for (int i = 1; i < g_in_degree.size(); i++)
    {
        if (g_in_degree[i] == 0)
        {
            start_q.push(i);
            g_min_time[i] = g_each_time[i];
        }
    }

    while (start_q.size() > 0)
    {
        int data = start_q.front();
        
        start_q.pop();
        for (int next_data : g_graph[data])
        {
            g_in_degree[next_data]--;

            g_min_time[next_data] = max(g_min_time[next_data], g_min_time[data] + g_each_time[next_data]);
            if (g_in_degree[next_data] == 0)
            {
                start_q.push(next_data);
            }
        }
    }

    for (int i = 1; i < g_in_degree.size(); i++)
    {
        cout << g_min_time[i] << "\n";
    }

    return 0;
}
// 너무 어렵다