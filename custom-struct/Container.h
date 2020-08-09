#ifndef CONTAINER_H
#define CONTAINER_H

#include <algorithm>
#include <stdexcept>

template<typename NumberType> class Container{
  public:
    Container(size_t n) : ptr_{new NumberType[n]}, n_{n}, e_{0} {};
    Container(const Container<NumberType>& niz) : ptr_{new NumberType[niz.velicina()]}, n_{niz.velicina()}, e_{niz.elements()} {
      std::copy(niz.ptr(), niz.ptr()+niz.velicina(), ptr_);
    }
    
    Container(const Container<NumberType>&& niz) : ptr_{new NumberType[niz.velicina()]}, n_{niz.velicina()}, e_{niz.elements()} {
      std::copy(niz.ptr(), niz.ptr()+niz.velicina(), ptr_);
      niz.clear();         
    }

    Container& operator=(const Container& niz){
      ptr_ = new NumberType[niz.velicina()];
      n_ = niz.velicina();
      e_ = niz.elements();

      std::copy(niz.ptr(), niz.ptr()+niz.velicina(), ptr_);
    }  

    Container& operator=(const Container&& niz){
      ptr_ = new NumberType[niz.velicina()];
      n_ = niz.velicina();
      e_ = niz.elements();

      std::copy(niz.ptr(), niz.ptr()+niz.velicina(), ptr_);
      niz.clear();
    }
  
    ~Container(){ delete [] ptr_; }

    NumberType* ptr(){ return ptr_; }
    size_t velicina(){ return n_; }
    size_t elements() { return e_; }
    
    void clear(){
      ptr_ = nullptr;
      n_ = 0;
      e_ = 0;
    }

    void push(const NumberType& n);
    void pop();
    const NumberType& back();
    NumberType accumulate() const;
    NumberType cumulativeProduct() const;
    NumberType min();
    NumberType max();
  private:
    size_t n_;
    size_t e_;
    NumberType *ptr_{nullptr};    
};

template<typename NumberType>
void Container<NumberType>::push(const NumberType& num){
    if(n_ != e_){
        *(ptr_+e_) = num;
        ++e_;
    } else {
     throw std::length_error("Niz je pun.");
    }
}

template<typename NumberType>
void Container<NumberType>::pop(){
    delete (ptr_+n_);
    ptr_+n_ = nullptr;
    --n_;
}

template<typename NumberType>
const NumberType& Container<NumberType>::back(){  
  return *(ptr_+e_-1);
}

template<typename NumberType>
NumberType Container<NumberType>::accumulate() const {
  NumberType temp;
  
  for(size_t i=0; i<n_; ++i){
    temp = temp + *(ptr_+i);  
  }

  return temp;
}


template<typename NumberType>
NumberType Container<NumberType>::cumulativeProduct() const {
  NumberType temp;
  
  for(size_t i=0; i<n_; ++i){
    temp = temp * (*(ptr_+i));  
  }

  return temp;
}

template<typename NumberType>
NumberType Container<NumberType>::max() {
  NumberType temp = *ptr_;
  
  for(size_t i=0; i<n_; ++i){
    if(temp.magnitude() < (ptr_+i)->magnitude()){
      temp = *(ptr_+i);
    }
  }

  return temp;
}

template<typename NumberType>
NumberType Container<NumberType>::min() {
  NumberType temp = *ptr_;
  
  for(size_t i=0; i<n_; ++i){
    if(temp.magnitude() > (ptr_+i)->magnitude()){
      temp = *(ptr_+i);
    }
  }

  return temp;
}


#endif
