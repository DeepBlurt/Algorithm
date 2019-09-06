# include<iostream>
# include<string>
# include <ctime>
# include<cstring>


void permutation(int n, int k){
    char ans[11], start[10];
    bool isUsed[11];

    for(int i = 0; i < n; i ++){
        if(!isUsed[i]){
            ans[k] = i + '0';
            isUsed[i] = 1;
            if(k == n){
                ans[k+1] = '\0';
                sscanf(ans+1, "%d", &sum[len++])
            }
        }
    }
}
