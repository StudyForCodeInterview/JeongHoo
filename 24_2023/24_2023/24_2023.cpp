// 24_2023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 다시 해보기
#include <iostream>
#include <vector>

using namespace std;

void DFS(int num, int digit);
bool isPrime(int num);
int g_digit;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> g_digit;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    
    return 0;
}

void DFS(int num, int digit)
{
    if (g_digit == digit && isPrime(num))
    {
        cout << num << "\n";
        return;
    }

    digit++;
    
    for (int i = 1; i <= 9; i += 2)
    {
        if(isPrime(num * 10 + i))
        DFS(num * 10 + i, digit);
    }
}

bool isPrime(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

