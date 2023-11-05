// 26_1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
void DFS(vector<vector<int>>& dfs_vec, int count, vector<bool>& visit_vec);
//void BFS(vector<queue<int>>& dfs_vec, int count, vector<bool>& visit_vec);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<bool> visit_vec(N+1);
    vector<vector<int>> dfs_vec(N+1);
    //vector<queue<int>>bfs_vec(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        dfs_vec[a].push_back(b); 
        dfs_vec[b].push_back(a);

        //bfs_vec[a].push(b);
        //bfs_vec[b].push(a);
    }

    queue<int> main_queue;

    for (vector<vector<int>>::iterator iter = dfs_vec.begin(); iter != dfs_vec.end(); iter++)
    {
        sort(iter->begin(), iter->end());
    }
    DFS(dfs_vec, V, visit_vec);
    cout << "\n";

    fill(visit_vec.begin(), visit_vec.end(), false);

    main_queue.push(V);

    while (main_queue.size() > 0)
    {
        int data = main_queue.front();
        main_queue.pop();

        if (visit_vec[data])
            continue;

        visit_vec[data] = true;
        cout << data << " ";

        for (int i = 0; i < dfs_vec[data].size(); i++)
        {
            main_queue.push(dfs_vec[data][i]);
        }
    }
    cout << "\n";

    return 0;
}
void DFS(vector<vector<int>>& dfs_vec, int count, vector<bool>& visit_vec)
{
    //if (visit_vec[count])
    //    return;

    visit_vec[count] = true;
    cout << count << " ";


    for(int i=0;i<dfs_vec[count].size();i++)
    {
        int data_idx = dfs_vec[count][i];

        if(!visit_vec[data_idx])
        DFS(dfs_vec, data_idx, visit_vec);
    }
}
