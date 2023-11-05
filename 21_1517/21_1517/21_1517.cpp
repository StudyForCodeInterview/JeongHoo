// 21_1517.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& origin_array, int left, int right, vector<int>& merge_array);

long long bub_count = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> origin_array(N);
	vector<int> merge_array(N);

	for (int i = 0; i < N; i++)
	{
		cin >> origin_array[i];
	}

	MergeSort(origin_array, 0, N - 1, merge_array);

	cout << bub_count << "\n";
	
	return 0;
}


void MergeSort(vector<int>& origin_array, int left, int right, vector<int>& merge_array)
{
	if (left == right)
		return;

	int mid = (left + right) / 2;

	MergeSort(origin_array, left, mid, merge_array);
	MergeSort(origin_array, mid + 1, right, merge_array);

	int merge_index = left;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (origin_array[i] <= origin_array[j])
		{
			merge_array[merge_index++] = origin_array[i++];

		}
		else
		{
			// 이게 왜 시간초과
			//for (int k = i; k <= mid; k++)
			//{
			//	if (origin_array[k] > origin_array[j])
			//		bub_count++;
			//}

			bub_count += (long long)mid - i + 1;

			merge_array[merge_index++] = origin_array[j++];
		}
	}

	while (i <= mid)
	{
		merge_array[merge_index++] = origin_array[i++];
	}
	while (j <= right)
	{
		merge_array[merge_index++] = origin_array[j++];
	}

	for (j = left; j <= right; j++)
	{
		origin_array[j] = merge_array[j];
	}
}