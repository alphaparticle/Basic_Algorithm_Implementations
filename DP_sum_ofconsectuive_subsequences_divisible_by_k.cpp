#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;
LL input [1000010] ;
LL ginti [110] ;
int n , k , test ;

int main(){
int i , j ;
scanf("%d",&test);
while ( test-- ){
      scanf("%d %d",&n , &k);
      memset ( ginti , 0, sizeof ginti) ;
      ginti[0] = 1 ;
      scanf("%lld",&input[0]) ;
      ginti [ input[0] %k ] ++ ;
      for( i = 1 ; i < n ; i++){
        scanf("%lld", input + i ) ;
        input[i] += input[i-1] ;
        ginti[ input[i] %k ] ++ ;
      }
    LL ans  = 0;
    for ( i = 0 ; i < k ; i++)
        ans +=  ( ginti[i] * (ginti[i]-1) ) / 2 ;
    printf("%lld\n",ans);
}



return 0 ;
}





