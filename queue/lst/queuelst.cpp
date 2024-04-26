
#include "../../zlasdtest/list/list.hpp"

namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data>& lc) {
	auto functor = [this] (const Data& value) {
		Enqueue(value);
	};
	lc.Traverse(functor);
}

template<typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data>&& mc) {
	auto functor = [this] (Data&& value) {
		Enqueue(std::move(value));
	};
	mc.MapPreOrder(functor);
}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queue) : List<Data>::List(queue) {
}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst&& queue) noexcept {
	std::swap(queue.head, this->head);
	std::swap(queue.size, this->size);
	std::swap(queue.tail, this->tail);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& queue) {
	List<Data>::operator=(queue);
	return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& queue) noexcept {
	List<Data>::operator=(std::move(queue));
	return *this;
}

template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst& queue) const noexcept {
	if (this->size != queue.size) return false;
	auto headCopy = this->head;
	auto toCompare = queue.head;
	while(headCopy != nullptr) {
		if(headCopy->value != toCompare->value) return false;
		headCopy = headCopy->next; toCompare = toCompare->next;
	} return true;
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& queue) const noexcept {
	return !(*this == queue);
}

template<typename Data>
const Data& QueueLst<Data>::Head() const {
	if (this->Empty()) throw std::length_error("Queue is empty");
	return this->head->value;
}

template<typename Data>
Data& QueueLst<Data>::Head() {
	if (this->Empty()) throw std::length_error("Queue is empty");
	return this->head->value;
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
	this->RemoveFromFront();
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
	return this->FrontNRemove();
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& value) {
	this->InsertAtBack(value);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& value) {
	this->InsertAtBack(std::move(value));
}

template<typename Data>
bool QueueLst<Data>::Empty() const noexcept {
	return this->size == 0;
}

template<typename Data>
unsigned long QueueLst<Data>::Size() const noexcept {
	return this->size;
}

/* ************************************************************************** */

}
