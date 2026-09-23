ll kadanes(vector<ll> &a){
    vector<ll> pr(a.size());
    pr[0] = a[0];
    ll ans = pr[0];

    if(pr[0] < 0) pr[0] = 0;

    for(int i= 1 ; i<a.size() ; i++){
        pr[i] = pr[i-1] + a[i];
        ans = max(pr[i] , ans);
        if(pr[i] < 0){
            pr[i] = 0;
        }
    }
    return ans;

}