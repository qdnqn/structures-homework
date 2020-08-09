#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include <functional>

template<typename ListType>
struct Node {
  Node() = default;
  Node(const ListType& val) : value{val}{};
  Node<ListType>* next{nullptr};
  ListType value;
};

template<typename ListType>
class Lista {
  public:
    Lista() = default;
    Lista(Lista<ListType>& l) : head{l.getHead()}, size{l.getSize()}{};

    Lista(Lista<ListType>&& l) : head{l.getHead()}, size{l.getSize()}{
      l.reset();
    };

    Lista& operator=(Lista<ListType>& l);
    Lista& operator=(Lista<ListType>&& l);

    ~Lista(){
      Node<ListType> *curr = head;

      while(curr->next != nullptr){
        auto temp = (*head).next;
        delete curr;
        curr = temp;
      }
    };

    class Iterator;
    
    Iterator begin();
    Iterator end();
    Iterator find(std::function<bool(const Node<ListType>& node)> condition);
    Iterator remove(Iterator el);
    
    Node<ListType>* getHead(){
      return head;
    }

    size_t getSize(){
      return size;
    }

    void reset(){
      head = nullptr;
      size = 0;
    }
    void add(const ListType& value);
    void sortedInsert(Node<ListType> **sorted, Node<ListType> *current);
  private:
    Node<ListType> *head, *tail, *beforeTail;
    size_t size{0};
};

template<typename ListType>
class Lista<ListType>::Iterator {
  public:
    Iterator() = default;
    Iterator(Node<ListType>* node) : current{node}, previous{nullptr}{};

    Iterator operator++(){
      previous = current;
      current = current->next;

      return *this;
    }

    Iterator operator++(int){
      auto old = *this;
      current = current->next;

      return old;
    }
    
    Node<ListType>* operator&(){
      return current;
    }

    bool operator!=(const Iterator& it){
      return current != it.current;
    } 

    Node<ListType>& operator*(){
      return *current;
    }
  private:
    Node<ListType> *current, *previous;
};

template<typename ListType>
void Lista<ListType>::add(const ListType& val){
  if(size){
    Node<ListType> *newNode = new Node<ListType>(val);

    newNode->next = head;
    head = newNode;
    
    Node<ListType> *sorted = nullptr;
    Node<ListType> *current = head;

    while(current != nullptr){
      Node<ListType> *next = current->next;
      
      sortedInsert(&sorted, current);
      current = next;
    }

    head = sorted;
  } else {
    head = new Node<ListType>(val);
  } 
  
  size++;
}

template<typename ListType>
void Lista<ListType>::sortedInsert(Node<ListType> **sorted, Node<ListType> *newNode){
  Node<ListType> *current;

  if(*sorted == nullptr || (*sorted)->value >= newNode->value){
    newNode->next = *sorted;
    *sorted = newNode;
  } else {
    current = *sorted;

    while(current->next != nullptr && current->next->value < newNode->value){
      current = current->next;
    }  

    newNode->next = current->next;
    current->next = newNode;
  }
}

template<typename ListType>
typename Lista<ListType>::Iterator Lista<ListType>::find(std::function<bool(const Node<ListType>& node)> condition){
  auto it = begin();

  while(it != end()){
    if(condition(*it)){
      return it;
    }

    ++it;
  }

  return end();
}

template<typename ListType>
typename Lista<ListType>::Iterator Lista<ListType>::remove(Lista<ListType>::Iterator it){
  if(it != nullptr){
    auto current = begin();
    
    if((*it).value == (*current).value){
      ++it;
      delete head;
      head = &it;
    } else {
      while(current != end()){
        auto element = &current;
        auto nextEl = ++current;
              
        if((*nextEl).value == (*it).value){          
          (*element).next = (*nextEl).next;
          delete &nextEl;

          break;
        } 
      }
    }
  }
}

template<typename ListType>
typename Lista<ListType>::Iterator Lista<ListType>::begin(){
  return Iterator(head);
}

template<typename ListType>
typename Lista<ListType>::Iterator Lista<ListType>::end(){
  return Iterator(nullptr);
}

#endif
