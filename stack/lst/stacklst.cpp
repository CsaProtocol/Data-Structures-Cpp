
namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data>& container) : List<Data>(container) {}

template<typename Data>
StackLst<Data>::StackLst(MappableContainer<Data>&& container) noexcept : List<Data>(std::move(container)) {}

template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack) : List<Data>(stack) {}

template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept : List<Data>(std::move(stack)) {}

template<typename Data>
StackLst<Data>::~StackLst() = default;

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack) {
	List<Data>::operator=(stack);
	return *this;
}

template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept {
    List<Data>::operator=(std::move(stack));
    return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
    return List<Data>::operator==(stack);
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept {
	return List<Data>::operator!=(stack);
}

template<typename Data>
const Data& StackLst<Data>::Top() const {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::Front();
}

template<typename Data>
Data& StackLst<Data>::Top() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::Front();
}

template<typename Data>
void StackLst<Data>::Pop() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    List<Data>::RemoveFromFront();
}

template<typename Data>
Data StackLst<Data>::TopNPop() {
    if (this->Empty()) {
        throw std::length_error("Stack is empty");
    }
    return List<Data>::FrontNRemove();
}

template<typename Data>
void StackLst<Data>::Push(const Data& value) {
    List<Data>::InsertAtFront(value);
}

template<typename Data>
void StackLst<Data>::Push(Data&& value) {
    List<Data>::InsertAtFront(std::move(value));
}
/* ************************************************************************** */

}
