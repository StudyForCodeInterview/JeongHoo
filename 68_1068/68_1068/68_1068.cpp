// 68_1068.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visit;
vector<int> parent;
vector<vector<int>> way;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    visit = vector<bool>(N, false);
    way = vector<vector<int>>(N);
    int start_node = 0;
    
    for (int i = 0; i < N; i++)
    {
        int parent_data;
        cin >> parent_data;

        parent.push_back(parent_data);
        
        if (parent_data == -1)
            start_node = i;
        else
        {
            way[parent_data].push_back(i);
        }
    }
    
    int delete_node;
    cin >> delete_node;

    visit[delete_node] = true;
    queue<int> start_q;
    start_q.push(start_node);
    
    int leaf_cnt = 0;

    while (start_q.size())
    {
        int front = start_q.front();
        start_q.pop();

        if (visit[front])
            continue;

        visit[front] = true;

        if (way[front].size() == 0 )
            leaf_cnt++;
        else if(way[front].size() == 1 && way[front][0] == delete_node)
            leaf_cnt++;

        for (int i = 0; i < way[front].size(); i++)
        {
            int next = way[front][i];
            if (!visit[next])
            {
                start_q.push(next);
            }
        }
    }

    cout << leaf_cnt << "\n";
    return 0;
}
