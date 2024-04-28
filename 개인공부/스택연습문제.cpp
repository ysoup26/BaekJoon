#include <iostream>

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
        if(Top < now)
        {
            return;
        }
        now++;
        Arr[now] = x;
    };
    int pop(){
        int result;
        if(IsEmpty()){
            result = -1;
        }else{
            result = Arr[now];
            now--;
        }
        return result;
    }
    int size(){
        if(Bottom > now){
            return 0;
        }else
            return now+1;
    }
    int IsEmpty(){
        int result;
        if(Bottom > now)
            result=1;
        else
            result = 0;
        return result;
    }
    int top(){
        if(IsEmpty()){
            return -1;
        }else
            return Arr[now];
    }
};

int main(){
    int N;
    cin>>N;
    Stack s;
    for(int i=0;i<N;i++){
        int n,x;
        cin>>n;
        if(n==1){
            cin>>x;
            s.push(x);
        }else if(n==2){
            cout<<s.pop()<<"\n";
        }else if(n==3){
            cout<<s.size()<<"\n";
        }else if(n==4){
            cout<<s.IsEmpty()<<"\n";
        }else if(n==5){
            cout<<s.top()<<"\n";
        }
    }
    return 0;
}