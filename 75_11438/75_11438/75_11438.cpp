// 75_11438.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
int lca_size;

int LCA(int a, int b);

int Pow(int a, int b);

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

    // lca_size -1 == 최대 길이
    while (depth)
    {
        depth /= 2;
        lca_size++;
    }
    lca_tree = vector<vector<int>>(lca_size);

    for (int i = 0; i < lca_tree.size(); i++)
    {
        lca_tree[i] = vector<int>(N + 1, 0);
        if (i == 0)
        {
            for (int j = 0; j < parent_tree.size(); j++)
                lca_tree[i][j] = parent_tree[j].first;
        }
        else
        {
            for (int j = 0; j < parent_tree.size(); j++)
                lca_tree[i][j] = lca_tree[i - 1][lca_tree[i - 1][j]];
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
    if (parent_tree[a].second > parent_tree[b].second)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int K = lca_size - 1;

    for (int k = K; k >= 0; k--)
    {
        if (Pow(2, k) <= (parent_tree[b].second - parent_tree[a].second)) // 2의 n승 만큼 이동.
            if (parent_tree[a].second <= lca_tree[k][b]) // 나머지 자투리만큼 이동
                b = lca_tree[k][b];
    }

    for (int k = K; k >= 0 && a != b; k--)
    {
        if (lca_tree[k][a] != lca_tree[k][b])
        {
            a = lca_tree[k][a];
            b = lca_tree[k][b];
        }
    }

    if (a != b)
        return lca_tree[0][a];

    return a;
}

int Pow(int a, int b)
{
    if (b == 0)
        return 1;

    int cnt = 0;
    int ans = 1;

    while (cnt < b)
    {
        ans *= a;
        cnt++;
    }
    return ans;
}