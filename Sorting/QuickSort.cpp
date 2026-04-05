#include <iostream>
#include <string>
#include <fstream>

#define MAX 1000

using namespace std;

int g_count = 0;

static int partitioning(int A[], int left, int right){
    int low = left;
    int high = right+1;
    int pivot = A[left];
    int temp = 0;
    g_count += 4;
    do {
        do{
            low++;
        } while(low<=right && A[low]<pivot);
        do{
            high--; g_count++;
        } while(high>=left && A[high]>pivot);
        if(low<high){
            temp = A[low];
            A[low] = A[high];
            A[high] = temp;
            g_count+=3;
        }
    }while(low<high);

    int temp2 = A[left];
    A[left] = A[high];
    A[high] = temp2;
    g_count+=3;

    return high;
}

void quickSort(int A[], int left, int right){
    if(left < right){
        g_count++;
        int q = partitioning(A, left, right);
        quickSort(A, left, q-1);
        quickSort(A, q+1, right);
    }
}

int main(){
    string filename;
    int n = MAX;
    int list[n];
    cout << "enter the problem file name\n";
    cin >> filename;
    fstream in(filename);
    if(in.is_open()){
        for(int i = 0 ; i < n ; i++){
        in >> list[i];
    }
    }
    quickSort(list, 0, n-1);

    for(int i =0 ; i < MAX; i++){
        cout <<  list[i] << " ";
    }
    
    cout << "g_count : " << g_count << "\n";
    return 0;
}