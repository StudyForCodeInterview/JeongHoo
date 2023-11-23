// 72_10868.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define MIN  1000000001
using namespace std;

typedef long long tdata;

vector<tdata> seg_tree;

void GetMin(int left, int right);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int tree_size = 1;

    int input_index;
    
    int pow_cnt = 1;

    while (tree_size < N)
    {
        tree_size *= 2;
        pow_cnt++;
    }
    input_index = tree_size;
    // 최소값 저장을 위한 배열 크기 확보
    tree_size *= 2;
    pow_cnt++;
    
    seg_tree = vector<tdata>(tree_size, MIN);
    for (int i = 0; i < N; i++)
    {
        cin >> seg_tree[input_index + i];
    }
 
    //마지막이 짝수인지 홀수인지 확인 후 처리
    bool isEven;
    if (input_index + N - 1 % 2 == 0)
        isEven = true;
    else
        isEven = false;

    for (int i = input_index + N - 1; i >= 1; i -= 2)
    {
        if (isEven)
            seg_tree[i/2] = min(seg_tree[i], seg_tree[i + 1]);
        else
            seg_tree[i/2] = min(seg_tree[i], seg_tree[i - 1]);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;

        GetMin(input_index + a - 1 , input_index + b -1);
    }
    return 0;
}
void GetMin(int left, int right)
{
    tdata t_min = MIN;
    int start_index = left;
    int end_index = right;

    while (start_index <= end_index)
    {
        if (start_index % 2 == 1)
            t_min = min(t_min, seg_tree[start_index]);

        if (end_index % 2 == 0)
            t_min = min(t_min, seg_tree[end_index]);
        
        start_index = (start_index + 1) / 2;
        end_index = (end_index - 1) / 2;
    }

    cout << t_min << "\n";
}
