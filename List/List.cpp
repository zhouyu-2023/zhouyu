#include "List.h"
#include <iostream>

int main()
{

    // 创建一个链表
    List<int> myList{4,5};

    // 测试插入元素
    myList.push_back(6);
    myList.push_back(7);
    myList.push_front(3);
    myList.push_front(2);
    std::cout << "List after inserting elements: ";
    for (List<int>::const_iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " "; // 读取操作
    }
    std::cout << std::endl;
    int leftValue1 = 8;
    int leftValue2 = 1;
    myList.push_front(leftValue2);
    myList.push_back(leftValue1);
    std::cout <<"leftValue: ";
    for(List<int>::const_iterator it = myList.begin();it !=myList.end();++it)
    {
        std::cout <<*it <<" ";
    }    
    std::cout << std::endl;

    // 测试大小和是否为空
    std::cout << "Size: " << myList.size() << ", Empty: " << (myList.empty() ? "Yes" : "No") << std::endl;

    //测试++功能和--功能
    List<int>::const_iterator it1 = myList.begin();
    List<int>::const_iterator it2 = it1++;
    if(*it1 == 2 && *it2 == 1)
    {
        std::cout << "true1" << std::endl;
    }
    else
    {
        std::cout<<"False"<< std::endl;
    }

    List<int>::const_iterator it3 = myList.begin();
    ++it3;
    if(*it3 == 2)
    {
        std::cout << "true2" << std::endl;
    }
    else
    {
        std::cout<<"False"<< std::endl;
    }

    List<int>::const_iterator it4 = myList.end();
    List<int>::const_iterator it5 = it4--;
    if( *it4 == 8 && it5 == myList.end())
    {
        std::cout << "true3" << std::endl;
    }
    else
    {
        std::cout<<"False"<< std::endl;
    }

    List<int>::const_iterator it6 = myList.end();
    --it6;
    if(*it6 == 8)
    {
        std::cout << "true4" << std::endl;
    }
    else
    {
        std::cout<<"False"<< std::endl;
    }

    // 测试访问首尾元素
    std::cout << "Front: " << myList.front() << ", Back: " << myList.back() << std::endl;

    // 测试删除元素
    myList.pop_front();
    myList.pop_back();
    std::cout << "List after popping front and back: ";
    for (List<int>::const_iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试清空
    myList.clear();
    std::cout << "List after clearing: Size: " << myList.size() << std::endl;

    // 测试拷贝构造
    myList.push_back(3);
    myList.push_back(4);
    List<int> copyList = myList;
    std::cout << "Copy of List: ";
    for (List<int>::const_iterator it = copyList.begin(); it != copyList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试赋值运算符
    List<int> anotherList;
    anotherList = myList;
    std::cout << "Another List after assignment: ";
    for (List<int>::const_iterator it = anotherList.begin(); it != anotherList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


