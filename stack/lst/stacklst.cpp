
namespace lasd {

/* ************************************************************************** */
//Constructor
template <typename Data>
StackLst<Data>::StackLst(): List<Data>::List() {}

//Constructor container
template <typename Data>
StackLst<Data>::StackLst(const MappableContainer<Data>& con): List<Data>::List(con) {}

//Constructor mutablecontainer
template <typename Data>
StackLst<Data>::StackLst(const MutableMappableContainer<Data>& con): List<Data>::List(con) {}

//Copy Constructor
template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& StackList): List<Data>::List(StackList){}

//Copy Assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& toCopy) {
    List<Data>::operator=(toCopy);
    return *this;
}

//Move constructor
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& StackList) noexcept: List<Data>::List(std::move(StackList)){}

//Move assignment
template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& toMove) noexcept {
    List<Data>::operator=(std::move(toMove));
    return *this;
}

//Comparing operators
template<typename Data>
bool StackLst<Data>::operator==(const StackLst& toCompare) const noexcept {
    return List<Data>::operator==(toCompare);
}
template<typename Data>
bool StackLst<Data>::operator!=(const StackLst& toCompare) const noexcept {
    return List<Data>::operator!=(toCompare);
}

//Top function
template<typename Data>
const Data& StackLst<Data>::Top() const {
    if(Empty())
        throw std::length_error("StackQueue has currently not a top. Size = 0");
    return List<Data>::Front();
}
template<typename Data>
Data& StackLst<Data>::Top() {
    if(Empty())
        throw std::length_error("StackQueue has currently not a top. Size = 0");
    return List<Data>::Front();
}

//Pop function
template<typename Data>
void StackLst<Data>::Pop() {
    if(Empty())
        throw std::length_error("StackQueue has currently not a top. Size = 0");
    List<Data>::RemoveFromFront();
}

//TopNPop function
template<typename Data>
Data StackLst<Data>::TopNPop() {
    if(Empty())
        throw std::length_error("StackQueue has currently not a top. Size = 0");
    return List<Data>::FrontNRemove();
}

//Push (Copy)
template<typename Data>
void StackLst<Data>::Push(const Data& d) {
    List<Data>::InsertAtFront(d);
}

//Push (Move)
template<typename Data>
void StackLst<Data>::Push(Data&& d) {
    List<Data>::InsertAtFront(std::move(d));
}
/* ************************************************************************** */

}
