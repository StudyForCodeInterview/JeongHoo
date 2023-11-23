// 66_1414.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> td;

vector<td> D;
vector<int> uf;
bool Union(int a, int b);
int Find(int a);

int total_len;
int edge_cnt;
int connection_len;
bool Compare(td a, td b)
{
	return get<2>(a) < get<2>(b);
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;
	
	uf = vector<int>(N + 1);

	for (int i = 1; i < uf.size(); i++)
	{
		uf[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		char c;

		for (int j = 1; j <= N; j++)
		{
			cin >> c;

			int len = 0;

			if (c >= 'a' && c <= 'z')
			{
				len = c - 96;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				len = c - 38;
			}

			total_len += len;
			if (i == j || len == 0)
			{
				continue;
			}

			D.push_back(td(i, j, len));
		}
	}

	sort(D.begin(), D.end(), Compare);
	

	for (int i = 0; i < D.size(); i++)
	{
		int s = get<0>(D[i]);
		int e = get<1>(D[i]);
		int w = get<2>(D[i]);

			if (!Union(s, e))
			{
				connection_len += w;
				edge_cnt++;
			}


		if (edge_cnt == N - 1)
			break;
	}

	for (int i = 1; i < uf.size(); i++)
	{
		int f_one = Find(1);
		if (f_one != Find(i))
		{
			cout << "-1\n";
			return 0;
		}
	}
	
	cout << total_len - connection_len << "\n";
	return 0;
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		uf[b] = a; 
		return false;
	}
	return true;
}
int Find(int a)
{
	if (uf[a] == a)
		return a;

	return uf[a] = Find(uf[a]);
}