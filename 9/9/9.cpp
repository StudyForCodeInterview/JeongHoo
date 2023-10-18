// 9.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input_str;
    int answer = 0;

    int S, P;
    
    int std_a, std_c, std_g, std_t;

    int A=0, C=0, G=0, T=0;

    cin >> S >> P;

    cin >> input_str;

    cin >> std_a >> std_c >> std_g >> std_t;

    vector<char> str_(input_str.begin(), input_str.end());
    vector<char> sub_str_(P);

    copy(str_.begin(), str_.begin()+P, sub_str_.begin());

    vector<char>::iterator start_iter = str_.begin();
    vector<char>::iterator end_iter;

    for (end_iter = str_.begin(); end_iter != str_.begin() + P; end_iter++)
    {
        switch (*end_iter)
        {
        case 'A': 
            A++; break;
        case 'C':
            C++; break;
        case 'G':
            G++; break;
        case 'T':
            T++; break;

        }
    }
    
    if (A >= std_a && C >= std_c && G >= std_g && T >= std_t)
        answer++;
    

    while (end_iter != str_.end())
    {
        switch (*start_iter)
        {
        case 'A': A--; break;
        case 'C': C--; break;
        case 'G': G--; break;
        case 'T': T--; break;
        }

        switch (*end_iter)
        {
        case 'A': A++; break;
        case 'C': C++; break;
        case 'G': G++; break;
        case 'T': T++; break;
        }


        if (A >= std_a && C >= std_c && G >= std_g && T >= std_t)
            answer++;

        start_iter++;
        end_iter++;
    }
    cout << answer << "\n";
}
