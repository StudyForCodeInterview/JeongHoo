// 46_18352.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> data_vec;// N+1
vector<int> dist_vec;
vector<bool> visit_vec;
queue<pair<int, int>> visit_queue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;

    cin >> N >> M >> K >> X;

    vector<int> answer_vec;
    data_vec = vector<vector<int>>(N + 1); // N+1
    dist_vec = vector<int>(N + 1, 0);
    visit_vec = vector<bool>(N + 1, false);


    for (int i = 0; i < M; i++)
    {
        int data_1, data_2;
        cin >> data_1 >> data_2;

        data_vec[data_1].push_back(data_2);
    }

    visit_queue.push(pair<int, int>(X, 0));

    int start_count = 0;
    int count = 0;

    while (visit_queue.size() > 0)
    {
        pair<int, int> data = visit_queue.front();
        int visit_index = data.first;
        visit_queue.pop();

        if (visit_vec[visit_index] || data.second > K)
        {
            continue;
        }

        visit_vec[visit_index] = true;

        if (dist_vec[visit_index] > data.second || dist_vec[visit_index] == 0)
            dist_vec[visit_index] = data.second;

        count = data.second + 1;
        for (int i = 0; i < data_vec[visit_index].size(); i++)
        {
            visit_queue.push(pair<int, int>(data_vec[visit_index][i], count));
        }
    }

    for (int i = 0; i < dist_vec.size(); i++)
    {
        if (dist_vec[i] == K)
            answer_vec.push_back(i);
    }

    if (answer_vec.empty())
        cout << "-1\n";
    else
    {
        for (int i = 0; i < answer_vec.size(); i++)
        {
            cout << answer_vec[i] << "\n";
        }
    }
    return 0;
}