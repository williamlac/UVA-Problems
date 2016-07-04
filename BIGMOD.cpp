//
//  main.cpp
//  Maratona-Lista 2
//
//  Created by William Sathler Lacerda on 5/17/16.
//  Copyright © 2016 William Sathler Lacerda. All rights reserved.
//

#include <iostream>

//long long int mod(long long int B, long long int P, long long int M)
//{
//	long long int res = 1;
//	B=B%M;
//	for(long long int i=0;i<P;i++)
//	{
//		res = (res*B)%M;
//	}
//
//	return res;
//
//}
long long int  bigmod ( long long int B, long long int P,long long int M )
{
	if ( P == 0 )return 1;
 
	if ( P % 2 )
	{
		return ( ( B % M ) * ( bigmod ( B, P - 1, M ) ) ) % M;
	}
	else
	{
		long long int res = bigmod ( B, P / 2, M );
		return ( (res%M) * (res%M) ) % M;
	}
}
int main() {
	long long int B, P, M;
	while (scanf("%lld %lld %lld",&B,&P,&M)==3) {
		long long int res = bigmod(B, P, M);
		printf("%lld\n", res);
	}
	return 0;
}
