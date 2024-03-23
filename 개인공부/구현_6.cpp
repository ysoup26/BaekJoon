/*문자열 재정렬

1초 128MB

문제 요약: 알파벳 대문자와 숫자(0~9)로 구성된 문자열이 잇다.
          모든 알파벳을 오름차순으로 정렬하여 출력하고
          그 뒤에 모든 숫자를 더한 값을 출력한다

입력: 
K1KA5CB7
>>ABCKK13

AJKDLSI412K4JSJ9D
>>ADDIJJJKKLSS20

풀이: 문자열에서 알파벳과 숫자를 구분해낸다.
     알파벳은 재정렬이 필요함으로 별도의 배열에 저장해두었다가 sort함수로 정렬하고 
     숫자는 즉시 덧셈한다. 

*/

#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    char s_arr[10000];
    int s_arr_i = 0;
    int n = 0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(c>='A' && c<='Z'){
            s_arr[s_arr_i] = c;
            s_arr_i++;
        }else{
            n+=(c-'0');
        }
    }
    sort(s_arr,s_arr+s_arr_i);
    for(int i=0;i<s_arr_i;i++){
        cout<<s_arr[i];
    }
    cout<<n;
    return 0;
}