// 55_1948.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#define pd pair<int,int>
using namespace std;
vector<vector<pd>> city;
vector<vector<pd>> rev_city;
vector<int> g_in_degree;


vector<bool> visited;
vector<int> max_time;
int g_count;
void DFS(int data);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 도시의 개수 , 도로의 개수
    cin >> N >> M;

    city = vector<vector<pd>>(N + 1);
    rev_city = vector<vector<pd>>(N + 1);
    g_in_degree = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);
    max_time = vector<int>(N + 1,0);

    for (int i = 0; i < M; i++)
    {
        int start, end, time;

        cin >> start >> end >> time;

        city[start].push_back(pd(end, time));
        rev_city[end].push_back(pd(start, time));
        g_in_degree[end]++;
    }

    int start_city, end_city;
    cin >> start_city >> end_city;

    queue<int> start_q;

    start_q.push(start_city);

    while (start_q.size() > 0)
    {
        int data = start_q.front();
        start_q.pop();

        for (int i = 0; i < city[data].size(); i++)
        {
            pd t_data = city[data][i];
            g_in_degree[t_data.first]--;

            max_time[t_data.first] = max(max_time[t_data.first], max_time[data] + t_data.second);
            if (g_in_degree[t_data.first] == 0)
            {
                start_q.push(t_data.first);
            }
        }
    }
    DFS(end_city);

    cout << max_time[end_city] << " " << g_count << "\n";
    return 0;
}

void DFS(int data)
{
    //visited[data] = true;
    visited[data] = true;

    for (int i = 0; i < rev_city[data].size(); i++)
    {
        pd t_data = rev_city[data][i];
        if (max_time[t_data.first] == max_time[data] - t_data.second)
        {
            if (!visited[t_data.first])
                DFS(t_data.first);
            g_count++;
        }
    }
}