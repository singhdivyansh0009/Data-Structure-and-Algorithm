// Graph representation
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
            cout << j << ",";
         }
         cout << endl;
       }
     }
};
int main(){
    int noOfvertices,noOfEdge;
    cout << "enter the no. of vertices and Edeges:";
    cin >> noOfvertices >> noOfEdge;
    int u,v;
     graph g;
    cout <<"enter the connections";
    for(int i = 0; i < noOfEdge; i++){
       cin >> u >> v;
       g.addEdge(u,v,0);
    }
    g.print();
}
/*
  1---2
    /    
  3---4
 */
