#include <iostream>
#include <string>
#include <fstream>

#define MAX 1000

using namespace std;

int main(){
    string filename;
    int g_count = 0;
    int arr[MAX], i, j, key;
    cout << "enter the problem file name\n";
    cin >> filename;
    fstream in(filename);
    if(in.is_open()){
        for(int i = 0 ; i < MAX ; i++){
        in >> arr[i];
    }
    }
    for(int i = 1; i < MAX; i++){
        key = arr[i]; g_count++;
        j = i - 1; g_count++;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]; g_count++;
            j = j - 1; g_count++;
        }
        arr[j + 1] = key; g_count++;
    }

    cout << "Sorted result\n";
    for(int i =0 ; i < MAX; i++){
        cout <<  arr[i] << " ";
    }
    cout << "g_count : " << g_count << "\n";
    return 0;
}