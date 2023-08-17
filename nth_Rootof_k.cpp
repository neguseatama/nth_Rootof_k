/*
 Newton's method and nth Root of k in C++
 C++によるニュートン法の実装と累乗根（kのn乗根）の計算
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,k;
double start,error;
//累乗根を入力としたいので、
//kはn乗根の底として受け取る。
//初期値の入力をstartで受け取り、
//誤差限界の入力をerrorで受け取る。

//微分を実行する関数
pair<ll,ll> differentiate(pair<ll,ll> p){
    return {p.first*p.second,p.second-1};
}

//ニュートン法の反復計算を実行する関数
double newton(void){
    //f(x)=x^n-kとおいてf(x)=0となる解を考える。
    //また、f'(x)=n*x^(n-1)である。
    double ans=start;
    double ans2=start-(pow(start,n)-k)/(n*pow(start,n-1));
    while(abs(ans-ans2)>=error){
        ans=ans2;
        ans2=ans-(pow(ans,n)-k)/(n*pow(ans,n-1));
    }
    return ans2;
}

int main(void){
    cin>>n>>k>>start>>error;
    cout<<fixed<<setprecision(30)<<
			newton()<<endl; //求まった近似値を出力
    return 0;
}