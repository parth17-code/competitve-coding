long long divisors(vector<long long> &a , int num){
    for(ll i=1 ; i*i < num ; i++){
        if(num % i == 0){
            a.push_back(i);
            if(num/i != i){
                a.push_back(num/i);
            }
        }
    }
    return num;
}

long long fastDivisors(int num){
    ll ans = 1;
    for(ll i =2 ; i*i<=num ; i++){
        int count  =0;
        while(num % i == 0){
            count ++;
            num = num/i;
        }
        ans  = ans * (count +1);
    }
    if(num > 1) ans *= 2;
    return ans;
}

long long productOfFactors(long long num) {
    long long factors = fastDivisors(num);

    if (num * 1LL == sqrt(num) * sqrt(num)) {
        return (long long)(pow(num, factors / 2) * sqrt(num));
    }

    return (long long)pow(num, factors / 2);
}

int precomputeFactors(vector<vector<int>>&a){
    for(int i=1; i < a.size() ; i++){
        for(j = i ; j < a.size() ; j = j+i){
            a[j].push_back(i);
        }
    }
}

vi sieve(1000001 , 0);

void preCompueteSieve(){
    sieve[0] = sieve[1] = 1;
    for(int i=2 ; i*i<sieve.size() ; i++){
        if(sieve[i] == 0){
            for(int j = i*i ; j< sieve.size() ; j += i){
                sieve[j] = 1;
            } 
        }
    }
}

void storeExponents(vector<pair<int,int>> &e , int num , int &cntExp){
    for(int i =2 ; i*i <= num ; i++){
        if(num % i == 0){
            int cnt = 0;

            while(num % i ==0){
                cnt++;
                num = num/i;
            }
            cntExp += cnt;
            e.push_back({i , cnt});
        }
    }
    if(num > 1){
        e.push_back({num , 1});
        cntExp++;
    }
}

void storeDivisors(vector <int> &divisors , int num){
    for(int i=1 ; i*i <= num ; i++){
        if(num % i == 0){
            divisors.push_back(i);

            if(num/i != i){
                divisors.push_back(num/i);
            }
        }
    }
}