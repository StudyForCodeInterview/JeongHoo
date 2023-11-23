// 71_2042.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>


using namespace std;

typedef long long cdata;
vector<cdata> seg_tree;
cdata input_index;

void Change(cdata target, cdata value);
void Print(cdata left, cdata right);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cdata N, M, K;

    cin >> N >> M >> K;

    cdata tree_size = 1;
    
    cdata pow_cnt = 1;

    while (tree_size < N)
    {
        tree_size *= 2;
        pow_cnt++;
    }

    input_index = tree_size;
    tree_size *= 2;
    pow_cnt++;

    seg_tree = vector<cdata>(tree_size + 1, 0);

    for (cdata i = 0; i < N; i++)
    {
        cin >> seg_tree[input_index + i];
    }

    // 초기 업데이트

    // 구간 합
    for (cdata i = input_index + N - 1; i >= 1; i--)
    {
        cdata parent_index = i/2;
        seg_tree[parent_index] += seg_tree[i];
    }


    for (cdata i = 0; i < M + K; i++)
    {
        cdata a, b, c;

        cin >> a >> b >> c;

        if (a == 1)
            Change(b, c);
        else
            Print(b + input_index -1, c + input_index -1);
    }
    return 0;
}

void Change(cdata target, cdata value)
{
    cdata change_index = input_index + target - 1;

    cdata prev_val = seg_tree[change_index];

    seg_tree[change_index] = value;

    cdata diff = value - prev_val;

    while (change_index >= 1)
    {
        cdata parent_index = change_index / 2;
    
        seg_tree[parent_index] += diff;

        change_index /= 2;
    }
}
void Print(cdata left, cdata right)
{
    cdata answer = 0;
    
    while (left <= right)
    {
        if (left % 2 == 1)
            answer += seg_tree[left];
        
        if (right % 2 == 0)
            answer += seg_tree[right];

        left = (left + 1) / 2;
        right = (right - 1) / 2;
    }

    cout << answer << "\n";
}
