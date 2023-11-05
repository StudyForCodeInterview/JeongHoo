// 19_11004.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 퀵 정렬.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void QuickSort(vector<int>& vec,int left, int right);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    
    cin >> N >> K;

    vector<int> int_vec(N);

    for (int i = 0; i < int_vec.size(); i++)
    {
        cin >> int_vec[i];
    }
    
    //sort(int_vec.begin(), int_vec.end());

    QuickSort(int_vec, 0, int_vec.size()-1);

    cout << int_vec[K-1] << "\n";
}

void QuickSort(vector<int>& v, int left, int right)
{
    if (right <= left)
        return;

    int pivot = v[left];
    int pL = left;
    int pR = right;

    while (pL <= pR)
    {
        while (v[pL] <= pivot)pL++;
        while (v[pR] > pivot)pR--;

        // 값을 바꿔줘야 하는 경우. 
        // [PL] [PR]
        if (pL < pR)
        {
            int tmp = v[pL];
            v[pL] = v[pR];
            v[pR] = tmp;
        }
    }
    v[left] = v[pR];
    v[pR] = pivot;
    QuickSort(v, left, pR-1);
    QuickSort(v, pR+1, right);
}
//void QuickSort(vector<int>& v, int left, int right)
//{
//    int pL = left;
//    int pR = right;
// 
//    int pivot = v[(left+right) / 2];
//
//    do
//    {
//        while (v[pL] < v[pivot])pL++;
//        while (v[pR] > v[pivot])pR--;
//
//        if (pL <= pR)
//        {
//            int tmp = v[pL];
//            v[pL] = v[pR];
//            v[pR] = tmp;
//            pL++;
//            pR--;
//        }
//    } while (pL <= pR);
//
//    if (left < pR)
//    QuickSort(v, left, pR);
//    
//    if(pL < right)
//    QuickSort(v, pL, right);
//}
