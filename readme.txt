��������� ��������� ��� ������ ������������ ������.��������� ������� �� ���� ������ ����. � forward_list.h 
��������� ���������� ������ ,� � Source.cpp ������������ ������� ������.
� ������ ������ ������ ����� ������:
public:
	forward_list()
	~forward_list()
	iterator begin() - ���������� �������� �� ������ �������
	iterator end() -���������� �������� �� ������� ����� ����������
	iterator before_begin() -���������� �������� ����� ������
	void insert_after(iterator& iter, T elem)-��������� ������� ����� ���������
	void push_front(T elem)-��������� ������
	void pop_front()-������� ������ �������
	void erase_after(iterator iter)-������� ������� ����� ���������
	iterator find(T elem)-���� ������� � ������

������ ������� �� ������� elem_list ,� ���� ������ ����� ������:
public:
	elem_list(T temp_elem, elem_list *temp_point)
	~elem_list() 
	elem_list* get_point() -������� ����������
	void set_point(elem_list * temp_point) -������ ����������
��� �� � ������ ���� ����� ���������� � ������� ������:
public:
	iterator(elem_list *temp, elem_list *temp_begin) 
	T operator*() 
	void operator++()
	void operator--()
	bool operator == (iterator it) 
	bool operator != (iterator it) 
	void operator= (T elem) -������������� �������� ��������