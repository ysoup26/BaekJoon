#include <iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    if(B >= C){ //C가 B보다 작으면, (수식에 의해)절대 손익분기점이 발생할 수 없음 
        cout<<-1;
    }else{
        int result = A/(C-B); //딱 나누어떨어지는 값 + 1 하면 손익분기점
        //주어진 식을 간소화해서 점화식을 구함
        //-> C x N >= A + B x N
        //-> N >= A / (C-B)
        cout<<result+1;
    }
    return 0;
}
