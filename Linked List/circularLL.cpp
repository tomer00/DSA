#include <iostream>
using namespace std;
class Node {
    int data;
    Node* next = NULL;
};

class CircularLL{
private:
    Node* root = NULL;
    Node* curr = NULL;
public:
    CircularLL() {
        
    }
    void addNode(int val){

    }
    bool delNode(int val){

    }
    int forward(){

    }
    int backward(){

    }
    void printList(){

    }
};

int main() {

    CircularLL ll;

    int c, val;
    printf("1 : Insert \n");
    printf("2 : Remove \n");
    printf("3 : Forward \n");
    printf("4 : Backward \n");
    printf("5 : Print \n");
    do {
        printf("\nEnter operation no. : ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter val to Insert : ");
            scanf("%d", &val);
            ll.addNode(val);
            printf("Inserted : %d", val);
            break;
        case 2:
            printf("Enter val to Remove : ");
            cin >> val;
            cout << (ll.delNode(val) ? "Node deleted" : "Node not found");
            break;
        case 3:
            cout << "Current pointer moved to: "<<ll.forward();
            break;
        case 4:
            cout << "Current pointer moved to: "<<ll.backward();
            break;
        case 6:
            ll.printList();
            break;
        }

    } while (c != -1);
    return 0;
}
