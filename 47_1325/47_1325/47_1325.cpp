// 47_1325.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pd;

int g_max = 0;

vector<int> count_vec;
vector<vector<int>> data_vec;

vector<bool> visit_vec;
void DFS(int i, int cnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	count_vec = vector<int>(N + 1);
	data_vec = vector<vector<int>>(N + 1);
	visit_vec = vector<bool>(N + 1,false);

	for (int i = 0; i < M; i++)
	{
		int data_1, data_2;
		cin >> data_1 >> data_2;

		data_vec[data_1].push_back(data_2);
	}


	for (int i = 1; i <= N; i++)
	{
		visit_vec = vector<bool>(N + 1, false);

		DFS(i, 0);
	}

	for (int i = 1; i <= N; i++)
	{
		if (g_max < count_vec[i])
			g_max = count_vec[i];
	}
	for (int i = 1; i <= N; i++)
	{
		if (count_vec[i] == g_max)
			cout << i << " ";
	}
	return 0;
}
void DFS(int start, int cnt)
{
	visit_vec[start] = true;
	cnt++;
	for (int idx = 0; idx < data_vec[start].size(); idx++)
	{
		int next = data_vec[start][idx];

		if (!visit_vec[next])
			DFS(next, cnt);
	}

	count_vec[start]++;
}