
namespace lasd {

/* ************************************************************************** */

template<typename Data>
List<Data>::List(const TraversableContainer<Data>& container) {
  container.Traverse([this](const Data& value){
      this->InsertAtBack(value);
  });
}

template<typename Data>
List<Data>::List(MappableContainer<Data>&& container) {
  unsigned long i = 0;
  // ReSharper disable once CppParameterMayBeConstPtrOrRef : Not const because of std::move
  container.Map([this, &i](Data& value){
      this->InsertAtBack(std::move(value)); i++;
  });
}

template<typename Data>
List<Data>::List(const List& lst) noexcept {
    Node* temp = lst.head;
    while(temp != nullptr){
        InsertAtBack(temp->value);
        temp = temp->next;
    }
}

template<typename Data>
List<Data>::List(List&& lst) noexcept {
	std::swap(this->head, lst.head);
    std::swap(this->tail, lst.tail);
	std::swap(this->size, lst.size);
}

template<typename Data>
List<Data>::~List() noexcept {
    Node* temp = this->head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    size = 0; this->head = nullptr; this->tail = nullptr;
}

template<typename Data>
List<Data>& List<Data>::operator=(const List& lst) noexcept {
    if(this != &lst){
        Clear();
        Node* temp = lst.head;
        while(temp != nullptr){
            InsertAtBack(temp->value);
            temp = temp->next;
        }
    }
    return *this;
}

template<typename Data>
List<Data>& List<Data>::operator=(List&& lst) noexcept {
    std::swap(this->head, lst.head);
    std::swap(this->tail, lst.tail);
    std::swap(this->size, lst.size);
    return *this;
}

template<typename Data>
bool List<Data>::operator==(const List& lst) const noexcept {
    if(this->Size() != lst.Size()){
        return false;
    }
    Node* temp1 = this->head;
    Node* temp2 = lst.head;
    while(temp1 != nullptr){
        if(temp1->value != temp2->value){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template<typename Data>
bool List<Data>::operator!=(const List& lst) const noexcept {
    return !(*this == lst);
}

template<typename Data>
Data& List<Data>::operator[](unsigned long index) {
    if(index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    Node* temp = this->head;
    for(unsigned long i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->value;
}

template<typename Data>
const Data& List<Data>::operator[](unsigned long index) const {
    if(index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    Node* temp = this->head;
    for(unsigned long i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->value;
}

template<typename Data>
void List<Data>::InsertAtFront(const Data& value) {
    Node* temp = new Node(value);
    temp->next = this->head;
    this->head = temp;
    if(this->size == 0){
        this->tail = temp;
    } size++;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& value) {
    Node* temp = new Node(std::move(value));
    temp->next = this->head;
    this->head = temp;
    if(this->size == 0){
        this->tail = temp;
    } size++;
}

template<typename Data>
void List<Data>::RemoveFromFront() {
    if(this->size == 0){
        throw std::length_error("List is empty");
    } if(this->size == 1) {
        this->tail = nullptr;
    }
    // ReSharper disable once CppLocalVariableMayBeConst -- Cannot be const because of delete
    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    size--;
}

template<typename Data>
Data List<Data>::FrontNRemove() {
    Data toReturn = this->head->value;
    RemoveFromFront();
    return toReturn;
}

template<typename Data>
void List<Data>::InsertAtBack(const Data& value) {
    Node* temp = new Node(value);
    if(this->size == 0){
        this->head = temp;
        this->tail = temp;
    } else {
        this->tail->next = temp;
        this->tail = temp;
    } size++;
}

template<typename Data>
void List<Data>::InsertAtBack(Data&& value) {
    Node* temp = new Node(std::move(value));
    if(this->size == 0){
        this->head = temp;
        this->tail = temp;
    } else {
        this->tail->next = temp;
        this->tail = temp;
    } size++;
}

template<typename Data>
void List<Data>::Clear() {
    Node* temp = this->head;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    size = 0; this->head = nullptr; this->tail = nullptr;
}

template<typename Data>
bool List<Data>::Insert(const Data& value) noexcept {
    if(this->Exists(value)) {
        return false;
    } InsertAtBack(value);
    return true;
}

template<typename Data>
bool List<Data>::Insert(Data&& value) noexcept {
    if(this->Exists(value)) {
        return false;
    } InsertAtBack(std::move(value));
    return true;
}

template<typename Data>
bool List<Data>::Remove(const Data& toFind) noexcept {
    Node* temp = this->head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        if(temp->value == toFind) {
            if(prev == nullptr) {
                RemoveFromFront();
                return true;
            } if(temp->next == nullptr) {
                this->tail = prev;
            } prev->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        prev = temp;
        temp = temp->next;
    } return false;
}

template<typename Data>
const Data& List<Data>::Front() const {
    if(this->size == 0){
        throw std::length_error("List is empty");
    }
    return this->head->value;
}

template<typename Data>
Data& List<Data>::Front() {
    if(this->size == 0){
        throw std::length_error("List is empty");
    }
    return this->head->value;
}

template<typename Data>
const Data& List<Data>::Back() const {
    if(this->size == 0){
        throw std::length_error("List is empty");
    }
    return this->tail->value;
}

template<typename Data>
Data& List<Data>::Back() {
    if(this->size == 0){
        throw std::length_error("List is empty");
    }
    return this->tail->value;
}

template<typename Data>
void List<Data>::Traverse(TraverseFun fun) const {
    Node* temp = this->head;
    while(temp != nullptr){
        fun(temp->value);
        temp = temp->next;
    }
}

template<typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun) const {
    Node* temp = this->head;
    while(temp != nullptr){
        fun(temp->value);
        temp = temp->next;
    }
}

template<typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverseAux(head, fun);
}

template<typename Data>
void List<Data>::PostOrderTraverseAux(Node* currentNode, TraverseFun fun) const {
    if(currentNode == nullptr){
        return;
    } PostOrderTraverseAux(currentNode->next, fun);
    fun(currentNode->value);
}

template<typename Data>
void List<Data>::Map(MapFun fun) {
    Node* temp = this->head;
    while(temp != nullptr){
        fun(temp->value);
        temp = temp->next;
    }
}

template<typename Data>
void List<Data>::PreOrderMap(MapFun fun) {
    Node* temp = this->head;
    while(temp != nullptr){
        fun(temp->value);
        temp = temp->next;
    }
}

template<typename Data>
void List<Data>::PostOrderMap(MapFun fun) {
    PostOrderMapAux(head, fun);
}

template<typename Data>
void List<Data>::PostOrderMapAux(Node* currentNode, MapFun fun) {
    if(currentNode == nullptr){
        return;
    } PostOrderMapAux(currentNode->next, fun);
    fun(currentNode->value);
}

/* ************************************************************************** */

}
