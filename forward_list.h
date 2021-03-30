#pragma once
template <typename T>
class forward_list
{

public:
	forward_list();
	~forward_list();
	class iterator;
	class elem_list;
	iterator begin() { auto temp = point_begin->get_point(); return iterator(temp, point_begin); }
	iterator end() { return iterator(point_end, point_begin); }
	iterator before_begin() { return iterator(point_begin, point_begin); }
	void insert_after(iterator& iter, T elem);
	void push_front(T elem);
	void pop_front();
	void erase_after(iterator iter);
	iterator find(T elem);
private:
	elem_list * point_begin;
	elem_list * point_end;
	size_t size;

};

template<typename T>
forward_list<T>::forward_list()
{
	point_end = new elem_list(0, nullptr);

	point_begin = new elem_list(0, point_end);
	point_end->set_point(point_begin);
	size = 0;

}
template<typename T>
forward_list<T>::~forward_list()
{
	delete point_end;
	delete point_begin;
	size = 0;
}
template<typename T>
void forward_list<T>::push_front(T elem)
{
	auto temp = point_begin;
	elem_list *p;
	p = new elem_list(elem, temp->get_point());
	temp->set_point(p);
	size++;
}
template<typename T>
void forward_list<T>::insert_after(iterator &iter, T elem)
{

	elem_list *temp = new elem_list(elem, (iter.iter)->get_point());
	(iter.iter)->set_point(temp);
	size++;
}
template<typename T>
void forward_list<T>::erase_after(iterator iter)
{
	if ((iter.iter)->get_point() == point_end)
	{
		return;
	}
	auto temp = (iter.iter)->get_point();
	auto temp_pointer = temp->get_point();
	(iter.iter)->set_point(temp_pointer);
	delete temp;
}
template<typename T>
void forward_list<T>::pop_front()
{
	auto beg = point_begin->get_point();
	auto point = beg->get_point();
	point_begin->set_point(point);
	if (begin() != end())
	{
		delete beg;
	}

	size--;
}
template<typename T>
class forward_list<T>::elem_list
{
	
	friend class iterator;
	T elem;
	elem_list *point;
public:
	elem_list(T temp_elem, elem_list *temp_point);
	~elem_list() = default;
	elem_list* get_point() { return point; };
	void set_point(elem_list * temp_point) { point = temp_point; };
};
template<typename T>
class forward_list<T>::iterator
{
public:
	elem_list *iter;
	elem_list  *iter_begin;
public:
	friend class elem_list;
	iterator(elem_list *temp, elem_list *temp_begin) { iter = temp; iter_begin = temp_begin; }
	T operator*() { return iter->elem; };
	void operator++() { auto temp = iter; iter = temp->point; };
	void operator--() { auto it = iter_begin; for (; it->point != iter; it++); iter = it; };
	bool operator == (iterator it) { return it.iter == iter; };
	bool operator != (iterator it) { return (it.iter != iter); };
	void operator= (T elem) { iter.elem = elem; };

};

template<typename T>
forward_list<T>::elem_list::elem_list(T temp_elem, elem_list *temp_point)
{
	elem = temp_elem;
	point = temp_point;
};
template<typename T>
auto forward_list<T>::find(T elem)->iterator
{
	for (auto iter = begin(); iter != end(); ++iter)
	{
		if (*iter == elem)
			return iter;
	}
	return end();
}
