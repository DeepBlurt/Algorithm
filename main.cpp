#include <iostream>
#include <cmath>

using namespace std;

void insertSort(int*, int, int);
int partation(int*, int, int);
int find(int*, int, int);
int findNumber(int*, int, int, int);

int main()
{
    int length;
    cout<<"Input number of elements:"<<endl;
    cin>>length;

    int a[length];
    cout<<"Input the elements, seperate by space:"<<endl;
    for(int i=0; i< length; i++){
        cin>>a[i];
    }
    cout<<"Here is what you input:"<<endl;
    for(int i=0; i< length; ++i)
        cout<<a[i]<<" ";
    cout<<endl;

    int order;
    cout<<"Input K:"<<endl;
    cin>>order;

    cout<<find(a, length, order)<<endl;

//    int data_3[15] = {1, 2, 3, 4, 6, 5, 7, 8, 9, 15, 10, 9, 8, 7, 11};
//    insertSort(data_3, 9, 14);
//    for(int i =0; i < 15; ++i)
//        cout<<data_3[i]<<" ";
//    cout<<endl;
//    cout<<partation(data_3, 10, 14)<<endl;

//    cout<<findNumber(data_3, 0, 14, 5)<<endl;
//    for(int i=0; i <15; ++i){
//        cout<<data_3[i]<<" ";
//    }
//    cout<<endl;
}


//Insert sort function
void insertSort(int* data, int start, int end)
{
    int temp;
    for(int i=start+1; i<=end; ++i){
        temp = data[i];
        for(int j=i; j>0 && data[j-1]>temp; --j){
            data[j] = data[j-1];
            data[j-1] = temp;
        }
    }
}


//Partition function
int partation(int* data, int start, int end)
{
    int median = data[start];
    int temp;
    int p= start;

    for(int i=start; i<= end; ++i){
        if(data[i] < median){
            // swap
            temp = data[i];
            data[i] = data[p];
            data[p] = temp;
            p ++;
        }
    }
    return p;
}


// Wrap function
int find(int* data, int len, int order){
    return findNumber(data, 0, len-1, order-1);
}


// Find master element
int findNumber(int* data, int start, int end, int order){
    // the length of data is zero:
    if(start == end)
        return data[start];

    // when subarray's length is smaller than 5, use insert sortation method to find
    if(end - start + 1 <= 5 ){
        insertSort(data, start, end);
        return data[order];
    }
    // Compare
    int part_index;
    part_index = partation(data, start, end);

    if(order == part_index)
        return data[part_index];
    // go to the left part
    else if(part_index < order){
        return findNumber(data, part_index+1, end, order);
    }
    // go to the right part
    else{
        return findNumber(data, start, part_index, order);
    }
}
