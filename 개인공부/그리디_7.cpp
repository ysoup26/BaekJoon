/*만들 수 없는 금액

문제 요약: 

입력: 숫자로 이루어진 문자열S

5
3 2 1 1 9

8

풀이: 
*/

#include <iostream>

using namespace std;

int main(){ 
    int N,target;
    cin>>N;
    int Narr[N];
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        Narr[i] = tmp;
    }
    sort(Narr,Narr+N);
    target=1;
    for(int i=0;i<N;i++){
        int x = Narr[i];
        if(target<x)
            break;
        target+=x;
    }
    cout<<target;
    return 0;
}