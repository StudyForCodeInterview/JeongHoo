// 57_1916.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pd;
vector<vector<pd>> adj_vec;
vector<int> weight_vec;
vector<bool> visited;

struct cmp
{
    bool operator()(pd a, pd b)
    {
        return a.first > b.first;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    adj_vec = vector<vector<pd>>(N + 1);
    weight_vec = vector<int>(N + 1,INT32_MAX);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
     
        cin >> u >> v >> w;

        adj_vec[u].push_back(pd(v,w));
    }
 
    int start, end;
    cin >> start >> end;

    priority_queue<pd, vector<pd>,cmp> start_q;

    start_q.push(pd(0, start));

    weight_vec[start] = 0;

    while (start_q.size())
    {
        int weight = start_q.top().first;
        int index = start_q.top().second;

        start_q.pop();

        if (visited[index])
        {
            if (index == end)
                break;

            continue;
        }
        visited[index] = true;

        for (pd t_data : adj_vec[index])
        {
            int next_index = t_data.first;
            int next_weight = t_data.second;

            if (weight_vec[next_index] > weight_vec[index] + next_weight)
            {
                weight_vec[next_index] = weight_vec[index] + next_weight;
                
                start_q.push(pd(weight_vec[next_index], next_index));
            }
        }
    }

    cout << weight_vec[end] << "\n";
    return 0;
}
