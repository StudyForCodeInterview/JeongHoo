// 20_2751.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 병합정렬
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAX 1'000'000
//int origin_array[MAX];
//int merge_array[MAX];

void MergeSort(vector<int>& origin_array, int left, int right, vector<int>& merge_array);

//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    set<int> int_set;
//
//    int N;
//    cin >> N;
//
//    for (int i = 0; i < N; i++)
//    {
//        int data;
//        cin >> data;
//        int_set.insert(data);
//    }
//
//    for (set<int>::iterator iter = int_set.begin(); iter != int_set.end(); iter++)
//    {
//        cout << *iter << "\n";
//    }
//
//    return 0;
//}

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

	MergeSort(origin_array,0, N - 1,merge_array);

	for (int i = 0; i < N; i++)
	{
		cout << origin_array[i] << "\n";
	}
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
	int j = mid+1;

	while (i <= mid && j <= right)
	{
		if (origin_array[i] <= origin_array[j])
		{
			merge_array[merge_index++] = origin_array[i++];
		}
		else
		{
			merge_array[merge_index++] = origin_array[j++];
		}
	}
	
	if (i <= mid)
	{
		while (i <= mid)
		{
			merge_array[merge_index++] = origin_array[i++];
		}
	}
	else if (j <= right)
	{
		while (j <= right)
		{
			merge_array[merge_index++] = origin_array[j++];
		}
	}

	for (j = left; j <= right; j++)
	{
		origin_array[j] = merge_array[j];
	}
}