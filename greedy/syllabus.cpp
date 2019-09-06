#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Task{
    bool occupy;
    int timeline;
    bool flag1;
    bool flag2;

    Task(bool occupy, int j, bool k , bool k2){
        this->occupy = occupy;
        this->timeline = j;
        this->flag1 = k;
        this->flag2 = k;
    }
};

// declaration
int schedule(vector<int> &timeline);
int allocate(vector<Task>&, int &, int, int);


int main(){
    int n;
    vector<int> timeline;

    cout << "Input number of students:" << endl;
    cin >> n;

    cout<< "Input time consume of each student: " << endl;
    int temp;
    for(auto i = 0; i < n; i ++)
        cin >> temp, timeline.push_back(temp);

    cout << "You input:" << "students :" << n << " time: ";
    for(auto i = 0; i < n; i ++)
        cout << " " << timeline[i];
    cout << endl;

    cout << "The minimum time consume is: " << schedule(timeline) << endl;

    return 0;
}


int schedule(vector<int> & timeline){

    vector<Task> task;
    int num_people = (int)timeline.size();

    for(int i = 0; i < num_people; i++){
        task.emplace_back(Task(false, timeline[i], true, true));
    }

    int end_time_1 = 0;
    int end_time_2 = 0;
    int find1 = -1;
    int find2 = -1;

    while(true){

        if (end_time_1 < end_time_2){
            find1 = allocate(task, end_time_1, num_people, 1);
        }

        else if(end_time_2 < end_time_1){
            find2 = allocate(task, end_time_2, num_people, 2);
        }

        else{
            find1 = allocate(task, end_time_1, num_people, 1);
            find2 = allocate(task, end_time_2, num_people, 2);
        }

        if(find1 == -2 and find2 == -2)
            break;

        if(end_time_1 < end_time_2 and find1 != -2){
            task[find1].occupy = false;
        }

        else if(end_time_1 > end_time_2 and find2 != -2){
            task[find2].occupy = false;
        }
        else if(find1 != -1 and find2 != -1){
            task[find1].occupy = false;
            task[find2].occupy = false;
        }
    }
    return end_time_1 >= end_time_2? end_time_1 :end_time_2;
}



int allocate(vector<Task>& task, int & end_time, int num_people, int id){
    int max = 0;
    int iter;
    int find = -1;

    if(id == 1) {
        for (iter = 0; iter < num_people; iter++) {
            if (max < task[iter].timeline and task[iter].flag1 and !task[iter].occupy) {
                    max = task[iter].timeline;
                    find = iter; // found the job that spend longest time
                    end_time += max;
                    task[iter].occupy = true;
                    task[iter].flag1 = false;
            }
        }

        for(iter=0; iter < num_people; iter++){
            if(task[iter].flag1)
                return find;
        }
        return -2;
    }


    if(id==2){
        for (iter = 0; iter < num_people; iter++) {
            if (max < task[iter].timeline and task[iter].flag2) {
                if(!task[iter].occupy) {
                    max = task[iter].timeline;
                    find = iter; // found the job that spend longest time
                    end_time += max;
                    task[iter].occupy = true;
                    task[iter].flag2 = false;
                }
                else
                    find = -2; // all jobs finished
            }
        }

        for(iter=0; iter < num_people; iter++){
            if(task[iter].flag2)
                return find;
        }
        return -2;
    }
}


//void quick_sort(vector<int> & seq){
//    quick_sort_recursive(seq, 0, (int)seq.size()-1);
//}
//
//void quick_sort_recursive(vector<int> & seq, int start, int end){
//    if(start >=  end)
//        return;
//    int pivot = (start + end) >> 1;
//    int newPivot = partition(seq, start, end, pivot);
//    quick_sort_recursive(seq, start, newPivot);
//    quick_sort_recursive(seq, newPivot+1, end);
//}
//
//
//int partition(vector<int> & seq, int start, int end, int pivot){
//    int baseline = seq[pivot];
//    int temp;
//    tem  p = seq[pivot], seq[pivot] = seq[end], seq[end] = temp;
//
//    int p = start;
//    for(int i = start; i <= end; i ++){
//        if(seq[i] > baseline){
//            temp = seq[i], seq[i] = seq[p], seq[p] = temp;
//            p++;
//        }
//    }
//    temp = seq[end], seq[end] = seq[p], seq[p] = temp;
//    return p;
//}
