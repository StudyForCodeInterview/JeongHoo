// 3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#define MAX 100001
int sub_total_array[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int i, j;

	int data;
	
	cin >> N >> M;

	for (int cnt = 1; cnt <= N; cnt++)
	{
		cin >> data;
		sub_total_array[cnt] = sub_total_array[cnt - 1] + data;
	}

	for (int cnt = 1; cnt <= M; cnt++)
	{
		cin >> i >> j;
		cout << sub_total_array[j] - sub_total_array[i-1] << "\n";
	}
	return 0;
}

