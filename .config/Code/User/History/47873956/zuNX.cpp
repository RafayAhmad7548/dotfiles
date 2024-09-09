#include <iostream>
using namespace std;

template <class T>
class Node{
    T data;
    Node<T>* next;
public:
    Node(T data, Node<T>* next) : data(data), next(next){}
};

template <class T>
class LinkedList{
    Node<T>* head;
    int size;
public:
    LinkedList(T data){
        Node<T> node(data, nullptr);
        head = &node;
        size = 1;
    }

    bool insertAtPosition(int position, T data){
        Node<T> newNode(data, head);
        for(int i=0;i<position-1;i++){
            newNode = newNode->next;
        }
        Node<T> temp = newNode->next;
        newNode = newNode->next;
        temp->next = newNode;
        size++;
    }

    void printList(){
        Node<T> temp = *head;
        for(int i=0;i<size;i++){
            cout<<temp.data;
            temp = temp->next;
        }
    }
};

int main(){

    LinkedList<int> list(1);
    list.insertAtPosition(0, 1);

    return 0;
}