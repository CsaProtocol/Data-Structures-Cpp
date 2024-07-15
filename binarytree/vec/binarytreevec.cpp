
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept {
	return (this->Element() == node.Element() && this->LeftChild() == node.LeftChild() && this->RightChild() == node.RightChild());
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept {
	return !(*this == node);
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& toInsert) {
	this->value = toInsert;
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& toInsert, const unsigned long i, Vector<NodeVec*>*& btVec) {
	this->value = toInsert;
	this->index = i;
	this->btVec = btVec;
}

template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& toInsert) noexcept {
	this->value = std::swap(toInsert, this->value);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
	if(2*this->index + 1 >= this->btVec->Size()) {
		return false;
	} if(btVec->operator[](2*this->index+1) != nullptr) {
		return true;
	} return false;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
	if(2*this->index + 2 >= this->btVec->Size()) {
		return false;
	} if(btVec->operator[](2*this->index+2) != nullptr) {
		return true;
	} return false;
}

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
	if (!this->HasLeftChild()) {
		throw std::out_of_range("The node has no left child");
	}
	return *(btVec->operator[](2 * this->index + 1));
}

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
	if (!this->HasRightChild()) {
		throw std::out_of_range("The node has no right child");
	}
	return *(btVec->operator[](2 * this->index + 2));
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
	if (!this->HasLeftChild()) {
		throw std::out_of_range("The node has no left child");
	}
	return *btVec->operator[](2 * this->index + 1);
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
	if (!this->HasRightChild()) {
		throw std::out_of_range("The node has no right child");
	}
	return *btVec->operator[](2 * this->index + 2);
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec() {
	tree = new Vector<NodeVec*>(10);
	for(unsigned long i = 0; i < 10; i++) {
		tree->operator[](i) = nullptr;
	}
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& container) {
	this->tree = new Vector<NodeVec*>(container.Size());
	unsigned long i = 0;
	auto functor = [this, &i](const Data& value){
		tree->operator[](i) = new NodeVec(value, i, this->tree);
		i++;
	}; container.Traverse(functor);
	this->size = container.Size();
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& container) noexcept {
	tree = new Vector<NodeVec*>(container.Size(), nullptr);
	unsigned long i = 0;
	container.Map([this, &i](Data& value){
		tree->operator[](i) = new NodeVec(std::move(value));
		tree->operator[](i)->index = i;
		tree->operator[](i)->btVec = this->tree;
		i++;
	});
	std::swap(this->size, container.size);
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& toCopy) {
	this->tree = new Vector<NodeVec*>(toCopy.tree->Size());
	for(unsigned long i = 0; i < toCopy.tree->Size(); i++) {
		if(toCopy.tree->operator[](i) != nullptr) {
			this->tree->operator[](i) = new NodeVec(toCopy.tree->operator[](i)->value, i, this->tree);
			this->size = this->size + 1;
		}
	}
}

template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& toMove) noexcept {
	std::swap(this->tree, toMove.tree);
	std::swap(this->size, toMove.size);
}

template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
	for(ulong i = 0; i < tree->Size(); i++) {
		delete tree->operator[](i);
	} delete tree;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& toCopy) {
	if(this == &toCopy) {
		return *this;
	} delete this->tree;
	this->tree = new Vector<NodeVec*>(toCopy.tree->Size());
	for (unsigned long i = 0; i < toCopy.tree->Size(); i++) {
		if (toCopy.tree->operator[](i) != nullptr) {
			this->tree->operator[](i) = new NodeVec(toCopy.tree->operator[](i)->value, i, this->tree);
			this->size = this->size + 1;
		}
	} return *this;
}

template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& toMove) noexcept {
	std::swap(this->tree, toMove.tree);
	std::swap(this->size, toMove.size);
	return *this;
}

template<typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& toConfront) const noexcept {
	if (this->size != toConfront.Size()) {
		return false;
	} if (this->size == 0) {
		return true;
	}
	for(unsigned long i = 0; i < this->tree->Size(); i++) {
		if((this->tree->operator[](i) == nullptr && toConfront.tree->operator[](i) != nullptr) ||
			this->tree->operator[](i) != nullptr && toConfront.tree->operator[](i) == nullptr) {
			return false;
		}
		if (this->tree->operator[](i)->value != toConfront.tree->operator[](i)->value) {
			return false;
		}
	}
	return true;
}

template<typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& toConfront) const noexcept {
	return !(*this == toConfront);
}

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
	if (this->size == 0) {
		throw std::length_error("The tree is empty");
	}
	return *(tree->operator[](0));
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
	if (this->size == 0) {
		throw std::length_error("The tree is empty");
	}
	return *(tree->operator[](0));
}

template<typename Data>
void BinaryTreeVec<Data>::Clear() {
	for (unsigned long i = 0; i < this->tree->Size(); i++) {
		delete tree->operator[](i);
	} delete tree;
	tree = new Vector<NodeVec*>(10);
	this->size = 0;
}

template<typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
	if (this->tree->Size() == 0) {
		throw std::length_error("The tree is empty");
	}
	for (unsigned long i = 0; i < this->Size(); i++) {
		fun(tree->operator[](i)->value);
	}
}

template<typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {
	if (this->tree->Size() == 0) {
		throw std::length_error("The tree is empty");
	}
	for (unsigned long i = 0; i < this->size; i++) {
		fun(tree->operator[](i)->value);
	}
}

template<typename Data>
bool BinaryTreeVec<Data>::Empty() const noexcept {
	return this->size == 0;
}



/* ************************************************************************** */

}
