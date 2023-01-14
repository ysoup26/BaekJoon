#include <iostream>
#include <string>

using namespace std;

//저장하고 세로 읽기
int main()
{
    char board[5][15];
    string read;
    for(int i=0;i<5;i++)
    {
        string line;
        cin>>line;
        for(int j=0;j<15;j++)
        {
            if(j<line.length())
                board[i][j]=line[j];
            else
                board[i][j]=' '; //빈부분엔 쓰레기값이 아닌 공백
        }
    }
    for(int j=0;j<15;j++)
    {
        for(int i=0;i<5;i++)
        {
            if(board[i][j]==' ')
                continue;
            read+=board[i][j];
        }
    }
    cout<<read;
    return 0;
}