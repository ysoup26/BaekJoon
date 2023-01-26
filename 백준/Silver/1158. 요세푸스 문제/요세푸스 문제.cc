#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue <int> Josephus,Nqueue;
    int N,K,check=1;
    cin>>N>>K;
    
    for(int i=1;i<=N;i++)//1~N
        Nqueue.push(i);  
    cout<<"<";
    //Nqueue.size()가 0이 될 때까지
    while(Nqueue.size()!=1)
    {
        int newInput=Nqueue.front();
        if(check==K){ 
            cout<<Nqueue.front()<<", ";
            check=1;
        }else
        {
            Nqueue.push(Nqueue.front());
            check++;
        }
        Nqueue.pop();
    }
    cout<<Nqueue.front()<<">";
    return 0;
}