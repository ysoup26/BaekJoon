#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101];
int visited[101][101];
int N;
int test_v; //안전영역 개수 체크 변수(테스트)

int dfs(int x,int y){
    //접근할 수 없는 영역 검증
    if(visited[x][y]==1 ||x<0 || x>=N || y<0 || y>=N ){
        return 0;
    }
    //접근할 수 있지만, 침수된 영역
    if(visited[x][y] == 0 && map[x][y] <= 0){ //
        visited[x][y] = 1;
        map[x][y]--;
        return 0;
    }
    visited[x][y] = 1;
    map[x][y]--;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    return 1;
}

int main() {
    cin>>N;
    int map_max_v = 0;
    int max_area = 0;
    //map과 visited 값 삽입
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cin>>map[x][y];
            if(map[x][y] > map_max_v)
                map_max_v = map[x][y];
        }
    } 
    //침수값을 변동시키며, 최대값의 안전영역을 구함
    for(int i = 0;i<map_max_v;i++){
        int sum=0;
        fill(&visited[0][0],&visited[100][100],0);
        //영역 출력(테스트)
        /*
        cout<<"<<영역 모습>>\n";
        for(int x=0;x<N;x++){
            for(int y=0;y<N;y++){
                cout<<map[x][y]<<" ";
            }
            cout<<"\n";
        } */
        for(int x=0;x<N;x++){
            //test_v = 0;
            for(int y=0;y<N;y++){
                int v = dfs(x,y);
                if(v>0){
                    sum+=v;
                }    
            }
        } 
        if(sum > max_area){
            max_area = sum;
        }
    }
    //최종 출력
    cout<<max_area;
    return 0;
}