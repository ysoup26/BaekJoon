/*순차탐색
  : 특정 데이터를 찾기 위해 앞에서부터 탐색
*/

#include <iostream>
#include <string>

using namespace std;

int sequential_search(int n,string findWord,string words[])
{
    for(int i=0;i<n;i++){
        if(findWord.compare(words[i])==0){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int n = 5;
    string f = "Dongbin";
    string words[n] = {"Hanul", "Jonggu", "Dongbin","Taeil","Sangwook"};
    cout<<sequential_search(n,f,words);
    return 0;
}