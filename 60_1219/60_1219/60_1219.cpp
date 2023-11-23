// 60_1219.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define MAX INT64_MAX
#define MIN INT64_MIN
typedef tuple<long long, long long, long long> td;
vector<td> adj_vec;
vector<long long> D;
vector<long long> earn;

bool Update(long long cnt);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, start_city, end_city, M;

    cin >> N >> start_city >> end_city >> M;
    
    D = vector<long long>(N, MIN);
    //adj_vec = vector<td>(M + 1);
    earn = vector<long long>(N);

    for (long long i = 0; i < M; i++)
    {
        long long start, end, price;
        cin >> start >> end >> price;
        
        adj_vec.push_back(td(start, end, price));
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> earn[i];
    }

    D[start_city] = earn[start_city];
    for (long long i = 0; i < N + 50; i++)
       Update(i);

    if (D[end_city] == MIN)
    {
        cout << "gg\n";
    }
    else if (D[end_city]==MAX)
    {
        cout << "Gee\n";
    }
    else
        cout << D[end_city] << "\n";

    return 0;
}
bool Update(long long cnt)
{
    bool bCycle = false;

    for (long long i = 0; i < adj_vec.size(); i++)
    {
        long long start = get<0>(adj_vec[i]);
        long long end = get<1>(adj_vec[i]);
        long long price = get<2>(adj_vec[i]);

        if (D[start] == MIN)
            continue;

        else if (D[start] == MAX)
            D[end] = MAX;

        else if (D[end] < D[start] + earn[end] - price)
        {
            D[end] = D[start] + earn[end] - price;

            bCycle = true;

            if (cnt >= D.size() - 1)
            {
                D[end] = MAX;
            }
        }
    }
    return bCycle;
}