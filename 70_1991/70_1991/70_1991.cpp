// 70_1991.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

#define LEFT 0
#define RIGHT 1
using namespace std;
typedef pair<char, char> pd;

vector<char> tree;
void preorder(int idx);
void inorder(int idx);
void postorder(int idx);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int size = 1;
    for (int i = 1; i < N; i++)
    {
        size *= 2;
    }
    tree = vector<char>(size + 1);

    vector<pd> temp = vector<pd>(N + 1);
    for (int i = 0; i < N; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;

        int idx = parent - 'A' + 1;

        temp[idx] = pd(left, right);
    }

    // NODE 간의 연결 정보 확립 후 정리

    queue<int> start_q;
    tree[1] = 'A';
    start_q.push(1);
    
    while (start_q.size())
    {
        int front = start_q.front();
        start_q.pop();

        int tmp_idx = tree[front] - 'A' + 1;

        char left = temp[tmp_idx].first;
        char right = temp[tmp_idx].second;

        if (left != '.')
        {
            start_q.push(2 * front);
            tree[2*front + 0] = left;
        }
        if (right != '.')
        {
            start_q.push(2 * front + 1);
            tree[2*front + 1] = right;
        }
    }

    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
    cout << "\n";
    return 0;
}

void preorder(int idx)
{
    if (idx > tree.size() || !tree[idx])
        return;

    cout << tree[idx];
    preorder(2 * idx);
    preorder(2 * idx + 1);
}
void inorder(int idx)
{
    if (idx > tree.size() || !tree[idx])
        return;

    inorder(2 * idx);
    cout << tree[idx];

    inorder(2 * idx + 1);
}
void postorder(int idx)
{
    if (idx > tree.size() || !tree[idx])
        return;

    postorder(2 * idx);
    postorder(2 * idx + 1);
    cout << tree[idx];

}