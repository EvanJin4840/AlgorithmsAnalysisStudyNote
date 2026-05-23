#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
    int id;
    char name[20];
    int status = -1; // 0이면, 왼쪽 자식 있고, 1이면 둘다 꽉참.
    Node(){
        id = -1;
    }
};

class Graph{
private:
    Node nodes[100];
    int nodeCount;
    int adjMatrix[100][100];

public: 
    Graph() {
        nodeCount = 0;
        for(int i = 0 ; i < 100 ; i ++){
            for(int j = 0 ; j < 100 ; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }
    int MakeGraph(int max)
    {
        int par, chi, max1 = max;
        char name[20];
        char parent[20];
        char child[20];
        cout << "What is the node Count?" << endl;
        cin >> nodeCount;
        max = nodeCount;
        for(int i = 0 ; i < nodeCount; i ++){
            cout << "Please enter the node's name" << endl;
            cin >> nodes[i+1].name;
            nodes[i+1].id = i + 1;
        }
        for(int i = 1; i < nodeCount; i++){
            cout << "Please enter the node's parent-child relationship Parent(index): ";
            cin >> par;//부모노드를 입력받는데, 그것을 자식노드에 연결시키는 방법
            cout << "Child: ";
            cin >> chi;
            adjMatrix[par][chi] = 1;
        }
        return max;
    }
    void ShowGraph(int max1){
        cout << "if row has child, it is marked as 1\n";
        cout << "            ";
        for(int i = 1 ; i < max1+1 ; i ++){
            cout << "[" << right << setw(9) << nodes[i].name << "]" << " ";
        }
            cout << endl;
        for(int i =1 ; i < max1+1 ; i ++){
            cout << "[" << right << setw(9) << nodes[i].name << "]" << "       ";
            for(int j = 1 ; j < max1+1 ; j++){
                cout << adjMatrix[i][j];
                cout << "           ";
            }
            cout << endl;
        }
    }
};

int main(){
    int max = 0;
    Graph g;
    char ans;
    cout << "Wanna make a graph? (yes: y, no: n): ";
    cin >> ans;
    if(ans == 'n'){
        cout << "program is terminated" << endl;
        return 0;
    }
    else{
        max = g.MakeGraph(max);
        g.ShowGraph(max);
    }

    return 0;
}