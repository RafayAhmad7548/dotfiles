#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next) : data(data), next(next){}
};

template <class T>
class LinkedList{
    Node<T>* head;
public:
    LinkedList(T data){
        head = new Node<T>(data, nullptr);
    }

    bool insertAtPosition(int position, T data){
        Node<T>* newNode = new Node(data, head);
        if(position == 0){
            head = newNode;
        }
        else{
            for(int i=0;i<position-1;i++){
                newNode->next = newNode->next->next;
            }
            Node<T>* temp = newNode->next;
            newNode->next = newNode->next->next;
            temp->next = newNode;
        }
        return true;
    }

    void printList(){
        Node<T>* temp = head;
        while(temp != nullptr){
            cout<<temp->data;
            temp = temp->next;
        }
    }
};

int main(){

    LinkedList<int> list(1);
    list.insertAtPosition(0, 1);
    list.insertAtPosition(1, 3);
    list.insertAtPosition(2,5);
    list.printList();

    return 0;
}