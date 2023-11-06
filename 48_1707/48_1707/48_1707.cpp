// 48_1707.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int, bool> pd;

vector<int> visit_vec;// (V + 1);
vector<vector<int>>data_vec;// (V + 1);
vector<bool> bipartite_vec;// (V + 1, 0); // 1-> 홀수, 2->짝수

bool BFS(int v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, V, E;

	cin >> K;
	string str;
	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;
		
		visit_vec = vector<int>(V + 1);
		data_vec = vector<vector<int>>(V + 1);
		bipartite_vec = vector<bool>(V + 1, false); // 1-> 홀수, 2->짝수

		bool bFlag = true;
		int start_vertex = 1;
		for (int i = 0; i < E; i++)
		{
			int u, v;

			cin >> u >> v;

			if (bFlag)
			{
				bFlag = false;
				start_vertex = u;
			}
			data_vec[u].push_back(v);
			data_vec[v].push_back(u);
		}
		
		bool res = true;
		for (int i = 1; i <= V; i++)
		{
			fill(bipartite_vec.begin(), bipartite_vec.end(), false);
			res = BFS(i);
			if (!res)
				break;
		}

		
		if (res)
			str += "YES\n";
		else
			str += "NO\n";
	}
	cout << str;
	
	return 0;
}
bool BFS(int v)
{
	queue<pd> main_queue;
	main_queue.push(pd(v,false));


	while (main_queue.size() > 0)
	{
		pd data = main_queue.front();
		main_queue.pop();

		if (visit_vec[data.first])
		{
			if (bipartite_vec[data.first] != data.second)
				return false;
			// 처리
			continue;
		}
		visit_vec[data.first] = true;
		bipartite_vec[data.first] = data.second;

		for (int i = 0; i < data_vec[data.first].size(); i++)
		{
			main_queue.push(pd(data_vec[data.first][i],!data.second));
		}
	}
	return true;
}
