namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const ulong newSize) {
	elements = new Data[newSize];
	this->size = newSize;
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& container) {
	elements = new Data[container.Size()];
	this->size = container.Size();
	unsigned long i = 0;
	container.Traverse([this, &i](const Data& value){
			(this->elements)[i] = value; i++;
	});
}

template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& container) {
	elements = new Data[container.Size()];
	this->size = container.Size();
	unsigned long i = 0;
	container.Map([this, &i](Data& value){
			(this->elements)[i] = std::move(value); i++;
	});
}

template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vector) {
	elements = new Data[vector.size];
	this->size = vector.Size();
	for (ulong i = 0; i < vector.size; i++) {
		elements[i] = vector.elements[i];
	}
}

template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vector) noexcept {
	std::swap(elements, vector.elements);
	std::swap(this->size, vector.size);
}

template<typename Data>
Vector<Data>::~Vector() {
	delete[] elements;
	elements = nullptr;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& toCopy) noexcept {
	if(this == &toCopy)
		return *this;
	if(toCopy.elements == nullptr) {
		this->Clear();
		return *this;
	} Resize(toCopy.size);
	std::copy(toCopy.elements, toCopy.elements + toCopy.size, elements);
	return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& toMove) noexcept {
	std::swap(this->elements, toMove.elements);
	std::swap(this->size, toMove.size);
	return *this;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& toCompare) const noexcept {
	return LinearContainer<Data>::operator==(toCompare);
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
void Vector<Data>::Clear() {
	delete[] elements;
	elements = nullptr;
	this->size = 0;
}

template<typename Data>
void Vector<Data>::Resize(const ulong newSize) {
	Data* newElements = new Data[newSize];
	const unsigned long minSize = std::min(this->size, newSize);
	std::copy(elements, elements + minSize, newElements);
	delete[] elements;
	std::swap(elements, newElements);
	this->size = newSize;
}

template<typename Data>
const Data& Vector<Data>::operator[](const ulong index) const {
	if(index >= this->size) {
		throw std::out_of_range("Index out of range");
	} return elements[index];
}

template<typename Data>
Data& Vector<Data>::operator[](const ulong index) {
	if(index >= this->size) {
		throw std::out_of_range("Index out of range");
	} return elements[index];
}

template<typename Data>
const Data& Vector<Data>::Front() const {
	if(this->size == 0) {
		throw std::length_error("Empty vector");
	} return elements[0];
}

template<typename Data>
Data& Vector<Data>::Front() {
	if(this->size == 0) {
		throw std::length_error("Empty vector");
	} return elements[0];
}

template<typename Data>
Data& Vector<Data>::Back() {
	if(this->size == 0) {
		throw std::length_error("Empty vector");
	} return elements[this->size - 1];
}

template<typename Data>
const Data& Vector<Data>::Back() const {
	if(this->size == 0) {
		throw std::length_error("Empty vector");
	} return elements[this->size - 1];
}


//SortableVector

template<typename Data>
SortableVector<Data>::SortableVector(const ulong newSize) : Vector<Data>::Vector(newSize) {
}

template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& container) : Vector<Data>::Vector(container) {
}

template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& container) : Vector<Data>::Vector(std::move(container)) {
}

template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& vector) : Vector<Data>::Vector(vector) {
}

template<typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& vector) noexcept : Vector<Data>::Vector(std::move(vector)) {
}

template<typename Data>
SortableVector<Data>::~SortableVector() {
		delete[] this->elements;
		this->elements = nullptr;
}

template<typename Data>
bool SortableVector<Data>::operator==(const SortableVector<Data>& toCompare) const noexcept {
	if(this->size != toCompare.Size()) {
		return false;
	} else {
		for (ulong i = 0; i < this->size; i++) {
			if(this->elements[i] != toCompare.elements[i]) {
				return false;
			}
		}
	} return true;
}

template<typename Data>
bool SortableVector<Data>::operator!=(const SortableVector& toCompare) const noexcept {
    return !(*this == toCompare);
}

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector& toCopy) {
	if(this == &toCopy) {
		return *this;
	} this->size = toCopy.Size();
	delete[] this->elements;
	this->elements = new Data[toCopy.Size()];
	for (ulong i = 0; i < toCopy.Size(); i++) {
		this->elements[i] = toCopy.elements[i];
	} return *this;
}

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector&& toMove) noexcept {
	std::swap(this->elements, toMove.elements);
	std::swap(this->size, toMove.size);
	return *this;
}

/* ************************************************************************** */

}
