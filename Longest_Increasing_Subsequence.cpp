// LIS Implemntation  O(n^2) 

int arr[n] ;  // Elements in array for which LIS needs to be calculated
int dp[n][2] ; // dp[][0] -> represents current LIS count
               // dp[][1] -> represents parent to which it is connected ;


dp[0][0] = 1 ; dp[0][1] = 0 ;

// Calculation of LIS
int ans , index ; // ans ->  max. LIS possible
                  // index -> index of the last element in LIS

for ( i = 1  ; i < n ; i++){
	dp[i][0] = 1 ;
    for ( j = i-1 ; j >= 0 ; j--)
    if ( arr[j] < arr[i])
    if ( dp[j][0] +1 > dp[i][0] )
    {
       dp[i][0] = 1 + dp[j][0] ;
       dp[i][1] = j ;
    }

   if ( dp[i][0] > ans){
      ans = dp[i][0] ; index = i ;
   }
}

// Printing the elements involved in the LIS 
// or Printing the path

vector <int> u ; // stores the path
u.push_back( arr[index]) ;  
        
// Go in reverse direction until the first element of LIS is not found ;

while ( index >= 0 && dp[index][1] != index){
	index = dp[index][1] ;
	u.push_back (arr[index]);
}


// Printing in the visiting order

for ( i = u.size()-1 ; i >= 0 ; i-- ){
	 printf("%d\n" , u[i]);
}
