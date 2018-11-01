#include <iostream>
#include <vector>


using namespace std;

int mls(vector<int>&);
int mls_bin(vector<int>&);
void replace(int, vector<int>& );
void test();

// ref: https://zhuanlan.zhihu.com/p/25173305
// https://www.jianshu.com/p/92fcc395446e

int main() {

    vector<int> seq;
    int length;
    int temp;

    test();

    cout<<"Input number of series:"<<endl;
    cin>>length;

    cout<<"Input series, split by space:"<<endl;
    for(int i=0; i< length; i++){

        cin >> temp;
        seq.push_back(temp);
    }
    cout<<"The number series you input is:"<<endl;
    for(int i = 0; i < length; i++)
        cout<< seq[i] << " ";
    cout<<endl;

    cout<< "The longest non descending sequence's length is "<<mls(seq)<<". "<<endl;

    cout<< "The longest non descending sequence's length is "<<mls_bin(seq)<<". "<<endl;

    return 0;
}


int mls(vector<int>& a){

    int len = (int)a.size();
    //vector<int> dynamic;
    int dynamic[len];

    for(int i = 0; i < len; i++)
        dynamic[i] = 1;


    for(int i = len - 2; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (a[j] >= a[i] && dynamic[j]+1 > dynamic[i])
                dynamic[i] = dynamic[j] + 1;
        }
    }

    int max_dp = dynamic[0];

    for (int i=1; i < len; i++){
        max_dp = dynamic[i] > max_dp? dynamic[i]: max_dp;
    }
    return max_dp;
}


int mls_bin(vector<int>& a){

    vector<int> bin;

    bin.push_back(a[0]);
    for(int i = 1; i < a.size();  i++){
        if(a[i] > bin[bin.size()-1])
            bin.push_back(a[i]);
        else{
            replace(a[i], bin);
        }
    }

    for(int n: bin )
        cout<< n << " ";
    cout<<endl;

    return (int)bin.size();
}


void replace(int a, vector<int>& b){

    int left = 0;
    int right = (int)b.size()-1;

    // binary search
    while(left <= right) {
        int mid = (right + left) >> 1;
        if (b[mid] < a)
            left = mid + 1;
        else if (b[mid] > a)
            right = mid - 1;
        else
            return;
    }

    b[left] = a;
}

void test(){
    vector<int> a;
    a.push_back(2);
    replace(1, a);

    vector<int> b;
    b.push_back(1);
    b.push_back(3);
    replace(2, b);

    vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(5);
    c.push_back(7);

    replace(4, c);

    for(int i = 0; i < a.size(); ++i)
        cout<<a[i]<<" "<<endl;

    for(int i = 0; i < b.size(); ++i)
        cout<<b[i]<<" ";
    cout<<endl;

    for(int i = 0; i < c.size(); ++i)
        cout<<c[i]<<" ";
    cout<<endl;
}