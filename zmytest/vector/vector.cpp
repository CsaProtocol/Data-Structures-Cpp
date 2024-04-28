#include "vector.hpp"

void vecIntTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::SortableVector<int> vec(0);
	Empty(testnum, testerr, vec, true);

	lasd::SortableVector<int> vec2(10);
	Empty(testnum, testerr, vec2, false);
	Size(testnum, testerr, vec2, true, 10);

	vec2.Clear(); vec2.Resize(3);
	vec.Clear(); vec.Resize(3);
	SetAt(testnum, testerr, vec, true, 0, 1);
	SetAt(testnum, testerr, vec, true, 1, 3);
	SetAt(testnum, testerr, vec, true, 2, 2);
	SetAt(testnum, testerr, vec2, true, 0, 3);
	SetAt(testnum, testerr, vec2, true, 1, 2);
	SetAt(testnum, testerr, vec2, true, 2, 1);
	NonEqualVector(testnum, testerr, vec, vec2, true);
	vec2.Sort(); vec.Sort();
	EqualVector(testnum, testerr, vec, vec2, true);

	lasd::MappableContainer<int>::MapFun mapfun = [](int& val) { val *= 2; };
	Map(testnum, testerr, vec, true, mapfun);
	Exists(testnum, testerr, vec, true, 6);
	MapPostOrder(testnum, testerr, vec2, true, mapfun);
	EqualVector(testnum, testerr, vec, vec2, true);

	lasd::TraversableContainer<int>::TraverseFun travfun = [](const int& val) { std::cout << val << " "; };
	Traverse(testnum, testerr, vec, true, travfun);
	TraversePreOrder(testnum, testerr, vec, true, travfun);
	TraversePostOrder(testnum, testerr, vec, true, travfun);

	lasd::TraversableContainer<int>::FoldFun<int> foldfun = [](const int& element, const int& accumulator) -> int {
		return accumulator + element;
	};
	Fold(testnum, testerr, vec, true, foldfun, 0, 12);
	FoldPreOrder(testnum, testerr, vec, true, foldfun, 0, 12);
	FoldPostOrder(testnum, testerr, vec, true, foldfun, 0, 12);

	lasd::SortableVector<int> vec3(vec);
	lasd::SortableVector<int> vec4(std::move(vec));
	EqualVector(testnum, testerr, vec3, vec4, true);
	EqualVector(testnum, testerr, vec, vec4, false);
	vec4.Front() = 150;
	Exists(testnum, testerr, vec4, true, 150);
	vec4.Back() = 300;
	Exists(testnum, testerr, vec4, true, 300);

	vec4.Resize(0);
	Empty(testnum, testerr, vec4, true);
	SetAt(testnum, testerr, vec4, false, 0, 1);
	vec4.Resize(2);
	SetAt(testnum, testerr, vec4, true, 0, 1);
	vec4.Resize(5);
	Exists(testnum, testerr, vec4, true, 1);
}

void vecDoubleTest(unsigned int& testnum, unsigned int& testerr) {
	lasd::SortableVector<double> vec(0);
	Empty(testnum, testerr, vec, true);

	lasd::SortableVector<double> vec2(10);
	Empty(testnum, testerr, vec2, false);
	Size(testnum, testerr, vec2, true, 10);

	vec2.Clear(); vec2.Resize(3);
	vec.Clear(); vec.Resize(3);
	SetAt(testnum, testerr, vec, true, 0, 1.5);
	SetAt(testnum, testerr, vec, true, 1, 3.5);
	SetAt(testnum, testerr, vec, true, 2, 2.8);
	SetAt(testnum, testerr, vec2, true, 0, 3.5);
	SetAt(testnum, testerr, vec2, true, 1, 2.8);
	SetAt(testnum, testerr, vec2, true, 2, 1.5);
	NonEqualVector(testnum, testerr, vec, vec2, true);
	vec2.Sort(); vec.Sort();
	EqualVector(testnum, testerr, vec, vec2, true);

	lasd::MappableContainer<double>::MapFun mapfun = [](double& val) { val *= 2; };
	Map(testnum, testerr, vec, true, mapfun);
	Exists(testnum, testerr, vec, true, 5.6);
	MapPostOrder(testnum, testerr, vec2, true, mapfun);
	EqualVector(testnum, testerr, vec, vec2, true);

	lasd::TraversableContainer<int>::TraverseFun travfun = [](const int& val) { std::cout << val << " "; };
	Traverse(testnum, testerr, vec, true, travfun);
	TraversePreOrder(testnum, testerr, vec, true, travfun);
	TraversePostOrder(testnum, testerr, vec, true, travfun);

	lasd::TraversableContainer<double>::FoldFun<double> foldfun = [](const double& element, const double& accumulator) -> double {
		return accumulator + element;
	};
	Fold(testnum, testerr, vec, true, foldfun, 0.0, 15.6);
	FoldPreOrder(testnum, testerr, vec, true, foldfun, 0.0, 15.6);
	FoldPostOrder(testnum, testerr, vec, true, foldfun, 0.0, 15.6);

	lasd::SortableVector<double> vec3(vec);
	lasd::SortableVector<double> vec4(std::move(vec));
	EqualVector(testnum, testerr, vec3, vec4, true);
	EqualVector(testnum, testerr, vec, vec4, false);
	vec4.Front() = 150.5;
	Exists(testnum, testerr, vec4, true, 150.5);
	vec4.Back() = 300.5;
	Exists(testnum, testerr, vec4, true, 300.5);

	vec4.Resize(0);
	Empty(testnum, testerr, vec4, true);
	SetAt(testnum, testerr, vec4, false, 0, 1.5);
	vec4.Resize(2);
	SetAt(testnum, testerr, vec4, true, 0, 1.5);
	vec4.Resize(5);
	Exists(testnum, testerr, vec4, true, 1.5);
}

void vecStringTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<std::string> vec(0);
    Empty(testnum, testerr, vec, true);

    lasd::SortableVector<std::string> vec2(10);
    Empty(testnum, testerr, vec2, false);
    Size(testnum, testerr, vec2, true, 10);

    vec2.Clear(); vec2.Resize(3);
    vec.Clear(); vec.Resize(3);
    SetAt(testnum, testerr, vec, true, 0, std::string("apple"));
    SetAt(testnum, testerr, vec, true, 1, std::string("banana"));
    SetAt(testnum, testerr, vec, true, 2, std::string("cherry"));
    SetAt(testnum, testerr, vec2, true, 0, std::string("banana"));
    SetAt(testnum, testerr, vec2, true, 1, std::string("cherry"));
    SetAt(testnum, testerr, vec2, true, 2, std::string("apple"));
    NonEqualVector(testnum, testerr, vec, vec2, true);
    vec2.Sort(); vec.Sort();
    EqualVector(testnum, testerr, vec, vec2, true);

    lasd::MappableContainer<std::string>::MapFun mapfun = [](std::string& val) { val += " mapped"; };
    Map(testnum, testerr, vec, true, mapfun);
    Exists(testnum, testerr, vec, true, std::string("apple mapped"));
    MapPostOrder(testnum, testerr, vec2, true, mapfun);
    EqualVector(testnum, testerr, vec, vec2, true);

    lasd::TraversableContainer<std::string>::TraverseFun travfun = [](const std::string& val) { std::cout << val << " "; };
    Traverse(testnum, testerr, vec, true, travfun);
    TraversePreOrder(testnum, testerr, vec, true, travfun);
    TraversePostOrder(testnum, testerr, vec, true, travfun);

    lasd::TraversableContainer<std::string>::FoldFun<std::string> foldfun = [](const std::string& element, const std::string& accumulator) -> std::string {
        return accumulator + element;
    };
    Fold(testnum, testerr, vec, true, foldfun, std::string(""), std::string("apple mappedbanana mappedcherry mapped"));
    FoldPreOrder(testnum, testerr, vec, true, foldfun, std::string(""), std::string("apple mappedbanana mappedcherry mapped"));
    FoldPostOrder(testnum, testerr, vec, true, foldfun, std::string(""), std::string("cherry mappedbanana mappedapple mapped"));

    lasd::SortableVector<std::string> vec3(vec);
    lasd::SortableVector<std::string> vec4(std::move(vec));
    EqualVector(testnum, testerr, vec3, vec4, true);
    EqualVector(testnum, testerr, vec, vec4, false);
    vec4.Front() = "kiwi";
    Exists(testnum, testerr, vec4, true, std::string("kiwi"));
    vec4.Back() = "mango";
    Exists(testnum, testerr, vec4, true, std::string("mango"));

    vec4.Resize(0);
    Empty(testnum, testerr, vec4, true);
    SetAt(testnum, testerr, vec4, false, 0, std::string("pear"));
    vec4.Resize(2);
    SetAt(testnum, testerr, vec4, true, 0, std::string("pear"));
    vec4.Resize(5);
    Exists(testnum, testerr, vec4, true, std::string("pear"));
}

void vecBoolTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::SortableVector<bool> vec(0);
    Empty(testnum, testerr, vec, true);

    lasd::SortableVector<bool> vec2(10);
    Empty(testnum, testerr, vec2, false);
    Size(testnum, testerr, vec2, true, 10);

    vec2.Clear(); vec2.Resize(3);
    vec.Clear(); vec.Resize(3);
    SetAt(testnum, testerr, vec, true, 0, true);
    SetAt(testnum, testerr, vec, true, 1, false);
    SetAt(testnum, testerr, vec, true, 2, true);
    SetAt(testnum, testerr, vec2, true, 0, false);
    SetAt(testnum, testerr, vec2, true, 1, true);
    SetAt(testnum, testerr, vec2, true, 2, true);
    NonEqualVector(testnum, testerr, vec, vec2, true);
    vec2.Sort(); vec.Sort();
    EqualVector(testnum, testerr, vec, vec2, true);

    lasd::MappableContainer<bool>::MapFun mapfun = [](bool& val) { val = !val; };
    Map(testnum, testerr, vec, true, mapfun);
    Exists(testnum, testerr, vec, true, false);
    MapPostOrder(testnum, testerr, vec2, true, mapfun);
    EqualVector(testnum, testerr, vec, vec2, true);

    lasd::TraversableContainer<bool>::TraverseFun travfun = [](const bool& val) { std::cout << (val ? "true" : "false") << " "; };
    Traverse(testnum, testerr, vec, true, travfun);
    TraversePreOrder(testnum, testerr, vec, true, travfun);
    TraversePostOrder(testnum, testerr, vec, true, travfun);

    lasd::TraversableContainer<bool>::FoldFun<bool> foldfun = [](const bool& element, const bool& accumulator) -> bool {
        return accumulator || element;
    };
    Fold(testnum, testerr, vec, true, foldfun, false, true);
    FoldPreOrder(testnum, testerr, vec, true, foldfun, false, true);
    FoldPostOrder(testnum, testerr, vec, true, foldfun, false, true);

    lasd::SortableVector<bool> vec3(vec);
    lasd::SortableVector<bool> vec4(std::move(vec));
    EqualVector(testnum, testerr, vec3, vec4, true);
    EqualVector(testnum, testerr, vec, vec4, false);
    vec4.Front() = true;
    Exists(testnum, testerr, vec4, true, true);
    vec4.Back() = false;
    Exists(testnum, testerr, vec4, true, false);

    vec4.Resize(0);
    Empty(testnum, testerr, vec4, true);
    SetAt(testnum, testerr, vec4, false, 0, true);
    vec4.Resize(2);
    SetAt(testnum, testerr, vec4, true, 0, true);
    vec4.Resize(5);
    Exists(testnum, testerr, vec4, true, true);
}

void testVector(unsigned int& testnum, unsigned int& testerr) {

	std::cout << "Testing Vector<int>:" << std::endl;
	vecIntTest(testnum, testerr);

	std::cout << std::endl << "Testing Vector<double>:" << std::endl;
	vecDoubleTest(testnum, testerr);

	std::cout << std::endl << "Testing Vector<std::string>" << std::endl;
	vecStringTest(testnum, testerr);

	std::cout << std::endl << "Testing Vector<bool>" << std::endl;
	vecBoolTest(testnum, testerr);

}
