#include <iostream>
#include <stack>

#define MAX_ 100000

using namespace std;

class Stack{
public:
    int Bottom, Top, now;
    int Arr[MAX_];
    Stack(){
        Bottom = 0;
        Top = MAX_;
        now = -1;
    }
    void push(int x){
        if(Top == now)
        {
            return;
        }
        now++;
        Arr[now] = x;
    };
    int pop(){
        int result;
        result = Arr[now];
        now--;
        return result;
    }
    int size(){
        if(empty()){
            return 0;
        }else
            return now+1;
    }
    int empty(){
        int result;
        if(Bottom > now)
            result = 1;
        else
            result = 0;
        return result;
    }
    int top(){
         return Arr[now];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M,X;
    cin>>N;
    //Stack s;
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