
namespace lasd {

/* ************************************************************************** */

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
	if (left == nullptr) {
		throw std::out_of_range("No left child");
	}
	return *left;
}

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
	if (right == nullptr) {
		throw std::out_of_range("No right child");
	}
	return *right;
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
	if (left == nullptr) {
		throw std::out_of_range("No left child");
	}
	return *left;
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
	if (right == nullptr) {
		throw std::out_of_range("No right child");
	}
	return *right;
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& container) {
	QueueVec<NodeLnk*> que;
	auto functor = [&que, this] (const Data& toCopy) {
		this->AuxConstructorBreadth<const Data&>(que, toCopy);
	};
	container.Traverse(functor);
	size = container.Size();
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& container) noexcept {
	QueueVec<NodeLnk*> que;
	auto functor = [&que, this] (Data& toMove) {
		this->AuxConstructorBreadth<Data&&>(que, std::move(toMove));
	};
	container.MapPreOrder(functor);
	size = container.Size();
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& tree) {
	if(tree.Empty()) {
		return;
	}
	AuxCopy(root, tree.root);
	size = tree.size;
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& tree) noexcept {
	std::swap(root, tree.root);
	std::swap(size, tree.size);
}

template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& tree) {
	if(tree.Empty()) {
		this->Clear();
		this->size = 0;
		return *this;
	}
	if(this != &tree) {
		this->Clear();
		AuxCopy(root, tree.root);
		size = tree.size;
	}
	return *this;
}

template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& tree) noexcept {
	std::swap(root, tree.root);
	std::swap(size, tree.size);
	return *this;
}

template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
	if(root != nullptr) {
		delete root;
		root = nullptr;
		size = 0;
	}
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& toCompare) const noexcept {
	if(size != toCompare.Size()) return false;
	return AuxEqual(root, toCompare.root);
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& tree) const noexcept {
	return !(*this == tree);
}

template<typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
	if (root == nullptr) {
		throw std::out_of_range("No root");
	}
	return *root;
}

template<typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
	if (root == nullptr) {
		throw std::out_of_range("No root");
	}
	return *root;
}

template<typename Data>
void BinaryTreeLnk<Data>::Clear() {
	if(root != nullptr) {
		delete root;
		root = nullptr;
		size = 0;
	}
}

template<typename Data> template<typename GLPRvalue>
void BinaryTreeLnk<Data>::AuxConstructorBreadth(QueueVec<NodeLnk*>& que, GLPRvalue&& value) {
	if(que.Empty()) {
		root = new NodeLnk{std::forward<GLPRvalue>(value)};
		que.Enqueue(root);
	} else if (que.Head()->IsLeaf()) {
		que.Head()->left = new NodeLnk{std::forward<GLPRvalue>(value)};
		que.Enqueue(que.Head()->left);
	} else {
		que.Head()->right = new NodeLnk{std::forward<GLPRvalue>(value)};
		que.Enqueue(que.Head()->right);
		que.Dequeue();
	}
}

template<typename Data>
void BinaryTreeLnk<Data>::AuxCopy(NodeLnk* tree, const NodeLnk* toCopy) {
	if (toCopy != nullptr) {
		tree = new NodeLnk{toCopy->value};
		AuxCopy(tree->left, toCopy->left);
		AuxCopy(tree->right, toCopy->right);
	}
}

template<typename Data>
bool BinaryTreeLnk<Data>::AuxEqual(const NodeLnk* first_tree , const NodeLnk* toCompare) const noexcept {
	// If both are nullptr, they are equal (encompasses both empty)
	if(first_tree == nullptr && toCompare == nullptr) {
		return true;
	} if(first_tree == nullptr || toCompare == nullptr) {
		return false;
	} if(first_tree->value != toCompare->value) {
		return false;
	} return AuxEqual(first_tree->left, toCompare->left) && AuxEqual(first_tree->right, toCompare->right);
}

/* ************************************************************************** */

}
