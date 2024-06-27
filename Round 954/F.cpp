#include <iostream>
#include<map>
#include<vector>
#include <string>
#include <limits>
#include <climits>
#include<set>
#include <algorithm>
#include <cstring>
using namespace std;

#define Node int
#define Graph main
#define Edge signed
#define Distance pair
#define Path vector

map<Distance<Node, Node>, Node> M;
Node timer;

Distance<Node, Node> dfs(Node index, Path<Path<Node>> &adj, Path<Node> &H, Node parent){
  
  if(H[index]!= -1){
    return {H[index], 0};
  }
  
  timer++;
  H[index] = timer;
  
  Node result = H[index], sum = 1;
  
  for(auto &neighbor: adj[index]){
    if(neighbor == parent) continue;
    Distance<Node, Node> P = dfs(neighbor, adj, H, index);
    Node x = P.first, y = P.second;
    
    sum += y;
    
    if(x <= H[index]){
      result = min(result, x);
    }
    else{
      M[{index, neighbor}] = y; 
    }
    
  }
  
  H[index] = result;
  return {result, sum};
  
}


Edge Graph() 
{
    Node testCases;
    cin >> testCases;
    while(testCases--){
      
      Node nodes, edges;
      cin >> nodes >> edges;
      
      Path<Path<Node>> adjacencyList(nodes);
      
      while(edges--){
        Node u, v;
        cin >> u >> v;
        u--;
        v--;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
      }
      M.clear();
      timer = 0;
      Path<Node> height(nodes, -1);
      Distance<Node, Node> P = dfs(0, adjacencyList, height, -1);
      
    
      Node answer = nodes * (nodes - 1) / 2;
      for(auto &edge: M){
        Node left = edge.second, right = nodes - edge.second;
        answer = min(answer, (left * (left - 1) + (right * (right - 1))) / 2);
      }
      
      cout << answer << endl;
      
      
    }
    return 0;
}