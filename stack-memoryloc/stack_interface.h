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
      head_ = st.head_;
      size_ = st.size_;
    };
    
    Stack(Stack&& st){
      head_ = st.head_;
      size_ = st.size_;

      st.clear();  
    }
    
    ~Stack(){
      while(!empty()){
        pop();
      }
    }

    Stack& operator=(Stack& st){
      head_ = st.head_;
      size_ = st.size_;
    }

    Stack& operator=(Stack&& st){
      head_ = st.head_;
      size_ = st.size_;
      
      st.clear();
    }

    struct Node {
      Type value;
      Node* next;
    };
    
    void push(const Type& val){
      if(!size_){
        head_ = new Node{val};
      } else {
        head_ = new Node{val, head_};
      }

      ++size_;
    }

    void push(Type&& val){
      if(!size_){
        head_ = new Node{val};
      } else {
        head_ = new Node{val, head_};
      }

      ++size_;
    }

    Type& top(){
      return head_->value;
    };

    const Type& top() const{
      return head_->value;
    }
    
    void pop(){
      Node* temp;

      if(head_->next != nullptr){
        temp = head_->next;  
      } else {
        temp = nullptr;  
      }
        
      delete head_;

      head_ = temp;
      --size_;
    }
    
    size_t size() const {
      return size_;
    }

    bool empty() const{
      if(!size_){
        return true;
      } else {
        return false;
      }
    }

    void clear(){
      head_ = nullptr;
      size_ = 0;
    }

  private:
    Node* head_{nullptr};
    size_t size_ = 0;
};

template<typename Type>
std::ostream& operator<<(std::ostream& o, const Stack<Type>& st){
  if(!st.empty()){
    o << st.top(); 
  } else {
    o << "Stack is empty." << std::endl;
  }
}


#endif
