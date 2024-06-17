#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int brank,star,line;
    brank = N-1;
    star = 1;
    line = 2*N-1;
    //줄 카운트 for문
    for(int i = 1;i<=line;i++){
        //빈칸찍기 for문
        for(int b=0;b<brank;b++)
            cout<<" ";
        //별찍기 for문
        for(int s=0;s<star;s++)
            cout<<"*";
        cout<<"\n";
        //빈칸과 별 갯수 갱신
        if(i<(line/2+1)){
            brank-=1;
            star+=2;
        }else{
            brank+=1;
            star-=2;
        }
    }
    return 0;
}