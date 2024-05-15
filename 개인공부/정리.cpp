/*알고리즘 간단 정리

특별한 공식이나 방법이 있는 알고리즘을 정리

1. 그리디
2. 구현
3. DFS/BFS  *
4. 정렬  *
5. 이진탐색  *
6. 다이나믹 프로그래밍  *
7. 최단 경로  *
8. 그래프 이론

*/

//깊은 너비 탐색
void dfs(int x){
    visited[x] = 1; //방문처리
    for(int i=0;i<map[x].size();i++){
        int next = map[x][i];
        dfs(next);
    }
}