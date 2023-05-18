
#include <iostream>
#include <vector>

using namespace std;

//깊은 탐색. 
void dfs(int x,int start,int *cnt,vector<int>* graph,bool *visited)
{
    visited[x] = true;
    for(int i=0;i<graph[x].size();i++)
    {
        int next = graph[x][i];
        if(!visited[next])
        {
            (*cnt)++;
            dfs(next,start,cnt,graph,visited);
        }
    }
}

void arr_max(int arr[],int N)
{
   int max = arr[1]; 
   for(int i=2;i<=N;i++)
   {
       if(max<arr[i])
        max = arr[i];
        
   }
   for(int i=1;i<=N;i++)
   {
       if(max == arr[i])
        cout<<i<<" ";
   }
}

int main()
{
    int N,M;
    cin>>N>>M;
    
    vector<int> graph[N+1]; //1~N의 컴퓨터
    bool visited[N+1];
    int hack[N+1];
    
    fill(visited,visited+N+1,false);
    fill(hack,hack+N+1,0);
    
    //A -(신뢰)-> B == B -(해킹)-> A. 반대는 안된다.(단방향)
    //여기서 화살표 방향은 해킹이 퍼지는 방향이다. 
    for(int i=0;i<M;i++)
    {
        int c1,c2;
        cin>>c1>>c2;
        graph[c2].push_back(c1);
    }
    //시작 컴퓨터를 다르게 해서 전체에 대한 탐색
    for(int i=1;i<=N;i++)
    {
        int cnt=0;
        fill(visited,visited+N+1,false); 
        dfs(i,i,&cnt,graph,visited);
        hack[i] = cnt;
    }
    arr_max(hack,N);

    return 0;
}
