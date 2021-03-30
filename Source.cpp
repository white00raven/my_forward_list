#include<iostream>
#include"forward_list.h"
void main()
 {
	 forward_list<int>list;
	 for (int i = 100; i != 0; --i)
		 list.push_front(i);
	 auto it = list.begin();
	 for (;it != list.end(); ++it)
	 {
		 std::cout << *it << std::endl;
	 }
	 auto iter2 = list.begin();
	 ++iter2;
	 list.insert_after(iter2, 111);
	 for (auto iter = list.begin(); iter != list.end(); ++iter)
	 {
		 std::cout << *iter << std::endl;
	 }
	 iter2 = list.find(111);
	 list.erase_after(iter2);
	 for (auto iter = list.begin(); iter != list.end(); ++iter)
	 {
		 std::cout << *iter << std::endl;
	 }
	 for (int i = 100; i != 0; --i)
		 list.pop_front();
	 for (auto it = list.begin();it != list.end(); ++it)
	 {
		 std::cout << *it << std::endl;
	 }
 }