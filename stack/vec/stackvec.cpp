
namespace lasd {

/* ************************************************************************** */
template<typename Data>
StackVec<Data>::StackVec() : Vector<Data>(5) {}

template<typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& container) : Vector<Data>(container) {
	this->stackRealSize = container.Size();
}

template<typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& con) {
	auto functor = [this] (Data& value) {
		this->Push(std::move(value));
	}; con.Map(functor);
}

template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stack) : Vector<Data>(stack) {
	this->stackRealSize = stack.stackRealSize;
}

template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stack) noexcept : Vector<Data>(std::move(stack)) {
	std::swap(this->stackRealSize, stack.stackRealSize);
}

template<typename Data>
StackVec<Data>::~StackVec() {
	delete[] elements;
	elements = nullptr;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stack) {
	Vector<Data>::operator=(stack);
	this->stackRealSize = stack.stackRealSize;
	return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stack) noexcept {
	Vector<Data>::operator=(std::move(stack));
	std::swap(this->stackRealSize, stack.stackRealSize);
	return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stack) const noexcept {
	if(stackRealSize != stack.stackRealSize) {
		return false;
	}
	for(ulong i = 0; i < stackRealSize; i++) {
		if(elements[i] != stack.elements[i]) {
			return false;
		}
	} return true;
}

template<typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stack) const noexcept {
	return !(*this == stack);
}

template<typename Data>
const Data& StackVec<Data>::Top() const {
	if(this->Empty()) {
		throw std::length_error("Stack is empty");
	} return this->operator[](stackRealSize-1);
}

template<typename Data>
Data& StackVec<Data>::Top() {
	if(this->Empty()) {
		throw std::length_error("Stack is empty");
	} return this->operator[](stackRealSize-1);
}

template<typename Data>
void StackVec<Data>::Pop() {
	if(this->Empty()) {
		throw std::length_error("Stack is empty");
	} stackRealSize--;
}

template<typename Data>
Data StackVec<Data>::TopNPop() {
	if(this->Empty()) {
		throw std::length_error("Stack is empty");
	} stackRealSize--;
	return Vector<Data>::operator[](stackRealSize);
}

template<typename Data>
void StackVec<Data>::Push(const Data& value) {
	if(stackRealSize == size) {
		this->Resize(size*1.2);
	} Vector<Data>::operator[](stackRealSize) = value;
	stackRealSize++;
}

template<typename Data>
void StackVec<Data>::Push(Data&& value) {
	if(stackRealSize == size) {
		this->Resize(size*1.2);
	} Vector<Data>::operator[](stackRealSize) = std::move(value);
	stackRealSize++;
}

template<typename Data>
bool StackVec<Data>::Empty() const noexcept {
	return stackRealSize == 0;
}

template<typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
	return stackRealSize;
}

template<typename Data>
void StackVec<Data>::Clear() {
	this->Resize(5);
	stackRealSize = 0;
}

/* ************************************************************************** */

}
