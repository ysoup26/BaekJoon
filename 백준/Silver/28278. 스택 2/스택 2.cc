#include <iostream>
#include <stack>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M,X;
    cin>>N;
    stack<int> s;
    for(int i=0;i<N;i++){
        cin>>M;
        if(M==1){
            cin>>X;
            s.push(X);
        }else if(M==2){
            if(s.empty()){
                cout<<"-1\n";
            }else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }else if(M==3){
            cout<<s.size()<<"\n";
        }else if(M==4){
            if(s.empty()){
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if(M==5){
            if(s.empty()){
                cout<<"-1\n";
            }else{
                cout<<s.top()<<"\n";
            }
        }
    }
    return 0;
}