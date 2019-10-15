//SimpleList.cpp
//Olivia Clough

#include "SimpleList.h"
#include <type_traits>

template <class T>
SimpleList<T>::SimpleList() {
  //numElements to 0
  //allocate array of CAPACITY
  elements = new T[CAPACITY];
  numElements = 0;
}

//helper for destructor
template<class T>
void destroy (T element) {
  //do nothing
  return;
}

//helper for destructor
template<class T>
void destroy(T* element) {
  delete element;
}

template <class T>
SimpleList<T>::~SimpleList() {
  //delete dynamic array and elements on heap

  if (std::is_pointer<T>::value){
    for (int x=0; x<numElements-1; x++){
      destroy(elements[x]);
    }
    delete [] elements;
    elements = nullptr;
  }
  else{
    delete [] elements;
  }
}

template <class T>
int SimpleList<T>::getNumElements() const {
  //return number of elements in array
  return numElements;
}

template <class T>
bool SimpleList<T>::empty() const {
  //true if empty
  if (numElements == 0) {return true;}
  else {return false;}
}

template <class T>
T SimpleList<T>::at(int index) const throw(InvalidIndexException) {
  //returns value of element at index, if NULL then throw exception
  if(index < 0 || index >=numElements)
    {
      //throw InvalidIndexException
      InvalidIndexException d;
      throw d;
    }
  else
    {
    return elements[index];
    }
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
  //returns value of first element, if NULL then throw exception
  if(numElements == 0)
    {
      //throw EmptyListException
      EmptyListException e;
      throw e;
    }
    else
      {
	return elements[0];
      }
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
  //returns value of last element, if NULL then throw exception
  if(numElements == 0)
    {
      //throw EmptyListException
      EmptyListException e;
      throw e;
    }
  else
    {
      return elements[numElements-1]; //index of last element is one less than the number of elements in list
    }
}
  

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
  //inserts value at next possible value, if full then throw exception
  if(numElements == CAPACITY)
    {
      //throw FullListException
      FullListException f;
      throw f;
    }
  else
    {
      elements[numElements] = item;
      numElements++;
    }     
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
  //check if empty (exception) then check index (exception) then remove value at index
  if (numElements == 0)
    {
      //throw EmptyListException
      EmptyListException e;
      throw e;
    }
  else if (index <0 || index >numElements)
    {
      //throw InvalidIndexException
      InvalidIndexException i;
      throw i;
    }
  else if(index +1 == numElements){
    //if last value in array
    numElements = numElements -1;
  }
  else
    {
      //all other values
      for (int x=index+1; x<numElements; x++)
	{
	  elements[x-1] = elements[x];
	}
      numElements = numElements-1;
    }
}
