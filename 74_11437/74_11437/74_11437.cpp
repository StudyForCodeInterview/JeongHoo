// 74_11437.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pd;

vector<vector<int>> adj;
vector<bool> visit;

vector<pd> parent_tree;

vector<vector<int>> lca_tree;
int LCA(int a, int b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    adj = vector<vector<int>>(N + 1);
    visit = vector<bool>(N + 1, false);
    parent_tree = vector<pd>(N + 1);

    for (int i = 0; i < N - 1; i++)
    {
        int input_1, input_2;

        cin >> input_1 >> input_2;

        adj[input_1].push_back(input_2);
        adj[input_2].push_back(input_1);
    }

    queue<int> start_q;
    start_q.push(1);

    parent_tree[1] = pd(0, 0); // 부모 노드, 깊이 순서

    int depth = 0;

    while (start_q.size())
    {
        int front = start_q.front();
        start_q.pop();

        visit[front] = true;

        for (int i = 0; i < adj[front].size(); i++)
        {
            int next = adj[front][i];

            if (!visit[next])
            {
                depth = max(depth, parent_tree[front].second + 1);
                parent_tree[next] = pd(front, depth);
                start_q.push(next);
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int M_1, M_2;
        cin >> M_1 >> M_2;

        cout << LCA(M_1, M_2) << "\n";
    }

    return 0;
}

int LCA(int a, int b)
{
    int a_depth = parent_tree[a].second;
    int b_depth = parent_tree[b].second;

    // depth가 안맞으면 일단 맞춰준다.
    while (a_depth != b_depth)
    {
        if (a_depth > b_depth)
        {
            a = parent_tree[a].first;
            a_depth = parent_tree[a].second;
        }
        else
        {
            b = parent_tree[b].first;
            b_depth = parent_tree[b].second;
        }
    }

    while (a != b)
    {
        a = parent_tree[a].first;
        b = parent_tree[b].first;
    }

    return a;
}