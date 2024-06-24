#include <iostream>

using namespace std;

int main(){
    int Arr[101][101] ={0,}; //1,1을 시작좌표로 하기 위해
    int N,cnt;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        //해당 색종이의 모든 좌표에 1을 집어넣음
        for(int x = a;x<a+10;x++){
            for(int y = b;y<b+10;y++){
                Arr[x][y] = 1;
            }
        }
    }
    cnt = 0;
    //값이 1인 좌표를 세서 넓이를 구함
    for(int x = 1;x<=100;x++){
        for(int y = 1;y<=100;y++){
             if(Arr[x][y] == 1)
                 cnt++;
        }
    }
    cout<<cnt;
    return 0;
}