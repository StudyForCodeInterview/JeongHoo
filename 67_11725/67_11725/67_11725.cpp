// 67_11725.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visit;
vector<vector<int>> way;
vector<int> parent;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    visit = vector<bool>(N + 1, false);
    way = vector<vector<int>>(N + 1);
  
    parent = vector<int>(N + 1);

    for (int i = 1; i < N; i++)
    {
        int src, dst;
       
        cin >> src >> dst;

        way[src].push_back(dst);
        way[dst].push_back(src);
    }

    queue<int> start_q;
    start_q.push(1);

    while (start_q.size())
    {
        int data = start_q.front();

        start_q.pop();

        visit[data] = true;

        for (int i = 0; i < way[data].size(); i++)
        {
            int next = way[data][i];
            if (!visit[next])
            {
                parent[next] = data;
                start_q.push(next);
            }
        }
    }

    for (int i = 2; i < parent.size(); i++)
    {
        cout << parent[i] << "\n";
    }

    return 0;
}
