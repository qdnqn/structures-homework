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
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;
    };
    
    Queue(Queue&& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;

      st.clear();
    };

    Queue& operator=(Queue& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;
      
      return *this;
    }

    Queue& operator=(Queue&& st){
      size_ = st.size_;
      capacity_ = st.capacity_;
      ptr_ = st.ptr_;

      st.clear();

      return *this;
    }

    ~Queue(){
      delete [] ptr_;
    }

    void push(const Type& val){
      if(full()){
        reallocate();
      }
      
      if(head_ == -1){
        ptr_[0] = val;
        ++head_;
        ++rear_;
      } else {
        ++rear_;

        if(rear_ == size_){
          rear_ = 0;
        }

        ptr_[rear_] = val;
      }

      ++size_;
    }
    
    void push(Type&& val){
      if(head_ == -1){
        ++head_;
        ++rear_;

        ptr_[head_] = val;     
      } else {
        ++rear_;
        
        if(head_ > 0){
          if(rear_ == capacity_){
            rear_ = 0;
          } else {
            if(rear_ == head_){
              reallocate();
            }
          }

          ptr_[rear_] = val;
        } else {        
          ptr_[rear_] = val;
        }
      }

      ++size_;
    }

    Type& front() {
      return ptr_[head_];
    }

    Type& back(){
      return ptr_[rear_-1];
    }

    const Type& front() const {
      return ptr_[0];
    }

    const Type& back() const {
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
      if(!empty()){
        std::move(ptr_[head_]);
        ++head_;
        --size_;
      }
    }

    void clear(){
      ptr_ = nullptr;
      size_ = 0;
      capacity_ = 8;
    }

  private:
    size_t capacity_ = 8;
    size_t size_ = 0;
    
    int head_{-1};
    int rear_{-1};

    Type* ptr_ = new Type[capacity_];

    void reallocate(){
      capacity_ *= 2;
      Type* newPtr = new Type[capacity_];
    
      auto temp = head_;
      auto counter = 0;

      do {
        newPtr[counter] = std::move(ptr_[temp]);
        ++counter;
        ++temp;

        if(temp == capacity_/2){
          temp = 0;
        }
      } while(temp != rear_);

      newPtr[counter] = std::move(ptr_[temp]);
      
      head_ = 0;
      rear_ = counter;

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
std::ostream& operator<<(std::ostream& o, const Queue<Type>& qu){
  if(!qu.empty()){
    o << qu.front();
  } else {
    o << "Queue is empty." << std::endl;
  }

  return o;
}

#endif
