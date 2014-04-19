#include <bits/stdc++.h>
using namespace std ;
typedef vector <int> vi ;


vi topo ;
vector <vi> adj ;
bool vis [35000] ;

void dfs(int u){
    vis[u] = true ;
    
    for ( int i = 0 ; i <adj[u].size() ; i++)
    if(!vis[ adj[u][i] ] )
    dfs( adj[u][i]);
    
    topo.push_back(u) ;
}

int main(){
   memset ( vis , false ,sizeof vis);
   int n , m , i, j ,x , y;
   cin >> n >> m ;
   adj.assign( n+1 , vi());
   for ( i = 0 ; i < m ; i++){
    cin >> x >> y ;
    adj[y].push_back(x) ;
   }
   
  for ( i = 1 ; i <= n ; i++){
     if ( !vis[i] )
     dfs(i);
  }

   reverse ( topo.begin() , topo.end() );
// cout << topo.size() << endl;
   if ( topo.size() != n ){
    cout <<"-1\n" ; return 0 ;
   }

  for ( i = 0 ; i < n ; i++){
   cout <<topo[i] <<" ";
  }

return 0 ;
}
