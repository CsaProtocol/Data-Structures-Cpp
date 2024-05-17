
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
	return (this->Element() == node.Element() && this->LeftChild() == node.LeftChild() && this->RightChild() == node.RightChild());
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
	return !(*this == node);
}

template<typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
	return (!HasLeftChild() && !HasRightChild());
}

template<typename Data>
bool BinaryTree<Data>::Node::HasLeftChild() const noexcept {
	try {
		// ReSharper disable once CppExpressionWithoutSideEffects
		LeftChild();
		return true;
	} catch(...) {
		return false;
	}
}

template<typename Data>
bool BinaryTree<Data>::Node::HasRightChild() const noexcept {
	try {
		// ReSharper disable once CppExpressionWithoutSideEffects
		RightChild();
		return true;
	} catch(...) {
		return false;
	}
}

template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& toCompare) const noexcept {
	if(size != toCompare.Size())
		return false;
	if(size == 0)
		return true;
	return toCompare.Root() == this->Root();
}

template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const {
	PreOrderTraverse(fun);
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
	if(!this->Empty())
		PreOrderTraverseAux(fun, Root());
}

template<typename Data>
void BinaryTree<Data>::PreOrderTraverseAux(TraverseFun fun, const Node& toTraverse) const {
	fun(toTraverse.Element());
	if(toTraverse.HasLeftChild()) {
		PreOrderTraverseAux(fun, *toTraverse.LeftChild());
	}
	if(toTraverse.HasRightChild()) {
		PreOrderTraverseAux(fun, *toTraverse.RightChild());
	}
}

template<typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
	if(!this->Empty())
		PostOrderTraverseAux(fun, Root());
}


template<typename Data>
void BinaryTree<Data>::PostOrderTraverseAux(TraverseFun fun, const Node& toTraverse) const {
	if(toTraverse.HasLeftChild()) {
		PostOrderTraverseAux(fun, *toTraverse.LeftChild());
	}
	if(toTraverse.HasRightChild()) {
		PostOrderTraverseAux(fun, *toTraverse.RightChild());
	}
	fun(toTraverse.Element());
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
	if(!this->Empty())
		InOrderTraverseAux(fun, Root());
}

template<typename Data>
void BinaryTree<Data>::InOrderTraverseAux(TraverseFun fun, const Node& toTraverse) const {
	if(toTraverse.HasLeftChild()) {
		InOrderTraverseAux(fun, toTraverse.LeftChild());
	}
	fun(toTraverse.Element());
	if(toTraverse.HasRightChild()) {
		InOrderTraverseAux(fun, toTraverse.RightChild());
	}
}

template<typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
	if(!this->Empty())
		BreadthTraverseAux(fun, Root());
}

template<typename Data>
void BinaryTree<Data>::BreadthTraverseAux(TraverseFun fun, const Node& toTraverse) const {
	QueueVec<Node const*> frontier;
	frontier.Enqueue(&toTraverse);
	while(!frontier.Empty()) {
		if(frontier.Head()->HasLeftChild()) {
			frontier.Enqueue(&frontier.Head()->LeftChild());
		} if (frontier.Head()->HasRightChild()) {
			frontier.Enqueue(&frontier.Head()->RightChild());
		} fun(frontier.HeadNDequeue()->Element());
	}
}

template<typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun) {
	auto mapfun = [&fun](const Data& data) { fun(const_cast<Data&>(data)); };
	static_cast<const MutableBinaryTree*>(this)->Traverse(mapfun);
}

template<typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
	auto mapfun = [&fun](const Data& data) { fun(const_cast<Data&>(data)); };
	static_cast<const MutableBinaryTree*>(this)->PreOrderTraverse(mapfun);
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
	auto mapfun = [&fun](const Data& data) { fun(const_cast<Data&>(data)); };
	static_cast<const MutableBinaryTree*>(this)->PostOrderTraverse(mapfun);
}

template<typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
	auto mapfun = [&fun](const Data& data) { fun(const_cast<Data&>(data)); };
	static_cast<const MutableBinaryTree*>(this)->InOrderTraverse(mapfun);
}

template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
	auto mapfun = [&fun](const Data& data) { fun(const_cast<Data&>(data)); };
	static_cast<const MutableBinaryTree*>(this)->BreadthTraverse(mapfun);
}


/* ************************************************************************** */
	// ITERATORS
/* ************************************************************************** */

template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& toIterate) noexcept {
	itrStack = StackVec<typename BinaryTree<Data>::Node const*>();
	if(not toIterate.Empty()) {
		current = toIterate.Root();
		reset = toIterate.Root();
	}
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& toCompare) const noexcept {
	return (current == toCompare.current && reset == toCompare.reset);
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
	return current == nullptr;
}

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
	if(current == nullptr) throw std::out_of_range("Iterator terminated");
	if(current->HasLeftChild()) {
		if(current->HasRightChild()) {
			itrStack.Push(current->RightChild());
		} current = &(current->LeftChild());
	} else if(current->HasRightChild()) {
		current = &(current->RightChild());
	} else if(!itrStack.Empty()) {
		current = &(itrStack.TopNPop()->RightChild());
	} else {
		current = nullptr;
	} return *this;
}

template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
	itrStack.Clear();
	current = reset;
}

template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*() {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree) noexcept {
    reset = tree.Empty() ? nullptr : &(tree.Root());
    if (reset == nullptr) {
	    current = nullptr;
    } else if (Explore(reset) != nullptr)
    	current = itrStack.TopNPop();
}

template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
	itrStack.Clear();
	if(Explore(reset) != nullptr) {
		current = itrStack.TopNPop();
	}
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (current == nullptr) throw std::out_of_range("Iterator already terminated");
    if (itrStack.Empty()) current = nullptr;
    else {
        if (itrStack.Top()->HasLeftChild() && current == &(itrStack.Top()->LeftChild())) {
	        if (itrStack.Top()->HasRightChild()) {
	        	Explore(&(itrStack.Top()->RightChild()));
	        }
        }
        current = itrStack.TopNPop();
    }
    return *this;
}

template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& toCompare) const noexcept {
	return (current == toCompare.current && reset == toCompare.reset);
}

template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
	return current == nullptr;
}

template <typename Data>
typename BTPostOrderIterator<Data>::Node const* BTPostOrderIterator<Data>::Explore(Node const* node){
	while (node != nullptr){
		itrStack.Push(node);
		if (node->IsLeaf()) return (itrStack.Empty())? nullptr : itrStack.Top();
		else if (node->HasLeftChild())  node = &(node->LeftChild());
		else if (node->HasRightChild()) node = &(node->RightChild());
	}
	return nullptr;
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator& toCompare) const noexcept {
	return (current == toCompare.current && reset == toCompare.reset);
}

template<typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*() {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template<typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& toCompare) const noexcept {
	return toCompare.current == current && toCompare.reset == reset;
}

template<typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& toCompare) const noexcept {
	return !(*this == toCompare);
}

template <typename Data> BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree) noexcept {
    reset = (tree.Empty())? nullptr : &(tree.Root());
    if (reset == nullptr) current = nullptr;
    else if (ExploreInOrder() != nullptr) current = itrStack.TopNPop();
}

template <typename Data> void BTInOrderIterator<Data>::Reset() noexcept {
    itrStack.Clear();
    if (ExploreInOrder(reset) != nullptr)
    	current = itrStack.TopNPop();
}

template <typename Data>
typename BTInOrderIterator<Data>::Node const* BTInOrderIterator<Data>::ExploreInOrder(Node const* node) {
    while (node != nullptr){
        itrStack.Push(node);
        node = (node->HasLeftChild())? &(node->LeftChild()) : nullptr;
    }
    return (itrStack.Empty())? nullptr : itrStack.Top();
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (current == nullptr) throw std::out_of_range("attempt to increment a terminated iterator");
    if (current->HasRightChild()) NavigateToLeft(&(current->RightChild()));
    current = (itrStack.Empty())? nullptr : itrStack.TopNPop();
    return *this;
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
		if (current == nullptr) throw std::out_of_range("attempt to dereference a terminated iterator");
		return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
		return current == nullptr;
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator& toCompare) const noexcept {
	return (current == toCompare.current && reset == toCompare.reset);
}

template<typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
Data &BTInOrderMutableIterator<Data>::operator*() {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree) noexcept {
	itrQueue = lasd::QueueVec<Node const*>();
	current = (tree.Empty())? nullptr : &(tree.Root());
	reset = current;
}

template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& toCompare) const noexcept {
	return toCompare.current == current && toCompare.reset == reset;
}

template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& toCompare) const noexcept {
	return !(*this == toCompare);
}

template<typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
	if(current == nullptr)
		throw std::out_of_range("Iterator out of range");
	return current->Element();
}

template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
	return current == nullptr;
}

template <typename Data> void BTBreadthIterator<Data>::Reset() noexcept {
  itrQueue.Clear();
  current = reset;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
  if (current == nullptr)
  	throw std::out_of_range("Iterator already terminated");
  if(current->HasLeftChild())
  	itrQueue.Enqueue(&(current->LeftChild()));
  if(current->HasRightChild())
  	itrQueue.Enqueue(&(current->RightChild()));
	current = (!itrQueue.Empty()) ? itrQueue.HeadNDequeue() : nullptr;
  return *this;
}


/* ************************************************************************** */

}
