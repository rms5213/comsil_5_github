#ifndef STACK
#define STACK
#include "LinkedList.h"
using namespace std;

//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//LinkedList class를 상속받음
template <class T>
class Stack:public LinkedList<T> {
        public:
                bool Delete(T &element);
};

template <class T>

//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함
// LinkedList의 Delete는 뒤의 데이터부터 삭제하지만
// Stack의 Delete는 앞의 데이터부터 삭제
bool Stack<T>::Delete(T &element) {
        //first가 0이면 false반환
        if(this->first == NULL) {
                return false;
        }
        // LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
        Node<T> *tmp = this->first;
        element = this->first->data;
        this->first = this->first->link;
        this->current_size--;
        delete tmp;
        return true;
}
#endif
