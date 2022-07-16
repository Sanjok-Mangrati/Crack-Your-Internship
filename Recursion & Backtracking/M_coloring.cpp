/*
Given an undirected graph and an integer M.
The task is to determine if the graph can be colored with at most M colors 
such that no two adjacent vertices of the graph are colored with the same color. 
Here coloring of a graph means the assignment of colors to all vertices.
*/

//These solution may not be optimised, it is just for learning the concept

#include <bits/stdc++.h>

using namespace std;

bool isPossible(int node, int color[], bool graph[101][101], int N, int colour){
   for(int k=0;k<N;k++){
    if(k!=node && graph[k][node] == 1 && color[node] == colour) return false;
   }
   return true;
}

bool solve(int node, int color[], bool graph[101][101], int m, int N){
    if(node == N)
        return true;
    for(int i=1;i<=m;i++){
        if(isPossible(node,color,graph,N,i)){
            color[node] = i;
            if(solve(node+1,color,graph,m,N) == true)
                return true;
            color[node] = 0;
        }
        
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int color[n] = {0};
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }

        int ans = solve(0,color,graph,m,n);
        
        if(ans == 1){
            cout << "possible" << endl;
        }
        else{
            cout << "not possible" << endl;
        }
        
    }
    return 0;
}