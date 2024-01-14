#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class graph{
   public :
     unordered_map<int,list<int>>adj;
     void addEdge(int u,int v,int direction){
           adj[u].push_back(v);
           if(!direction)  // if the graph is undirected
               adj[v].push_back(u);
     }
     void print(){
       for(auto i : adj){
         cout << i.first << "->";
         for(auto j : i.second){
            cout << j << " ";
         }
     }
}
int main(){
    int noOfvertices,noOfEdge;
    cout << "enter the no. of vertices and Edeges:";
    cin >> noOfvertices >> noOfEdge;
    int u,v;
    cout <<"enter the connections":;
    for(int i = 0; i < noOfEdges; i++)
       cin >> u >> v;
    graph g;
    g.addEdge(u,v,dir)
}
/*
  1---2
  |    
  3---4
      */
