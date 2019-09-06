//
// Created by ax on 18-11-8.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int bracket(string&);


int main(){

    string s;
    cout<<"Input brackets series:"<<endl;
    int test;
    cout<<"Initialize value of integral:"<<test<<endl;

    cin>>s;
    cout<<"You input:"<<s<<endl;

    cout<<"Number of balanced pair of brackets is:"<<bracket(s)<<endl;
    return 0;
}


int bracket(string& s){

    int length =  (int)s.size();
    int mod = 1000000007;

    vector<int> dp;
    for(int i = 0; i < length; ++i){
        dp.push_back(0);
    }
    dp[0] = 1;

    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '('){
            for(int j = length - 2; j >= 0 ; --j)
                dp[j + 1] += dp[j], dp[j + 1] %= mod;
        }
        else if(s[i] == ')'){
            for(int j = 1; j < length; j++)
                dp[j-1] += dp[j], dp[j-1] %= mod;
        }
    }

    return dp[0] - 1;
}

// ref: https://blog.csdn.net/mengxiang000000/article/details/54564214

int bracket_single(string& s){

    int length =  (int)s.size();
    int mod = 1000000007;

    vector<int> dp;
    for(int i = 0; i < length; ++i){
        dp.push_back(0);
    }

    int mod = 1000000007;
    for(int i = 1; i < = s.size(); i++)
        if(s[i] == '(')

}


//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 1e6+7;
//int stk[maxn],dp[maxn],now,len,p[maxn];
//long long ans;
//char s[maxn];
//int main()
//{
//    scanf("%s",s+1);len=strlen(s+1);
//    for(int i=1;i<=len;i++)
//    {
//        if(s[i]=='(')stk[now++]=i;
//        else if(s[i]==')'&&now!=0)p[i]=stk[--now];
//        if(!p[i])continue;
//        dp[i]=dp[p[i]-1]+1;
//        ans+=dp[i];
//    }
//    cout<<ans<<endl;
//}