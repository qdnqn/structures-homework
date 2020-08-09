#ifndef H_INTERFACE_QUEUE
#define H_INTERFACE_QUEUE

template <typename Type>
class queue_interface
{
    public:
        virtual void push(const Type & val) = 0;   
        virtual void push(Type&& val) = 0;  
        virtual Type& front() = 0;
        virtual const Type& front() const = 0;
        virtual Type& back() = 0;
        virtual const Type& back() const = 0;
        virtual void pop() = 0;     
        virtual size_t size() const = 0;
        virtual bool empty() const = 0; 
        
        virtual ~queue_interface() = default;       
};

template<typename Type>
class Queue : queue_interface<Type> {
  public:
    Queue() = default;
    
    Queue(Queue& st){
      head_ = st.head_;
      size_ = st.size_;
    };
    
    Queue(Queue&& st){
      head_ = st.head_;
      size_ = st.size_;

      st.clear();  
    }
    
    ~Queue(){
      while(!empty()){
        pop();
      }
    }

    Queue& operator=(Queue& st){
      head_ = st.head_;
      size_ = st.size_;
    }

    Queue& operator=(Queue&& st){
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
        tail_ = head_;
      } else {
        tail_->next = new Node{val};
        tail_ = tail_->next;
      }

      ++size_;
    }

    void push(Type&& val){
      if(!size_){
        head_ = new Node{val};
        tail_ = head_;
      } else {
        tail_->next = new Node{val};
        tail_ = tail_->next;
      }

      ++size_;
    }

    Type& front(){
      return head_->value;
    };

    Type& back(){
      return tail_->value;
    }

    const Type& front() const{
      return head_->value;
    }

    const Type& back() const {
      return tail_->value;
    }
    
    void pop(){
      if(!empty()){
        Node* temp;

        if(head_->next != nullptr){
          temp = head_->next;  
        } else {
          temp = nullptr;  
          tail_ = temp;
        }
        
        delete head_;

        head_ = temp;
        --size_;
      } else {
        throw std::length_error("Queue is empty.");
      }
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
    Node* tail_{nullptr};
    size_t size_ = 0;
};

template<typename Type>
std::ostream& operator<<(std::ostream& o, const Queue<Type>& qu){
  if(!qu.empty()){
    o << qu.front(); 
  } else {
    o << "Queue is empty." << std::endl;
  }
}


#endif
