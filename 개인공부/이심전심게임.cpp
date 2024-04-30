/*
이심전심: 두 사람이 같은 단어를 고르는 게임

동작: 
1) 두 키워드 제시
2) 유저와 봇이 키워드를 하나씩 선택
3) 두 키워드가 동일하면 정답

이때 봇은 키워드 조합별 확률을 가지고 키워드를 선택함
*/

#include <iostream>

string keyword[6] ={"으쓱","미소","윙크","실망","놀람","화남"};

int main(){
    //랜덤 두 키워드
    string user,bot;
    cin>>user;
    cout<<"유저: "<<user<<" / 봇: "<<bot;
    return ;
}