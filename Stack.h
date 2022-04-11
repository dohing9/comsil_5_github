#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first==0)
				return false;

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T>*current=this->first;//this->first, 즉 리스트의 첫 노드를 current로 받아온다.
			this->first=current->link;//다음 노드를 첫노드로 설정해준다
			element=current->data;//element에 current->data저장 
			this->current_size--;//current사이즈 -1
			delete current;//current 삭제
			return true;
			}
};
