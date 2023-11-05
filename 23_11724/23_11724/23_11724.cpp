// 23_11724.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int g_visit_count;

void DFS(vector<vector<int>>& adj_vec, int idx, vector<bool>& visit_vec);
int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<bool> visit_vec(N+1, false);	
	
	vector<vector<int>> adj_vector(N+1);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		adj_vector[u].push_back(v);
		adj_vector[v].push_back(u);
	}
	
	int visit_count = 0;
	
	for (int i = 1; i <= N; i++)
	{
		if (!visit_vec[i])
		{
			DFS(adj_vector, i, visit_vec);
			visit_count++;
		}
	}
	cout << visit_count << "\n";
	return 0;
}

void DFS(vector<vector<int>>& adj_vec, int idx, vector<bool>& visit_vec)
{
	if (visit_vec[idx])
		return;

	visit_vec[idx] = true;

	while (adj_vec[idx].size() > 0)
	{
		int data_idx = adj_vec[idx].back();
		adj_vec[idx].pop_back();

		DFS(adj_vec, data_idx, visit_vec);
	}
}