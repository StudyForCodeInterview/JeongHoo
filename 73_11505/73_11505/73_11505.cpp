// 73_11505.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define DENOMINATOR 1000000007
using namespace std;

typedef long long tdata;

vector<tdata> seg_tree;

void Mult(tdata a, tdata b);
void Print(int left, int right);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int tree_size = 1;

	int pow_cnt = 1;
	while (tree_size < N)
	{
		tree_size *= 2;
		pow_cnt++;
	}

	int input_idx = tree_size;
	tree_size *= 2;
	pow_cnt++;

	seg_tree = vector<tdata>(tree_size, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> seg_tree[input_idx + i];
	}


	bool isEven = (input_idx + N - 1) % 2 == 0;
	for (int i = input_idx + N - 1; i >= 1; i -= 2)
	{
		if (isEven)
			seg_tree[i / 2] = seg_tree[i] * seg_tree[i + 1] % DENOMINATOR;
		else
			seg_tree[i / 2] = seg_tree[i] * seg_tree[i - 1] % DENOMINATOR;
	}

	for (int i = 0; i < M + K; i++)
	{
		tdata a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			Mult(b + input_idx - 1, c);
		else
			Print(b + input_idx - 1, c + input_idx - 1);
	}
	return 0;
}
void Mult(tdata a, tdata b)
{
	int start_idx = a;

	seg_tree[start_idx] = b;

	while (start_idx >= 1)
	{
		// 짝수 인덱스
		if (start_idx % 2 == 0)
			seg_tree[start_idx / 2] = seg_tree[start_idx] * seg_tree[start_idx + 1] % DENOMINATOR;
		else
			seg_tree[start_idx / 2] = seg_tree[start_idx] * seg_tree[start_idx - 1] % DENOMINATOR;

		start_idx /= 2;
	}
}

void Print(int left, int right)
{
	int start_idx = left;
	int end_idx = right;

	tdata ans = 1;
	while (start_idx <= end_idx)
	{
		if (start_idx % 2 == 1)
			ans = ans * seg_tree[start_idx] % DENOMINATOR;

		if (end_idx % 2 == 0)
			ans = ans * seg_tree[end_idx] % DENOMINATOR;

		start_idx = (start_idx + 1) / 2;
		end_idx = (end_idx - 1) / 2;
	}
	cout << ans << "\n";
}