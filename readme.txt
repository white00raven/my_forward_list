Программа реализует мою версию односвязного списка.программа состоит из двух файлов кода. В forward_list.h 
находится реализация списка ,а в Source.cpp представлены примеры работы.
В классе списка входят такие методы:
public:
	forward_list()
	~forward_list()
	iterator begin() - возвращает итератор на первый элемент
	iterator end() -возвращает итератор на элемент после последнего
	iterator before_begin() -возвращает итератор перед первым
	void insert_after(iterator& iter, T elem)-вставляет элемент после итератора
	void push_front(T elem)-вставляет вперед
	void pop_front()-удаляет первый элемент
	void erase_after(iterator iter)-удаляет элемент после итератора
	iterator find(T elem)-ищит элемент в списке

Список состоит из классов elem_list ,в него входят такие методы:
public:
	elem_list(T temp_elem, elem_list *temp_point)
	~elem_list() 
	elem_list* get_point() -выводит содержимое
	void set_point(elem_list * temp_point) -вводит содержимое
Так же в списке есть класс итераторов в который входят:
public:
	iterator(elem_list *temp, elem_list *temp_begin) 
	T operator*() 
	void operator++()
	void operator--()
	bool operator == (iterator it) 
	bool operator != (iterator it) 
	void operator= (T elem) -приравнивание значения элементу