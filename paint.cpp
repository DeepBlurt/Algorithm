/*
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005];
int get(int l,int r)
{
    int minn=1e9+3;
    for(int i=l;i<=r;i++)
    {
        minn=min(minn,a[i]);
    }
    int ans=minn;
    for(int i=l;i<=r;i++)
    {
        if(a[i]==minn)
            continue;
        int ii=i+1;
        while(ii<=r&&a[ii]!=minn)
            ii++;
        ii--;
        for(int j=i;j<=ii;j++)
            a[j]-=minn;
        ans+=get(i,ii);
        i=ii;
    }
    return min(r-l+1,ans);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n",get(0,n-1));
    }
    return 0;
}
*/
/*
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[5678];
int dfs(int l,int r,int k)
{
    if(l>r||(l==r&&a[l]<=k)) return 0;
    if(l==r) return 1;
    //注意区间左闭右开 只有这里r+1考虑右边界
    int mn=min_element(a+l,a+r+1)-a;
    //注意-k
    return min(r-l+1,dfs(l,mn-1,a[mn])+dfs(mn+1,r,a[mn])+a[mn]-k);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        //区间严格[l,r]
        //如果用0,n注意所有地方都要改
        printf("%d\n",dfs(0,n-1,0));
    }
    return 0;
}

*/
#include<iostream>

using namespace std;

// Function declearation
int paint(int*, int);

int main(){
    int length;
    while(true){
        cout<<"Input numbe of elements:"<<endl;
        cin>>length;

        int data[length];
        cout<<"Input elements, split by space:"<<endl;

        for(int i = 0; i < length; i++)
            cin>>data[i]; 

        cout<<"Here is what you input:"<<endl;
        for(int i = 0; i < length; i++)
            cout<<data[i]<<" "; 
        cout<<endl;

        cout<<"Number need to paint: "<<paint(data, length)<<endl;
        cout<<"Quit or not(y/n):";
        
        char quit;
        cin>>quit;
        if(quit == 'y' || quit == 'Y')
            break;
        else
            continue;

    }
    return 0;
}


// Search the result, using recursive calling
int search(int* data, int start, int end){
    
    // Find minma of data
    int minma = data[start];
    for(int i = start + 1; i <= end; i++)
        minma = min(data[i], minma);
    int count = minma;

    // All elements substract manma of data
    for(int i = start; i <= end; i++)
        data[i] -= minma;

    int left;
    int right;

    for(int point = start; point <= end; point++){
        
        // skip zeors before
        if(!data[point])
            continue;
        
        // Find sub-array and call recursively
        left = point;
        right = point + 1;
        while(right <= end && data[right])
            right ++;
        right --;
        count += search(data, left, right);
        
        point = right + 1;
    }
    return min(count, end-start+1);
}


// Wrap function
int paint(int* data, int length){
    return search(data, 0, length-1);
}