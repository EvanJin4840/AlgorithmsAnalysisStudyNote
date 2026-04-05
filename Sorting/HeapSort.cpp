#include <iostream>
#include <string>
#include <fstream>
#define MAX 1000

using namespace std;

void build_max_heap(int arr[], int n);
void max_heapify(int arr[], int n, int i);

int g_count = 0;

int main(){
    string filename;
    int arr[MAX], i, j, key;
    cout << "enter the problem file name\n";
    cin >> filename;
    fstream in(filename);
    if(in.is_open())
        for(int i = 0 ; i < MAX ; i++){
        in >> arr[i];
    }
    int n = MAX;
    build_max_heap(arr, n);

    cout << "Sorted result\n";
    for(int i =0 ; i < MAX; i++){
        cout <<  arr[i] << " ";
    }
    cout << "g_count : " << g_count << "\n";

    return 0;
}

void max_heapify(int arr[], int n, int i){
    int largest = i; g_count++;
    int l = i*2+1; g_count++;
    int r = i*2+2; g_count++;
    if(l < n && arr[l]>arr[largest]){
        largest = l; g_count++;
    }
    if(r < n && arr[r]>arr[largest]){
        largest = r; g_count++;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp; g_count+=3;
        max_heapify(arr, n, largest); g_count++;
    }
}
void build_max_heap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        g_count++;
        max_heapify(arr, n, i);
    }
    for(int i = n-1;i>=0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        g_count+=3;
        max_heapify(arr, i, 0);
    }
}