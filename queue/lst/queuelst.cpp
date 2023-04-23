
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(): List<Data>() {}
//Specific constructors
template<typename Data>
QueueLst<Data>::QueueLst(const MappableContainer<Data>& con): List<Data>::List(con) {}

template<typename Data>
QueueLst<Data>::QueueLst(const MutableMappableContainer<Data>& con): List<Data>::List(con) {}

//Copy Constructor
template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst& q): List<Data>(q) {}

//Mv constructor
template<typename Data>
QueueLst<Data>::QueueLst(QueueLst&& q) noexcept : List<Data>(std::move(q)) {}

//Copy assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& q) {
    List<Data>::operator=(q);
    return *this;
}

//Move assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& q) noexcept {
    List<Data>::operator=(std::move(q));
    return *this;
}

//Operators
template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& q) const noexcept {
    return List<Data>::operator==(q);
}
// !=
template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& q) const noexcept {
    return List<Data>::operator!=(q);
}

//Head
template<typename Data>
const Data& QueueLst<Data>::Head() const {
    if(Empty())
        throw std::length_error("Empty queue");
    return List<Data>::Front();
}
template<typename Data>
Data& QueueLst<Data>::Head() {
    if(Empty())
        throw std::length_error("Empty queue");
    return List<Data>::Front();
}
//dequeue
template<typename Data>
void QueueLst<Data>::Dequeue() {
    if(Empty())
        throw std::length_error("Empty queue");
    return List<Data>::RemoveFromFront();
}
//Headndequeue
template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    if(Empty())
        throw std::length_error("Empty queue");
    return List<Data>::FrontNRemove();
}

//Enqueue
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& d){
    List<Data>::InsertAtBack(d);
}
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& d){
    List<Data>::InsertAtBack(std::move(d));
}
/* ************************************************************************** */

}
