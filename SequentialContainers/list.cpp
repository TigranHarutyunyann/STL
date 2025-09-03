#include <iostream>

template<typename T>
struct Node{
 	T data;
    Node* prev;
    Node* next;
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class MyList{
	private:
		Node<T> *head;
        Node<T> *tail;
        size_t size;

	public:
		class iterator;
		
		//constructor  
        MyList() :head(nullptr), tail(nullptr), size(0) {}

		//destructor (no end)
		~MyList() {
			clear();
		} 

		//push_back()
		void push_back(const T& value){
			Node<T>* node = new Node<T>(value);
            if(!tail){
				head=tail=node;
			}else{
				tail->next = node;
				node->prev = tail;
				tail = node;
			}                  
			size++;
		}
		//push_front()
		void push_front(const T& value){
			Node<T>* node = new Node<T>(value);
            if(!head){
				head=tail=node;
			}else{ 
				head->prev = node;
			 	node->next = head;
				head = node;	
			}
			size++;
		}

		//pop_back()
		void pop_back(){
			if(!tail) return;

            Node<T>* toDelete = tail;

			if(head==tail){
				head=tail=nullptr;
			}else{
				tail=tail->prev;
				tail->next=nullptr;
			}                      
			delete toDelete;
			size--;   
		}

		//pop_front()
		void pop_front(){
			if(!tail) return;

			Node<T>* toDelete = head;

			if(head==tail){
				head=tail=nullptr;
			}else{
				head=head->next;
				head->prev=nullptr;
			}
				delete toDelete;
				size--;
			}
	
		//empty()
		bool empty() const {
			return head == nullptr;
		}

		//get_size()
		size_t get_size() const {
			return size;
		}

		//clear()
		void clear(){
			Node<T>* current = head;
			while(current != nullptr){
				Node<T>* toDelete = current;
				current=current->next;
				delete toDelete;
			}
			head=tail=nullptr;
			size=0;
		}
        //front and back
		T& front() {
 		   if (empty()) throw std::out_of_range("List is empty");
   		   return head->data;
		}

		T& back() {
    		if (empty()) throw std::out_of_range("List is empty");
    		return tail->data;
		}

		//print()
		void print() const {
			Node<T>* current = head;
			while(current != nullptr){
				std::cout << current->data << " ";
				current=current->next;
			}
			std::cout << std::endl;
		}

		//begin and end
		iterator begin() { 
				return iterator(head); 
		}
    	iterator end()   { 
				return iterator(nullptr); 
		}

	public:
		class iterator{
			private:
				Node<T>* ptr;
			public:
				iterator(Node<T>* p = nullptr) : ptr(p) {}

			   	//ptr operator
               	T& operator*(){
			       return ptr->data;
			   	}

				T* operator->(){
					return &(ptr->data);
				}

				//increment/decrement
				iterator& operator++(){
					ptr = ptr->next;
					return *this ;
				}

				iterator& operator--(){
					ptr = ptr->prev;
					return *this;
				}

			   	//Comparison
    		   	bool operator==(const iterator& other) const {
					return (ptr==other.ptr);
				}
    			
				bool operator!=(const iterator& other) const{
					return (ptr!=other.ptr);
				}
    			bool operator<(const iterator& other) const{
					return (ptr<other.ptr);
				}
    			bool operator>(const iterator& other) const{
			   		return (ptr>other.ptr); 
				}
	};
};



int main() {
	MyList<int> lst;

	lst.push_back(1);
	lst.push_front(0);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << "size = " << lst.get_size() << std::endl;
    std::cout << "print list = "; lst.print();
    std::cout << "empty? = " << lst.empty() << std::endl;
    std::cout << "front = " << lst.front() << std::endl;
    std::cout << "back = " << lst.back() << std::endl;

    MyList<int>::iterator it = lst.begin();
	++it;
    std::cout << "*it = " << *it << std::endl;  
    ++it;
    std::cout << "++it = " << *it << std::endl; 
    --it;
    std::cout << "--it = " << *it << std::endl; 
    std::cout << "it == lst.begin()? " << (it == lst.begin()) << std::endl;

    lst.clear();
    std::cout << "print list = "; lst.print();

	return 0;
}
