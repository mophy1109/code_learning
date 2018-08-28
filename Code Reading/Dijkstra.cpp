//
//  Dijkstra
//  ACM
//  Find the k biggest number in an array
//
//  Created by Rachel on 12-2-23.
//  Copyright (c) 2014年 ZJU. All rights reserved.
//
 
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <functional>
#include <utility>
using namespace std;
#define N 505
#define INF 100000000
#define min(a,b) a<b?a:b
 
int map[N][N];
int minres[N]; //min distance from source to point_i
bool visited[N];
 
void init(int n)
{
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            map[i][j] = INF;
        }
        minres[i] = INF;
    }
    memset(visited, false, sizeof(visited));
}
 
void dijkstra(int source, int dest, int n)
{
    int i,j;
    for(i=0;i<n;i++)
        minres[i]=map[source][i];
    visited[source]=true;
    
    // (n-1) times, each time select one point into the start point set
    for (j=0; j<n-1; j++) {
        //select a point to add into the start point set
        int minn = INF, point=-1;
        for(i=0;i<n;i++)
            if (!visited[i]&&minres[i]<minn) {
                minn = minres[i];
                point = i;
            }
        if(point==-1 || point==dest)
            break;
        visited[point] = true;
        
        //update the min distance of other points
        for (i=0; i<n; i++) {
            if (!visited[i]&&minres[i]>minres[point]+map[point][i]) {
                minres[i] = minres[point]+map[point][i];
            }
        }
    }
}
 
int main()
{
    int i,m,n,a,b,t,source,dest;
    while (cin>>n>>m) {
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&t);
            map[b][a] = map[a][b]= min(map[a][b],t);
        }
        cin>>source>>dest;
        if (source==dest) {
            cout<<0<<endl;
            continue;
        }
        dijkstra(source,dest,n);
        if (minres[dest]==INF) {
            minres[dest] = -1;
        }
        cout<<minres[dest]<<endl;
    }
