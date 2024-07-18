#include <iostream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M,cnt;
    cin>>N>>M;
    set<string> S;
    cnt = 0;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        S.insert(tmp);
    }
    //set 출력법    
    /*for(auto iter = S.begin();iter!=  S.end();iter++){
        cout<<*iter<<"\n";
    }*/
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        if(S.find(tmp) != S.end()) // end가 아닌 반복자 반환 = 존재한다
            cnt++;
    }
    cout<<cnt;
    return 0;
}