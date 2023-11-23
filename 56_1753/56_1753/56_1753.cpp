// 56_1753.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int64_t, int64_t> pd;
vector<vector<pd>> adj_matrix;
vector<int64_t> val_vec;
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

    int V, E;
    cin >> V >> E;
    int K; // start
    cin >> K;

    adj_matrix = vector<vector<pd>>(V + 1);
    val_vec = vector<int64_t>(V + 1, INT64_MAX);
    visited = vector<bool>(V + 1, false);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;

        cin >> u >> v >> w;

        adj_matrix[u].push_back(pd(v, w));
    }

    val_vec[K] = 0;
    priority_queue<pd,vector<pd>,cmp> start_q;
    
    start_q.push(pd(0,K));

    while (start_q.size())
    {
        pd data = start_q.top();
        start_q.pop();

        if (visited[data.second])
            continue;

        visited[data.second] = true;

        for (pd adj_data : adj_matrix[data.second])
        {
            if (adj_data.second + val_vec[data.second] < val_vec[adj_data.first])
            {
                val_vec[adj_data.first] = adj_data.second + val_vec[data.second];

                start_q.push(pd(val_vec[adj_data.first], adj_data.first));
            }
        }
    }

    for (int i = 1; i < val_vec.size(); i++)
    {
        if (val_vec[i] == INT64_MAX)
            cout << "INF\n";
        else
        {
            cout << val_vec[i] << "\n";
        }
    }

    return 0;
}
