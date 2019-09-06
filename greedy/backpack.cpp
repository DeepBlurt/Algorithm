#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <list>
using namespace std;

float part_pack(list<array<float, 3>> &, int);
array<float, 3>& list_at(list<array<float, 3>> &, int);
void sort_by_avg(list<array<float, 3>> &);
array<float, 3>& list_modify(list<array<float, 3>>&, int, array<float, 3>&);

//int main() {
//    array<float, 3> object = {0, 0, 0};
//    list<array<float, 3>> seq;
//
//    int n, v;
//    cin >> n;
//    cin >> v;
//    cout << "Number of kind:" << n << " value of total capacity:" << v << endl;
//    float temp1, temp2;
//
//    for(int i = 0; i < n; i++) {
//        cin >> temp1;
//        cin >> temp2;
//        object[0] = temp1, object[1] = temp2;
//        object[2] = temp2 / temp1;
//
//        seq.push_back(object);
//    }
//
//    for(auto a : seq)
//        cout << "capacity:" << a[0] << " value: " << a[1] << " avg:" << a[2] << endl;
//
//    cout<< "Total value is: "<< part_pack(seq, v)<< endl;
//
//    return 0;
//}


float part_pack(list<array<float, 3>> & seq, int v){
    sort_by_avg(seq);

    // allocate in a greedy way
    float capacity_left = v;
    float total_value = 0;

    for(int i = 0; i < seq.size(); i++){
        if(capacity_left >= list_at(seq, i)[0])
            capacity_left -= list_at(seq, i)[0], total_value += list_at(seq, i)[0] * list_at(seq, i)[2];
        else
            total_value += capacity_left * list_at(seq, i)[2], capacity_left = 0;

        if(capacity_left == 0)
            return total_value;
    }
    return total_value;
}


void merge_sort_recursive(list<array<float, 3>>& seq, list<array<float, 3>>& reg,const int start,const int end){
    if(start >= end)
        return;

    int mid = (end + start) >> 1;
    int start1 = start, start2 = mid + 1;
    int end1 = mid, end2 = end;

    // recursively calling
    merge_sort_recursive(seq, reg, start1, end1);
    merge_sort_recursive(seq, reg, start2, end2);

    // merge
    int k = start;
    while(start1 <= end1 && start2 <= end2){
        if(list_at(seq, start1)[2] > list_at(seq, start2)[2]){
            list_modify(reg, k, list_at(seq, start1));
            start1 ++;
        }
        else{
            list_modify(reg, k , list_at(seq, start2));
            start2 ++;
        }
        k++;
    }
    while(start1 <= end1){
        list_modify(reg, k, list_at(seq, start1));
        start1 ++, k ++;
    }
    while(start2 <= end2){
        list_modify(reg, k, list_at(seq, start2));
        start2 ++; k++;
    }
    for(int iter = start; iter <= end; iter++){
        list_modify(seq, iter, list_at(reg, iter));
    }
}


void sort_by_avg(list<array<float, 3>>& seq){
    list<array<float, 3>> reg;
    array<float, 3> occupy = {0, 0, 0};
    for(int iter = 0; iter < seq.size(); iter ++)
        reg.push_back(occupy);

    merge_sort_recursive(seq, reg, 0, (int)seq.size()-1);
}


array<float, 3>& list_at(list<array<float, 3>>& seq, int index){
    int i = 0;
    if(index >= seq.size() ||index < 0)
        throw "Index Out of Range!";
    for(auto it = seq.begin(); it != seq.end(); ++it) {
        if (i == index)
            return *it;
        i++;
    }
}

array<float, 3>& list_modify(list<array<float, 3>>& seq, int index, array<float, 3>& array){
    int i = 0;
    if(index >= seq.size() ||index < 0)
        throw "Index Out of Range!";
    for(auto it = seq.begin(); it != seq.end(); ++it) {
        if (i == index){
            list_at(seq, index)[0] = array[0];
            list_at(seq, index)[1] = array[1];
            list_at(seq, index)[2] = array[2];
        }
        i++;
    }
}
