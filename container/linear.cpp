
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
void SortableLinearContainer<Data>::Sort() noexcept {
	if(this->Size() < 2) {
		return;
	}
	QuickSort(0, this->Size() - 1);
}

template<typename Data>
void SortableLinearContainer<Data>::QuickSort(const unsigned long start, const unsigned long end) {
  if (end - start < 2) return;
  const Data& pivot = this->operator[](end-1);
  unsigned long current_index = start - 1;
  unsigned long swap_marker = start - 1;

  while (++current_index < end){
    if (this->operator[](current_index) <= pivot){
      if (current_index > ++swap_marker) {
        std::swap(this->operator[](current_index), this->operator[](swap_marker));
      }
    }
  }

  QuickSort(start, swap_marker);
  QuickSort(swap_marker + 1, end);
}



/* ************************************************************************** */

}
