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