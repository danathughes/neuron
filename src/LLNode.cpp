#include <iostream>
#include <LLNode.h>

template<class T>
LLNode<T>::LLNode(){

}

template<class T>
LLNode<T>::LLNode(const T& item, LLNode<T>* ptrnext){

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

template<class T>
LLNode<T>::~LLNode()
{

}

// TODO: 1) unfuck all this code, 2) implement a scene as an LL of objects, then have the renderer run through and draw them
// TODO: Are we ready for the messagebus yet?
