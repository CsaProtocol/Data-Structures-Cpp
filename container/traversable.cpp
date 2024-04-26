
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool TraversableContainer<Data>::Exists(const Data& toFind) const noexcept {
	bool existance = false;
	auto existsFunctor = [&existance, &toFind] (const Data& data) {
		if (data == toFind) {
			existance = true;
		}
	};
	Traverse(existsFunctor);
	return existance;
}

template<typename Data>
template<typename Accumulator>
Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> foldFun, Accumulator init) const {
	Accumulator accumulator = init;
	auto foldFunctor = [&accumulator, &foldFun] (const Data& data) {
		accumulator = foldFun(data, accumulator);
	};
	Traverse(foldFunctor);
	return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> foldFun, Accumulator init) const {
	Accumulator accumulator = init;
	auto foldFunctor = [&accumulator, &foldFun] (const Data& data) {
		accumulator = foldFun(data, accumulator);
	};
	PreOrderTraverse(foldFunctor);
	return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> foldFun, Accumulator init) const {
	Accumulator accumulator = init;
	auto foldFunctor = [&accumulator, &foldFun] (const Data& data) {
		accumulator = foldFun(data, accumulator);
	};
	PostOrderTraverse(foldFunctor);
	return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> foldFun, Accumulator init) const {
	Accumulator accumulator = init;
	auto foldFunctor = [&accumulator, &foldFun] (const Data& data) {
		accumulator = foldFun(data, accumulator);
	};
	InOrderTraverse(foldFunctor);
	return accumulator;
}

template<typename Data>
template<typename Accumulator>
Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> foldFun, Accumulator init) const {
	Accumulator accumulator = init;
	auto foldFunctor = [&accumulator, &foldFun] (const Data& data) {
		accumulator = foldFun(data, accumulator);
	};
	BreadthTraverse(foldFunctor);
	return accumulator;
}

/* ************************************************************************** */

}
