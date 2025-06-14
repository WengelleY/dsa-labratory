#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
}; 

int main(){
    int n,m;
    cin >> n >> m;

    Node* graph[n+1] = {};

    while (m--){
        int input, u ,v;
        cin >> input;
         if (input == 1 ){
            cin >> u >> v;

            Node* temp = new Node {v,graph[u]};
            graph[u] = temp;

            temp = new Node {u,graph[v]};
            graph[v] = temp ;
         }
         else{
            cin >> u ;
            Node* current = graph[u];
            while (current != NULL){
                cout << current -> val << " ";
                current = current -> next ;
            }
            cout << endl;
         }
    }
    return 0 ;
}