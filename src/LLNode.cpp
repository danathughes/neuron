#include <iostream>
#include <LLNode.h>

// Modified / borrowed largely from http://www.cplusplus.com/articles/LACRko23/
// Append an object to the list
// Delete an object from the list
// Search for an object in the list

template<class T>
LLNode<T>::LLNode(){

}

template<class T>
LLNode<T>::~LLNode()
{
  // TODO: Once memory management becomes a thing, the destructor needs to go through the list and free all data
}

template<class T>
LLNode<T>::LLNode(const T* const item, LLNode<T>* ptrnext){
  this->data = new T(item);
}

template<class T>
LLNode<T>* LLNode<T>::NextNode(){

}

template<class T>
void LLNode<T>::InsertAfter(LLNode<T>* p){

}

template<class T>
LLNode<T>* LLNode<T>::DeleteAfter(){

}

template<class T>
LLNode<T>* LLNode<T>::GetNode(const T& item, LLNode<T>* nextptr){

}

// TODO: 1) unfuck all this code, 2) implement a scene as an LL of objects, then have the renderer run through and draw them
// TODO: Are we ready for the messagebus yet?
