
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(2) {}

//Constructor (specifics)
template<typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& con) {
    size = 2;
    element = new Data[2];

    con.Map(
        [this](const Data & dat) {
            Enqueue(dat);
        }
    );
}
template<typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>& con) {
    size = 2;
    element = new Data[2];

    con.Map(
        [this](const Data & dat) {
            Enqueue(std::move(dat));
        }
    );
}

//Copy Constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec& q) : Vector<Data>(q) {
    length = q.length;
    head = q.head;
    tail = q.tail;
}
//Move constructor
template<typename Data>
QueueVec<Data>::QueueVec(QueueVec&& q) noexcept : Vector<Data>(std::move(q)) {
    std::swap(length, q.length);
    std::swap(head, q.head);
    std::swap(tail, q.tail);
}

//Destructor
template<typename Data>
QueueVec<Data>::~QueueVec() {}

//Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& q) {
    Vector<Data>::operator=(q);
    length = q.length;
    head = q.head;
    tail = q.tail;
    return *this;
}
//Move assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& q) noexcept {
    Vector<Data>::operator=(std::move(q));
    std::swap(length, q.length);
    std::swap(head, q.head);
    std::swap(tail, q.tail);
    return *this;
}

//Comparison operators
template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec& q) const noexcept {
    if(length != q.length) {
        return false;
    }
    unsigned long this_head = head;
    unsigned long q_head = q.head;

    for(unsigned long i = 0; i < length; i++) {
        if (element[this_head] != q.element[q_head]) {
            return false;
        }
        this_head = (this_head + 1) % size;
        q_head = (q_head + 1) % size;
    }
    return true;
}

//Comparison !=
template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& q) const noexcept {
    return !(*this==q);
}

//Head
template<typename Data>
const Data& QueueVec<Data>::Head() const {
    if(length == 0) {
        throw std::length_error("Access to an empty queue.");
    }
    return element[head];
}
template<typename Data>
Data& QueueVec<Data>::Head() {
    if(length == 0) {
        throw std::length_error("Access to an empty queue.");
    }
    return element[head];
}

//Dequeue
template<typename Data>
void QueueVec<Data>::Dequeue() {
    if(length == 0) {
        throw std::length_error("Access to an empty queue.");
    }
    head = (head+1) % size;
    length--;

    if(length <= (size/4)) {
        Reduce();
    }
}

//HeadNDequeue
template<typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    Data toReturn = Head();
    Dequeue();
    return toReturn;
}

//EnqueueCpy
template<typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    if(length == size - 1) {
        Expand();
    }
    length++;
    element[tail] = data;
    tail = (tail + 1) % size;
}
//EnqueueMove
template<typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    if(length == size - 1) {
        Expand();
    }
    length++;
    std::swap(element[tail], data);
    tail = (tail + 1) % size;
}

//Empty function
template<typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    if(length == 0) {
        return true;
    } return false;
}

//Size function
template<typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    return length;
}

//Clear Function
template<typename Data>
void QueueVec<Data>::Clear() {
    delete[] element;
    size = 2;
    element = new Data[2];
    length = 0;
    head = 0;
    tail = 0;
}

//expand and reduce
template<typename Data>
void QueueVec<Data>::Expand() {
    SwapVectors(size * 2);
}
template<typename Data>
void QueueVec<Data>::Reduce() {
    SwapVectors(size / 2);
}

//SwapVectors
template<typename Data>
void QueueVec<Data>::SwapVectors(unsigned long newSize) {
    unsigned long this_head = head;
    Data* tmp = new Data[newSize];
    for(unsigned long i = 0; i < length; i++) {
        tmp[i] = element[this_head];
        this_head = (this_head + 1) % size;
    }

    head = 0;
    tail = length;
    size = newSize;
    std::swap(tmp, element);

    delete[] tmp;
}
/* ************************************************************************** */

}
