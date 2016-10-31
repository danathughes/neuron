#pragma once

#include <iostream>

using namespace std;

template<class T>
class LLNode
{
	public:
		LLNode();
		LLNode(const T* const item, LLNode<T>* ptrnext = NULL);
		~LLNode();

    LLNode<T>* NextNode();
    void InsertAfter(LLNode<T>* p);
    LLNode<T>* DeleteAfter();
    LLNode<T>* GetNode(const T& item, LLNode<T>* nextptr = NULL);

		T* data;
  private:
    LLNode<T>* next;
};

template<class T>
LLNode<T>::LLNode(const T* const item, LLNode<T>* ptrnext){
  this->data = new T(item);
}
