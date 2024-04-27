
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer& linearContainer) const noexcept {
	if (this->size != linearContainer.size) {
		return false;
	}
	for (unsigned long i = 0; i < this->size; i++) {
		if (operator[](i) != linearContainer[i]) {
			return false;
		}
	}
	return true;
}

template<typename Data>
bool LinearContainer<Data>::operator!=(const LinearContainer& linearContainer) const noexcept {
	return !operator==(linearContainer);
}

template<typename Data>
const Data& LinearContainer<Data>::Front() const {
	if (this->size == 0) {
		throw std::out_of_range("Container is empty");
	}
	return operator[](0);
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
	if (this->size == 0) {
		throw std::out_of_range("Container is empty");
	}
	return operator[](0);
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
	if (this->size == 0) {
		throw std::out_of_range("Container is empty");
	}
	return operator[](this->size - 1);
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
	if (this->size == 0) {
		throw std::out_of_range("Container is empty");
	}
	return operator[](this->size - 1);
}

template<typename Data>
void LinearContainer<Data>::Traverse(TraverseFun functor) const {
	PreOrderTraverse(functor);
}

template<typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun functor) const {
	for (unsigned long i = 0; i < this->size; i++) {
		functor(operator[](i));
	}
}

template<typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun functor) const {
	for(long i = this->size-1; i >= 0; --i) {
		functor(operator[](i));
	}
}

template<typename Data>
void LinearContainer<Data>::Map(MapFun functor) {
	PreOrderMap(functor);
}

template<typename Data>
void LinearContainer<Data>::PreOrderMap(MapFun functor) {
	for(unsigned long i = 0; i < this->size; i++) {
		functor(operator[](i));
	}
}

template<typename Data>
void LinearContainer<Data>::PostOrderMap(MapFun functor) {
	for(long i = this->size-1; i >= 0; --i) {
		functor(operator[](i));
	}
}

/* ************************************************************************** */

template<typename Data>
bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer& sortableLinearContainer) const noexcept {
	return LinearContainer<Data>::operator==(sortableLinearContainer);
}

template<typename Data>
bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer& sortableLinearContainer) const noexcept {
	return LinearContainer<Data>::operator!=(sortableLinearContainer);
}

template<typename Data>
void SortableLinearContainer<Data>::Sort() noexcept { //TODO - Da correggere in quicksort
	if(this->Size() < 2) {
		std::cerr << "Container is empty or has only one element" << "\n";
		return;
	}
	for (unsigned long i = 0; i < this->Size(); i++) {
        for (unsigned long j = 0; j < this->Size() - i - 1; j++) {
            if (this->operator[](j) > this->operator[](j + 1)) {
                std::swap(this->operator[](j), this->operator[](j + 1));
            }
        }
    }
}



/* ************************************************************************** */

}
