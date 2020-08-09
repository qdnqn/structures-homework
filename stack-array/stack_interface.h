#ifndef H_INTERFACE_STACK
#define H_INTERFACE_STACK

#include <iostream>

template <typename Type>
class stack_interface
{
    public:
        virtual void push(const Type & val) = 0;   
        virtual void push(Type&& val) = 0;  
        virtual Type& top() = 0;
        virtual const Type& top() const = 0;
        virtual void pop() = 0;     
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;  
        
        virtual ~stack_interface() = default;
};

template<typename Type>
class Stack : stack_interface<Type> {
  public:
    Stack() = default;

    Stack(Stack& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;
    };
    
    Stack(Stack&& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;

      st.clear();
    };

    Stack& operator=(Stack& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;
      
      return *this;
    }

    Stack& operator=(Stack&& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;

      st.clear();

      return *this;
    }

    ~Stack(){
      delete [] ptr_;
    }

    void push(const Type& val){
      if(full()){
        reallocate();
      }
      
      ptr_[size_] = val;
      ++size_;
    }

    void push(Type&& val){
      if(full()){
        reallocate();
      }

      ptr_[size_] = val;
      ++size_;
    }

    Type& top() {
      return ptr_[size_-1];
    }

    const Type& top() const {
      return ptr_[size_-1];
    }

    size_t size() const {
      return size_;
    }

    bool empty() const {
      if(size_ == 0){
        return true;
      } else {
        return false;
      }
    }
    
    void pop(){
      std::move(ptr_[size_]);
      --size_;
    }

    void clear(){
      ptr_ = nullptr;
      size_ = 0;
      capacity_ = 8;
    }

  private:
    size_t capacity_ = 8;
    size_t size_ = 0;
    Type* ptr_ = new Type[capacity_];

    void reallocate(){
      capacity_ *= 2;
      Type* newPtr = new Type[capacity_];
      
      for(size_t i=0; i<size_; ++i){
        newPtr[i] = std::move(ptr_[i]);
      } 

      delete[] ptr_;
      ptr_ = newPtr;
    }

    bool full(){
      if(size_ == capacity_){
        return true;
      } else {
        return false;
      }
    }
};

template<typename Type>
std::ostream& operator<<(std::ostream& o, const Stack<Type>& st){
  if(!st.empty()){
    o << st.top();
  } else {
    o << "Stack is empty." << std::endl;
  }

  return o;
}

#endif
