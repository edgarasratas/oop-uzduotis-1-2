#pragma once

#define ll long long

template <typename T>
class Vector {
private:
	T* arr;
	ll capacity;
	ll length;
public:
	explicit Vector(ll = 100);

	ll push_back(T);

	T pop_back();

	ll size() const;
	T& operator[](ll);

	class iterator {
	private:
		T* ptr;
	public:
		explicit iterator()
			: ptr(nullptr)
		{
		}
		explicit iterator(T* p)
			:ptr(p)
		{
		}
		bool operator == (const iterator& rhs) const
		{
			return ptr == rhs.ptr;
		}
		bool operator!=(const iterator& rhs) const
		{
			return !(*this == rhs);
		}
		T operator*() const
		{
			return *ptr;
		}
		iterator& operator++()
		{
			++ptr;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp(*this);
			++* this;
			return temp;
		}
	};
	iterator begin() const;
	iterator end() const;
};

template <typename T>
Vector<T>::Vector(ll n)
	: capacity(n), arr(new T[n]), length(0)
{
}

//push_back
template <typename T>
ll Vector<T>::push_back(T data)
{
	if (length == capacity) {
		T* old = arr;
		arr = new T[capacity = capacity * 2];
		std::copy(old, old + length, arr);
		delete[] old;
	}
	arr[length++] = data;
	return length;
}

//pop_back
template <typename T>
T Vector<T>::pop_back()
{
	return arr[length-- - 1];
}

//size()
template <typename T>
ll Vector<T>::size() const
{
	return length;
}

//operators
template <typename T>
T& Vector<T>::operator[](ll index)
{
	if (index >= length) {
		cout << "Error: Array index out of bound";
		exit(0);
	}

	return *(arr + index);
}

//begin()
template <typename T>
typename Vector<T>::iterator
Vector<T>::begin() const
{
	return iterator(arr);
}

//end()
template <typename T>
typename Vector<T>::iterator
Vector<T>::end() const
{
	return iterator(arr + length);
}