#include <iostream>
#include <iomanip>

using namespace std;

struct Node{
    int id;
    Node() {
        id = -1;
    }
    Node(int nid){
        id = nid;
    }
};

class Graph{
private:
    Node nodes[100];
    int nodeCount;
    int adjMatrix[100][100];

public: 
    int edgeCount;
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
        int s, d, w, n, max1 = max;
        cout << "What is the node Count?" << endl;
        cin >> nodeCount; 
        for(int i = 0 ; i < nodeCount; i ++){
            Node(i+1);//노드번호 1부터 노드 생성.
        }
        cout << "What is the edge Count?" << endl;
        cin >> edgeCount;
        for(int i = 0 ; i < edgeCount ; i++){
            cout << "Please enter the edge's start node, destination node, and its weight" << endl;
            cin >> s >> d >> w;
            if(s>d){
                n = s;
            }
            else{
                n = d;
            }
            if(n>max1){
                max1 = n;
            }
            adjMatrix[s][d] = w;

            
        }
        return max1;
    }
    void ShowGraph(int max1){
        cout << "    ";
        for(int i = 1 ; i < max1+1 ; i ++){
            cout << "[" << i << "]" << "  ";
        }
            cout << endl;
        for(int i =1 ; i < max1+1 ; i ++){
            cout << "[" << i << "]" << "  ";
            for(int j = 1 ; j < max1+1 ; j++){
                cout << right << setw(2) << adjMatrix[i][j];
                cout << "   ";
            }
            cout << endl;
        }
    }
};

int main(){
    int max = 0;
    Graph g;
    while(1){
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
    }

    return 0;
}