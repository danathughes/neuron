#pragma once

#include <iostream>

using namespace std;

template<class T>
class LLNode
{
	public:
		LLNode();
		LLNode(const T& item, LLNode<T>* ptrnext = NULL);
		~LLNode();

    LLNode<T>* NextNode();
    void InsertAfter(LLNode<T>* p);
    LLNode<T>* DeleteAfter();
    LLNode<T>* GetNode(const T& item, LLNode<T>* nextptr = NULL);

		T data;
  private:
        LLNode<T>* next;
};
