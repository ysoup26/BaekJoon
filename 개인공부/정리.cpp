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

/*DFS/BFS*/

//깊은 너비 탐색
//반환형으로 void나 bool을 사용
//bool을 사용하면, 시작하는 좌표는 true를 반환하기 때문에 구역 세기에 용이하다.
//문제 유형: ㅁㅁ하는 칸의 개수를 구하세요
bool dfs(int x){
    if(x<0 || x>N){//잘못된 좌표 제외
        return false;
    }
    if(visited[x]){//이미 방문한 좌표 제외
        return false;
    }
    visited[x] = true; //방문처리
    for(int i=0;i<map[x].size();i++){
        int next = map[x][i];
        if(!visited[next])
            dfs(next);
    }
    return true;
}

//좁은 너비 탐색
//최소칸 구하기 문제는 방문할때 이전칸의 값+1을 줌으로써 계산할 수 있다.
//문제유형: 미로 문제. 탈출할 수 있는 최소 칸의 개수를 구해라
void bfs(int x){
    visited[x] = true;
    queue<int> q; //queue<pair<int,int>> q 
    q.push(x);    //q.push(make_pair(x,y));
    while(!q.empty()){
        int qx = q.front(); //q.front().first, .second
        q.pop();
        for(int i=0;i<map[qx].size();i++){
            int next = map[qx][i];
            if(!visited[next]){    //이부분의 조건과 내용을 달리 줄 수 있음. 특정값을 제외하거나, 좌표검증을 하거나
                visited[next] = true;
                q.push_back(next);
            }
        }
    }
}

/*정렬*/

//quick sort
//시간복잡도가 낮은 정렬방법
//pivot이라는 정하고, pivot을 기준으로 배열을 나눈후 정렬하는 방식
//각각의 나눠진 배열은 계속해서 pivot을 정하고 나누면서 정렬을 수행한다
void quick_sort(int start,int end){
    int pivot = start;
    int left = start+1;
    int right = end;
    while(left<=right){
        while(left<=end && arr[left]<=arr[pivot])
            left++;
        while(right>=start+1 && arr[right]>=arr[pivot])
            right--;
        if(left<=right){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }else{
            int tmp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = tmp;
        }
    }
    quick_sort(start,right-1);
    quick_sort(right+1,end);

}

/*이진탐색*/
//특정 값이나 단어를 탐색하는 방법
//중점을 변경하며 탐색하는 방식이고 재귀, 반복문으로 구현할 수 있다
//찾으려는 값이 중점보다 작다면, 중점이 새로운 끝점이 되고
//                      크다면, 중점이 새로운 시작점이 된다.
bool binary_search(int find,int start,int end){
    int s,m,e,find_idx;
    s = start;
    e = end;
    while(true){
        if(s > e){
            find_idx = -1; //시작과 끝점이 교차한다면 값을 찾을 수 없는 것
            break;
        }
        m = (s+e)/2;
        if(arr[m] == find){
            find_idx = m;
            break;
        }else if(arr[m] > find)
            e = m-1;
        else
            s = m+1;
    }
    return find_idx;
}

int binary_search(int find,int start,int end){
    if(start>end)
        return -1;
    int m = (start+end)/2;
    if(arr[m] == find)
        return m;
    else if(arr[m] > find)
        return binary_search(find,start,m-1);
    else
        return binary_search(find,m+1, end); 

}