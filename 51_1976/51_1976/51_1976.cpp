// 51_1976.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g_linked_city;
vector<int> g_parent;

int Find(int a);
void Union(int a, int b);
bool Check(int a, int b);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	g_linked_city = vector<vector<int>>(N + 1);
	g_parent = vector<int>(N+1);
	for (int i = 1; i < g_parent.size(); i++)
	{
		g_parent[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		int flag;
		for (int j = 1; j <= N; j++)
		{
			cin >> flag;
			if (flag)
				g_linked_city[i].push_back(j);
		}
	}

	for (int i = 1; i < g_linked_city.size(); i++)
	{
		for (int j = 0 ; j < g_linked_city[i].size(); j++)
		{
			Union(i, g_linked_city[i][j]);
		}
	}

	vector<int> input;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;
		input.push_back(data);
	}
	int parent_v = Find(input[0]);
	
	bool can = true;
	for (int i = 1; i < input.size(); i++)
	{
		if (Find(input[i]) != parent_v)
		{
			can = false;
			break;
		}
	}

	if (can)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		g_parent[b] = a;
}
int Find(int a)
{
	if (g_parent[a] == a)
		return a;

	return g_parent[a] = Find(g_parent[a]);
}
bool Check(int a, int b)
{
	b = Find(b);
	
	return a == b;
}