#include "list.hpp"

void ListIntTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<int> list;
    Empty(testnum, testerr, list, true);

    lasd::List<int> list2;
    for(int i = 0; i < 10; ++i) {
        InsertAtBack(testnum, testerr, list2, true, i);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    list2.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list2, true, i);
    }
    list.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list, true, i);
    }
    NonEqualLinear(testnum, testerr, list, list2, false);
    list2.InsertAtBack(3); list.InsertAtBack(3);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::MappableContainer<int>::MapFun mapfun = [](int& val) { val *= 2; };
    Map(testnum, testerr, list, true, mapfun);
    Exists(testnum, testerr, list, true, 6);
    MapPostOrder(testnum, testerr, list2, true, mapfun);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::TraversableContainer<int>::TraverseFun travfun = [](const int& val) { std::cout << val << " "; };
    Traverse(testnum, testerr, list, true, travfun);
    TraversePreOrder(testnum, testerr, list, true, travfun);
    TraversePostOrder(testnum, testerr, list, true, travfun);

    lasd::TraversableContainer<int>::FoldFun<int> foldfun = [](const int& element, const int& accumulator) -> int {
        return accumulator + element;
    };
    Fold(testnum, testerr, list, true, foldfun, 0, 12);
    FoldPreOrder(testnum, testerr, list, true, foldfun, 0, 12);
    FoldPostOrder(testnum, testerr, list, true, foldfun, 0, 12);

    lasd::List<int> list3(list);
    lasd::List<int> list4(std::move(list));
    EqualLinear(testnum, testerr, list3, list4, true);
    EqualLinear(testnum, testerr, list, list4, false);
    InsertAtBack(testnum, testerr, list4, true, 150);
    Exists(testnum, testerr, list4, true, 150);
    RemoveFromFront(testnum, testerr, list4, true);
    Exists(testnum, testerr, list4, true, 150);

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    InsertAtBack(testnum, testerr, list4, true, 1);
    InsertAtBack(testnum, testerr, list4, true, 2);
    Exists(testnum, testerr, list4, true, 1);
}

void ListDoubleTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<double> list;
    Empty(testnum, testerr, list, true);

    lasd::List<double> list2;
    for(int i = 0; i < 10; ++i) {
        InsertAtBack(testnum, testerr, list2, true, i * 1.1);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    list2.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list2, true, i * 1.1);
    }
    list.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list, true, i * 1.1);
    }
    NonEqualLinear(testnum, testerr, list, list2, false);
    InsertAtBack(testnum, testerr, list2, true, 3.3);
    InsertAtBack(testnum, testerr, list, true, 3.3);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::MappableContainer<double>::MapFun mapfun = [](double& val) { val *= 2; };
    Map(testnum, testerr, list, true, mapfun);
    Exists(testnum, testerr, list, true, 6.6);
    MapPostOrder(testnum, testerr, list2, true, mapfun);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::TraversableContainer<double>::TraverseFun travfun = [](const double& val) { std::cout << val << " "; };
    Traverse(testnum, testerr, list, true, travfun);
    TraversePreOrder(testnum, testerr, list, true, travfun);
    TraversePostOrder(testnum, testerr, list, true, travfun);

    lasd::TraversableContainer<double>::FoldFun<double> foldfun = [](const double& element, const double& accumulator) -> double {
        return accumulator + element;
    };
    Fold(testnum, testerr, list, true, foldfun, 0.0, 13.2);
    FoldPreOrder(testnum, testerr, list, true, foldfun, 0.0, 13.2);
    FoldPostOrder(testnum, testerr, list, true, foldfun, 0.0, 13.2);

    lasd::List<double> list3(list);
    lasd::List<double> list4(std::move(list));
    EqualLinear(testnum, testerr, list3, list4, true);
    EqualLinear(testnum, testerr, list, list4, false);
    InsertAtBack(testnum, testerr, list4, true, 150.5);
    Exists(testnum, testerr, list4, true, 150.5);
    RemoveFromFront(testnum, testerr, list4, true);
    Exists(testnum, testerr, list4, true, 150.5);

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    InsertAtBack(testnum, testerr, list4, true, 1.1);
    InsertAtBack(testnum, testerr, list4, true, 2.2);
    Exists(testnum, testerr, list4, true, 1.1);
}

void ListStringTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<std::string> list;
    Empty(testnum, testerr, list, true);

    lasd::List<std::string> list2;
    for(int i = 0; i < 10; ++i) {
        InsertAtBack(testnum, testerr, list2, true, std::to_string(i));
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    list2.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list2, true, std::to_string(i));
    }
    list.Clear();
    for(int i = 0; i < 3; ++i) {
        InsertAtBack(testnum, testerr, list, true, std::to_string(i));
    }
    NonEqualLinear(testnum, testerr, list, list2, false);
    InsertAtBack(testnum, testerr, list2, true, std::string("3"));
    InsertAtBack(testnum, testerr, list, true, std::string("3"));
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::MappableContainer<std::string>::MapFun mapfun = [](std::string& val) { val += " mapped"; };
    Map(testnum, testerr, list, true, mapfun);
    Exists(testnum, testerr, list, true, std::string("1 mapped"));
    MapPostOrder(testnum, testerr, list2, true, mapfun);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::TraversableContainer<std::string>::TraverseFun travfun = [](const std::string& val) { std::cout << val << " "; };
    Traverse(testnum, testerr, list, true, travfun);
    TraversePreOrder(testnum, testerr, list, true, travfun);
    TraversePostOrder(testnum, testerr, list, true, travfun);

    lasd::TraversableContainer<std::string>::FoldFun<std::string> foldfun = [](const std::string& element, const std::string& accumulator) -> std::string {
        return accumulator + element;
    };
    Fold(testnum, testerr, list, true, foldfun, std::string(""), std::string("0 mapped1 mapped2 mapped3 mapped"));
    FoldPreOrder(testnum, testerr, list, true, foldfun, std::string(""), std::string("0 mapped1 mapped2 mapped3 mapped"));
    FoldPostOrder(testnum, testerr, list, true, foldfun, std::string(""), std::string("3 mapped2 mapped1 mapped0 mapped"));

    lasd::List<std::string> list3(list);
    lasd::List<std::string> list4(std::move(list));
    EqualLinear(testnum, testerr, list3, list4, true);
    EqualLinear(testnum, testerr, list, list4, false);
    InsertAtBack(testnum, testerr, list4, true, std::string("test"));
    Exists(testnum, testerr, list4, true, std::string("test"));
    RemoveFromFront(testnum, testerr, list4, true);
    Exists(testnum, testerr, list4, true, std::string("test"));

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    InsertAtBack(testnum, testerr, list4, true, std::string("test"));
    InsertAtBack(testnum, testerr, list4, true, std::string("test2"));
    Exists(testnum, testerr, list4, true, std::string("test"));
}

void ListBoolTest(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<bool> list;
    Empty(testnum, testerr, list, true);

    lasd::List<bool> list2;
    for(int i = 0; i < 10; ++i) {
        list2.InsertAtBack(i % 2 == 0);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    list2.Clear();
    for(int i = 0; i < 3; ++i) {
        list2.InsertAtBack(i % 2 == 0);
    }
    list.Clear();
    for(int i = 0; i < 3; ++i) {
        list.InsertAtBack(i % 2 == 0);
    }
    NonEqualLinear(testnum, testerr, list, list2, false);
    list2.InsertAtBack(true); list.InsertAtBack(true);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::MappableContainer<bool>::MapFun mapfun = [](bool& val) { val = !val; };
    Map(testnum, testerr, list, true, mapfun);
    Exists(testnum, testerr, list, true, true);
    MapPostOrder(testnum, testerr, list2, true, mapfun);
    EqualLinear(testnum, testerr, list, list2, true);

    lasd::TraversableContainer<bool>::TraverseFun travfun = [](const bool& val) { std::cout << (val ? "true" : "false") << " "; };
    Traverse(testnum, testerr, list, true, travfun);
    TraversePreOrder(testnum, testerr, list, true, travfun);
    TraversePostOrder(testnum, testerr, list, true, travfun);

    lasd::TraversableContainer<bool>::FoldFun<bool> foldfun = [](const bool& element, const bool& accumulator) -> bool {
        return accumulator || element;
    };
    Fold(testnum, testerr, list, true, foldfun, false, true);
    FoldPreOrder(testnum, testerr, list, true, foldfun, false, true);
    FoldPostOrder(testnum, testerr, list, true, foldfun, false, true);

    lasd::List<bool> list3(list);
    lasd::List<bool> list4(std::move(list));
    EqualLinear(testnum, testerr, list3, list4, true);
    EqualLinear(testnum, testerr, list, list4, false);
    list4.InsertAtBack(true);
    Exists(testnum, testerr, list4, true, true);
    list4.RemoveFromFront();
    Exists(testnum, testerr, list4, true, true);

    list4.Clear();
    Empty(testnum, testerr, list4, true);
    list4.InsertAtBack(true);
    list4.InsertAtBack(false);
    Exists(testnum, testerr, list4, true, true);
}

void testList(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "Testing List<int>" << std::endl;
    ListIntTest(testnum, testerr);

    std::cout << "Testing List<double>" << std::endl;
    ListDoubleTest(testnum, testerr);

    std::cout << "Testing List<std::string>" << std::endl;
    ListStringTest(testnum, testerr);

    std::cout << "Testing List<bool>" << std::endl;
    ListBoolTest(testnum, testerr);
}

void testDictionaryListInt(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<int> list;
    Empty(testnum, testerr, list, true);

    lasd::List<int> list2;
    for(int i = 0; i < 10; ++i) {
        InsertC(testnum, testerr, list2, true, i);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    lasd::List<int> list3(list2);
    RemoveAll(testnum, testerr, list2, true, list3);
    Empty(testnum, testerr, list2, true);

    std::vector<int> vec = {1, 2, 3, 4, 5};
    for(int i : vec) {
        InsertC(testnum, testerr, list2, true, i);
    }
    NonEqualList(testnum, testerr, list2, list, true);
    list.Clear();
    lasd::Vector<int> vec2(list2);
    InsertAllM(testnum, testerr, list, true, std::move(vec2));
    EqualList(testnum, testerr, list, list2, true);

    lasd::Vector<int> vec3(list2);
    InsertSomeC(testnum, testerr, list2, false, vec3);
    NonEqualList(testnum, testerr, list2, list, false);

}

void testDictionaryListString(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<std::string> list;
    Empty(testnum, testerr, list, true);

    lasd::List<std::string> list2;
    for(int i = 0; i < 10; ++i) {
        InsertC(testnum, testerr, list2, true, std::to_string(i));
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    lasd::List<std::string> list3(list2);
    RemoveAll(testnum, testerr, list2, true, list3);
    Empty(testnum, testerr, list2, true);

    std::vector<std::string> vec = {"one", "two", "three", "four", "five"};
    for(const auto& str : vec) {
        InsertC(testnum, testerr, list2, true, str);
    }
    NonEqualList(testnum, testerr, list2, list, true);
    list.Clear();
    lasd::Vector<std::string> vec2(list2);
    InsertAllM(testnum, testerr, list, true, std::move(vec2));
    EqualList(testnum, testerr, list, list2, true);

    lasd::Vector<std::string> vec3(list2);
    InsertSomeC(testnum, testerr, list2, false, vec3);
    NonEqualList(testnum, testerr, list2, list, false);
}

void testDictionaryListDouble(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<double> list;
    Empty(testnum, testerr, list, true);

    lasd::List<double> list2;
    for(int i = 0; i < 10; ++i) {
        InsertC(testnum, testerr, list2, true, i * 1.1);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 10);

    lasd::List<double> list3(list2);
    RemoveAll(testnum, testerr, list2, true, list3);
    Empty(testnum, testerr, list2, true);

    std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};
    for(const auto& val : vec) {
        InsertC(testnum, testerr, list2, true, val);
    }
    NonEqualList(testnum, testerr, list2, list, true);
    list.Clear();
    lasd::Vector<double> vec2(list2);
    InsertAllM(testnum, testerr, list, true, std::move(vec2));
    EqualList(testnum, testerr, list, list2, true);

    lasd::Vector<double> vec3(list2);
    InsertSomeC(testnum, testerr, list2, false, vec3);
    NonEqualList(testnum, testerr, list2, list, false);
}

void testDictionaryListBool(unsigned int& testnum, unsigned int& testerr) {
    lasd::List<bool> list;
    Empty(testnum, testerr, list, true);

    lasd::List<bool> list2;
    for(int i = 0; i < 2; ++i) {
        InsertC(testnum, testerr, list2, true, i % 2 == 0);
    }
    Empty(testnum, testerr, list2, false);
    Size(testnum, testerr, list2, true, 2);

    lasd::List<bool> list3(list2);
    RemoveAll(testnum, testerr, list2, true, list3);
    Empty(testnum, testerr, list2, true);

    lasd::Vector<bool> vec(5);
    for(int i = 0; i < 5; ++i) {
        vec[i] = (i % 2 == 0);
    }
    for(uint i = 0; i < vec.Size(); i++) {
        InsertSomeC(testnum, testerr, list2, false, vec);
    }
    NonEqualList(testnum, testerr, list2, list, true);
    list.Clear();
    lasd::Vector<bool> vec2(list2);
    InsertAllM(testnum, testerr, list, true, std::move(vec2));
    EqualList(testnum, testerr, list, list2, true);

    lasd::Vector<bool> vec3(list2);
    InsertSomeC(testnum, testerr, list2, false, vec3);
    NonEqualList(testnum, testerr, list2, list, false);
}

void testDictionaryList(unsigned int& testnum, unsigned int& testerr) {
    std::cout << "Testing DictionaryList<int>" << std::endl;
    testDictionaryListInt(testnum, testerr);

    std::cout << "Testing DictionaryList<std::string>" << std::endl;
    testDictionaryListString(testnum, testerr);

    std::cout << "Testing DictionaryList<double>" << std::endl;
    testDictionaryListDouble(testnum, testerr);

    std::cout << "Testing DictionaryList<bool>" << std::endl;
    testDictionaryListBool(testnum, testerr);
}