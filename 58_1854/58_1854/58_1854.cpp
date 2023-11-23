// 58_1854.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 요것은 아직 완성되지 않음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pd;
vector<vector<pd>> adj_vec;
vector<vector<int>> weight_vec;
vector<priority_queue<int>> dist_q;
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

    int n, m, k;

    cin >> n >> m >> k;

    adj_vec = vector<vector<pd>>(n + 1);
    weight_vec = vector<vector<int>>(n + 1);
    dist_q = vector<priority_queue<int>>(n + 1);
    for (int i = 1; i < weight_vec.size(); i++)
    {
        weight_vec[i] = vector<int>(k, INT32_MAX);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        adj_vec[a].push_back(pd(b, c));
    }

    int start = 1;
    weight_vec[1][0] = 0;
    priority_queue<pd, vector<pd>,cmp> start_q;
    start_q.push(pd(0, start));
    
    while (start_q.size())
    {
        int data = start_q.top().first;
        int index = start_q.top().second;

        start_q.pop();

        for (pd t_data : adj_vec[index])
        {
            int next_index = t_data.first;
            int next_weight = t_data.second;

            if (next_weight != 0)
            {
                if (dist_q[next_index].size() < k)
                {
                    dist_q[next_index].push(data + next_weight);
                    start_q.push(pd(data + next_weight, next_index));
                }
                else if( dist_q[next_index].top() > data + next_weight)
                {
                    dist_q[next_index].pop();
                    dist_q[next_index].push(data + next_weight);
                    start_q.push(pd(data + next_weight, next_index));
                }
            }
        }
    }

    for (int i = 1; i < dist_q.size(); i++)
    {
        if (dist_q[i].size() == k)
            cout << dist_q[i].top() << "\n";
        else
            cout << "-1\n";
    }


    return 0;
}

