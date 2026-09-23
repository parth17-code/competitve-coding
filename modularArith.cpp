using namespace std;
#include <bits/stdc++.h> 
#define ll long long int


int mod = 1e9+7;


long long mulm(ll a , ll b){
    ll ans = 0;
    while(b > 0){
      if(b & 1){
         ans += a;
         ans %= mod;
      }
      b = b >> 1ll;
      a += a;
      a %= mod;
    }
    return ans;
}

long long powm(ll a , ll b){
   ll ans = 1;
   while(b > 0){
      if(b & 1){
           ans = mulm(ans,a);
      }
      b = b >> 1ll;
      a = mulm(a,a);
   }
    return ans;
}


long long  divm(ll x , ll y){
   return mulm(x, powm(y , mod-2));
}


// matrxi exponentiation
const int sz = 2;

struct Mat{
   long long m[sz][sz];

   Mat(){
      memset(m , 0 , sizeof(m));
   }

   void identity(){
      for(int i=0 ; i<sz ; i++){
         m[i][i] = 1;
      }
   }

   Mat operator* (Mat a){
      Mat res;
      for (int i = 0; i < sz; ++i)
      {
         for (int j = 0; j < sz; ++j)
         {
            for (int k = 0; k < sz; ++k)
            {
               res.m[i][j] += m[i][k] * a.m[k][j];
               res.m[i][j] %= mod;
            }
         }
      }
      return res;
   }
};

long long Fib(long long n){
   Mat res;
   res.identity();
   Mat T;
   T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

   if(n <= 2) return 1;
   n -= 2;

   while(n > 0){
      if(n & 1){
         res = res * T;
      }
      n  = n >> 1ll;
      T = T * T;
   }
   return (res.m[0][0] + res.m[0][1]) % mod;
}


int main(){
	cout << Fib(10);
}