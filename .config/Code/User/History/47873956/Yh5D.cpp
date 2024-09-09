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
    int size;

    int search(T value){
        Node<T>* temp = head;
        for(int i=0;i<size;i++){
            if(head->data == value) return i;
            temp = temp->next;
        }
        return -1;
    }

public:
    LinkedList(T data){
        head = new Node<T>(data, nullptr);
        size = 1;
    }
    
    void insertAtHead(T data){
        insertAtPosition(0, data);
    }

    void insertAtEnd(T data){
        insertAtPosition(size, data);
    }

    bool insertAtPosition(int position, T data){
        if(position < 0 || position > size) return false;
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
        size++;
        return true;
    }

    bool insertAfterValue(T value, T data){
        int index = search(value);
        return insertAtPosition(index+1, data);
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
    list.insertAtHead(1);
    list.insertAtPosition(1, 3);
    list.insertAtEnd(5);
    list.insertAfterValue(3, 10);
    list.printList();

    return 0;
}