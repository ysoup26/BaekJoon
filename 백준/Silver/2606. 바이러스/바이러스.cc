#include <iostream>
#include <vector>

using namespace std;

//재귀함수로 구현된 dfs
void dfs(int x,vector<int> *com,vector<int> *worm,bool *visited) 
{
    visited[x]=true;
    for(int i=0;i<com[x].size();i++) //연결된 컴퓨터중 확인하지 않은것 탐색
    {
        int c=com[x][i];
        if(!visited[c]) 
        {
            //cout<<x<<" dfs"<<c<<"\n";
            worm->push_back(c);
            dfs(c,com,worm,visited);
        }
    }
}

int main()
{
    int N,chain;
    cin>>N>>chain;
    vector<int> com[N+1];
    vector<int> worm;
    bool visited[N+1];
    
    fill(visited,visited+N+1,false);
    for(int i=1;i<=chain;i++)
    {
        int f,s;
        cin>>f>>s;
        //*실제값과 인덱스가 다름
        com[f].push_back(s);
        com[s].push_back(f);
    }
    /*구조확인
    for(int i=1;i<=N;i++)
    {
        cout<<i<<":";
        for(int j=0;j<com[i].size();j++)
        {
            int c=com[i][j];
            cout<<" "<<c;
        }    
        cout<<"\n";
    }*/
    
    dfs(1,com,&worm,visited); //첫번째 연결부터 검사시작
    cout<<worm.size();
    return 0;
}
