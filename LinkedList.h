#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
using namespace std;

template <class T>
// Linked List Node
class Node {
public:
        T data; // 데이터를 저장할 변수
        Node *link; // 노드구조체 이용; 다음 노드의 주소를 저장할 포인터
        Node(T element)
        {
                data = element;
                link = NULL;
        }
};

// Linked List Class
template <class T>
class LinkedList
{
        protected:
                Node<T> *first; // 첫번째 노드의 주소를 저장할 포인터
                int current_size;
        public:
                LinkedList() // 생성자 초기화
                {
                        first = 0;
                        current_size = 0;
                };
                int GetSize() { return current_size; }; // 노드 개수를 리턴
                void Insert(T element); // 맨 앞에 원소를 삽입, LinkedList와 Stack 둘 다 같다.
                virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제
                void Print(); // 리스트 출력
};

// 새 노드를 맨 앞에 붙이고 값을 넣음
template <class T>
void LinkedList<T>::Insert(T element)
{
        //노드 생성
        Node<T> *newnode = new Node<T>(element);
        //새 노드가 첫번째 노드를 가리킴
        //newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
        newnode->link = first;
        first = newnode;
        current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <class T>
bool LinkedList<T>::Delete(T &element)
{
        if (first == 0)
                return false;
        Node<T> *current = first;
        Node<T> *previous = NULL;
        //마지막 노드까지 찾아가는 반복문
        while (1)
{
                if (current->link == 0) // 마지막 노드를 찾는 것
                {
                        if (previous) previous->link = current->link;
                        else first = first->link;
                        break;
                }
                previous = current;
                current = current->link;
        }
        element = current->data;
        delete current;
        current_size--;
        return true;
}

//리스트를 출력하는 Print 함수
template <class T>
void LinkedList<T>::Print()
{
        Node<T> *i = first;
        int index = 1;
        if (current_size != 0){
                for(i = first; i != NULL; i = i->link) {
                        if (index == current_size){
                                cout << "[" << index << "|";
                                cout << i -> data <<"]->";
                        }

                        else {
                                cout << "[" << index << "|";
                                cout << i -> data << "]->";
                                index++;
                        }
                }
                cout << endl;
        }
}
#endif
