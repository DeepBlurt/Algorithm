#include<iostream>
#include<vector>

using namespace std;

void mergeSort(int*, const int);
int reversePair(int*, int);

// 整理：有关排列的知识，逆序数与归并排序的关系
// 栽在了运算符优先级上，玩完没想到加减运算优先级要高于位移运算符！
// 注意运算符的优先级
// 关系都没有搞清楚就开始写代码，不错才怪
// 竟然对排序的数求逆序数，也是没谁了

int main(){
    // int length;
    // cout<<"Input number of elements:"<<endl;
    // cin>>length;
    
    // int temp;
    // vector<int> v;
    
    // cout<<"Input the elements, seperate by space:"<<endl;
    // for(int i=0; i< length; i++){
    //     cin>>temp;  
    //     v.push_back(temp);
    // }
    // cout<<"Vector size:"<<v.size()<<endl;

    // cout<<"Here is what you input:"<<endl;
    // vector<int>::iterator iter;

    // for(iter = v.begin(); iter != v.end(); ++iter){
    //     cout<<*iter<<" ";
    // }
    // cout<<endl;

    int length;
    cout<<"Input number of elements:"<<endl;
    cin>>length;

    int a[length];
    cout<<"Input the elements, seperate by space:"<<endl;
    for(int i=0; i< length; i++){
        cin>>a[i];
    }
    cout<<"Here is what you input:"<<endl;
    for(int i=0; i<length; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
    
    // cout<<"Merge sort:"<<endl;

    // mergeSort(a, length);
    // for(int i=0; i<length; ++i)
    //     cout<<a[i]<<" ";
    // cout<<endl;

    cout<<"Number of reverse pair:";
    cout<<reversePair(a, length)<<endl;
    
    return 0;
}

//Implentation of mergesort
void merge_sort(int* data, int* temp, const int start, const int end){
    if(start >= end)
        return;
    
    // Split into two parts
    int mid = ((end - start) >> 1) + start;
    int start1 = start; 
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    
    // cout<<"start1:"<<start1<<" end1:"<<end1<<endl;
    
    merge_sort(data, temp, start1, end1);
    merge_sort(data, temp, start2, end2);

    // Merge two parts:
    int k = start;
    while(start1 <= end1 && start2 <= end2)
        temp[k++] = data[start1] < data[start2]? data[start1++]: data[start2++];
    while(start1 <= end1)
        temp[k++] = data[start1++];
    while(start2 <= end2)
        temp[k++] = data[start2++];

    for(k=start; k <= end; k++)
        data[k] = temp[k];
}


// Wrap function
void mergeSort(int* data, const int length){
    int reg[length];
    merge_sort(data, reg, 0, length-1);
}


// Find reverse pairs
void reverse_pair(int* data, int* temp, int start, int end, int& count){
    
    // Check boundary conditions
    if(start >= end)
        return; 
    
    // Split into two parts
    int start1 = start; 
    int mid  = (end + start)>>1;
    int start2 = mid + 1; 
    int end2 = end;
    int end1 = mid;
    
    
    reverse_pair(data, temp, start1, end1, count);
    reverse_pair(data, temp, start2, end2, count);
    
    // Merge and count
    int k = start;
    while(start1 <= end1 && start2 <= end2)
        if(data[start1] <= data[start2])
            temp[k++] = data[start1++];
        else{
            temp[k++] = data[start2++];
            count += start2 - k;
        }
    while(start1 <= end1)
        temp[k++] = data[start1++];
    while(start2 <= end2)
        temp[k++] = data[start2++];
    
    for(k=start; k <= end; k++)
        data[k] = temp[k];
}

int reversePair(int* data, int length){
    int reg[length];
    int count = 0;
    reverse_pair(data, reg, 0, length-1, count);
    return count;
}
