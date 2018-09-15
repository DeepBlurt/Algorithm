#include<iostream>

using namespace std;

// function declearation
long span(long*, int);

int main(){
    int length;
    while(true){
        cout<<"Input numbe of elements:"<<endl;
        cin>>length;
        long data[length];
        cout<<"Input elements, split by space:"<<endl;

        for(int i = 0; i < length; i++)
            cin>>data[i]; 

        cout<<"Here is what you input:"<<endl;
        for(int i = 0; i < length; i++)
            cout<<data[i]<<" "; 
        cout<<endl;

        cout<<"Span of number arrays is: "<<span(data, length)<<endl;
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

long maxmin(long* data, int start, int end){
    long maxium = data[start];
    long minium = data[start];
    for(int i = start; i <= end; i++){
        maxium = max(data[i], maxium);
        minium = min(data[i], minium);
    }
    return maxium == minium? 1: maxium - minium;
}


// 
long span_recursive(long* data, int start, int end){
    
    if(start >= end)
        return  1;
    
    int mid = (end + start) >> 1;
    int start1 = start; 
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;

    long prod = 1;
    
    prod *= span_recursive(data , start1, end1);
    prod *= span_recursive(data, start2, end2);

    for(int i = start1; i <= end1; i++){
        for(int j = start2; j <= end2; j++)
            prod *= maxmin(data, i, j);
    }
    return prod >= 1e9+7? (prod % 1000000007): prod;
}

// wrap function
long span(long* data, int length){
    return span_recursive(data, 0, length-1);
}