
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueVec<Data>::QueueVec() {
	elements = new Data[5];
	this->size = 5;
}

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& con) : Vector<Data>::Vector(5) {
	auto functor = [this] (const Data& value) {
		Enqueue(value);
	}; con.Traverse(functor);
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& con) : Vector<Data>::Vector(5) {
	auto functor = [this] (Data& value) {
		this->Enqueue(std::move(value));
	}; con.Map(functor);
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& queue) : Vector<Data>::Vector(queue) {
	this->operator=(queue);
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& queue) noexcept {
	std::swap(this->elements, queue.elements);
	std::swap(this->size, queue.size);
	std::swap(this->queueHead, queue.queueHead);
	std::swap(this->queueRealSize, queue.queueRealSize);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& queue) {
	if (this != &queue) {
		this->size = queue.size;
		this->queueHead = queue.queueHead;
		this->queueRealSize = queue.queueRealSize;
		delete[] this->elements;
		this->elements = new Data[queue.size];
		std::copy(queue.elements, queue.elements + queue.size, this->elements);
	} return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& queue) noexcept {
	if (this != &queue) {
		std::swap(this->elements, queue.elements);
		std::swap(this->size, queue.size);
		std::swap(this->queueHead, queue.queueHead);
		std::swap(this->queueRealSize, queue.queueRealSize);
	} return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& queue) const noexcept {
	if (this->queueRealSize != queue.queueRealSize) return false;
	if (this->queueRealSize == 0) return true;
	unsigned int i = 0;
	unsigned int j = 0;
	while(i != this->queueHead && j != queue.queueHead) {
		if(this->operator[](i) != queue.operator[](j)) return false;
		i++; j++;
		if(i == this->size) i = 0;
		if(j == queue.size) j = 0;
	}
	return true;
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& queue) const noexcept {
  return !this->operator==(queue);
}

template <typename Data>
const Data& QueueVec<Data>::Head() const {
  if (this->Empty()) throw std::length_error("Queue is empty");
  return this->operator[](queueHead);
}

template <typename Data>
Data& QueueVec<Data>::Head() {
  if (this->Empty()) throw std::length_error("Queue is empty");
  return this->operator[](queueHead);
}

template <typename Data>
void QueueVec<Data>::Dequeue() { //TODO - Rimpicciolisci la coda se necessario
	if (this->Empty()) throw std::length_error("Queue is empty");
	queueHead++;
	queueRealSize--;
	if (queueHead == size) queueHead = 0;
	if (queueRealSize < size/3) this->SafeResize(size/2);
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
  if (this->Empty()) throw std::length_error("Queue is empty");
  Data& value = this->operator[](queueHead);
  Dequeue();
  return value;
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& value) {
  if (queueRealSize == size)
  	this->SafeResize(size * 1.3);
  unsigned long index = queueHead + queueRealSize;
  if (index >= size) index -= size;
  this->elements[index] = value;
  queueRealSize++;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& value) {
  if (queueRealSize == size) this->SafeResize(size*1.3);
  unsigned long index = queueHead + queueRealSize;
  if (index >= size) index -= size;
	std::swap(this->elements[index], value);
  queueRealSize++;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
  return this->queueRealSize == 0;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
  return queueRealSize;
}

template <typename Data>
void QueueVec<Data>::Clear() {
	this->Resize(5);
	this->size = 5;
  this->queueRealSize = 0;
  this->queueHead = 0;
}

template<typename Data>
void QueueVec<Data>::SafeResize(const unsigned long newSize) {
	Data* tempelements = new Data[newSize];
	if(queueRealSize + queueHead > size) {
		std::copy(elements + queueHead, elements + size - 1, tempelements);
		std::copy(elements, elements + queueHead - 1, tempelements + size - queueHead);
	} else {
		std::copy(elements + queueHead, elements + queueHead + queueRealSize - 1, tempelements);
	} queueHead = 0;
	delete[] elements;
	std::swap(elements, tempelements);
	this->size = newSize;
	/*Data* tempelements = new Data[newSize];
	std::copy(elements + queueHead, elements + size - 1, tempelements);
	std::copy(elements, elements + queueHead - 1, tempelements + size - queueHead);
	queueHead = 0;
	delete[] elements;
	elements = nullptr;
	std::swap(elements, tempelements);
	this->size = newSize;*/
}


/* ************************************************************************** */

}
