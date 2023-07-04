#pragma once
#include <memory>

namespace KK
{
	using namespace std;

	template<typename T>
	class KVector
	{
	private:
		T* arr;
		size_t count;
		size_t array_size;

		void doublesize();

	public:
		KVector();
		KVector(size_t c, T v);
		~KVector();
		KVector(const KVector& vec);
		KVector(KVector&& vec) noexcept;
		KVector& operator=(const KVector& vec);
		KVector& operator=(KVector&& vec) noexcept;

		T at(int idx);
		T& operator[](int idx);

		T& front();
		T& back();

		bool empty();
		size_t Size();
		size_t max_size();
		void resize(int n);
		size_t Capacity();
		void reserve(int n);
		void shrink_to_fit();

		void clear();
		void push_back(T value);
		void pop_back();

		void insert(int idx, T value);
		void erase(T value);

		void swap();

		T& begin();
		T& end();
	};
	template<typename T>
	inline void KVector<T>::doublesize()
	{
		T* newArr = new T[array_size*2];
		for (size_t i = 0; i < count; ++i)newArr[i] = arr[i];
		array_size *= 2;
		delete[] arr;
		arr = newArr;
	}

	template<typename T>
	inline KVector<T>::KVector()
		:arr(nullptr), count(0), array_size(0) {}

	template<typename T>
	inline KVector<T>::KVector(size_t s, T v)
		:count(s), array_size(s * 2)
	{
		arr = new T[array_size];
		for (size_t i = 0; i < count; ++i)arr[i] = v;
	}
	template<typename T>
	inline KVector<T>::~KVector()
	{
		if (arr != nullptr) {
			delete[] arr;
		}
		count = 0;
		array_size = 0;
	}
	template<typename T>
	inline KVector<T>::KVector(const KVector& vec)
	{
		if (this != &vec)
		{
			if (arr != nullptr)delete[] arr;
			arr = new T[vec.array_size];
			array_size = vec.array_size;
			count = vec.count;
			for (size_t i = 0; i < count; ++i)arr[i] = vec.arr[i];
		}
	}
	template<typename T>
	inline KVector<T>::KVector(KVector&& vec) noexcept
	{
		swap(arr, vec.arr);
		array_size = vec.array_size;
		count = vec.count;
	}
	template<typename T>
	inline KVector<T>& KVector<T>::operator=(const KVector& vec)
	{
		if (this != &vec)
		{
			if (arr != nullptr)delete[] arr;
			arr = new T[vec.array_size];
			array_size = vec.array_size;
			count = vec.count;
			for (size_t i = 0; i < count; ++i)arr[i] = vec.arr[i];
		}
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline KVector<T>& KVector<T>::operator=(KVector&& vec) noexcept
	{
		swap(arr, vec.arr);
		array_size = vec.array_size;
		count = vec.count;
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline T KVector<T>::at(int idx)
	{
		try {
			return arr[idx];
		}
		catch (out_of_range e) {
			return -1;
		}
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline T& KVector<T>::operator[](int idx)
	{
		return arr[idx];
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline T& KVector<T>::front()
	{
		return arr[0];
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline T& KVector<T>::back()
	{
		return arr[count - 1];
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline bool KVector<T>::empty()
	{
		if (count == 0)return true;
		return false;
	}
	template<typename T>
	inline size_t KVector<T>::Size()
	{
		return count;
	}
	template<typename T>
	inline size_t KVector<T>::max_size()
	{
		return array_size;
	}
	template<typename T>
	inline void KVector<T>::resize(int n)
	{
		if (n > array_size)
		{
			T* newArr = new T[n];
			memcpy_s(newArr, n, arr, array_size);
			array_size = n;
			delete[] arr;
			arr = newArr;
		}
	}
	template<typename T>
	inline size_t KVector<T>::Capacity()
	{
		return array_size;
	}
	template<typename T>
	inline void KVector<T>::reserve(int n)
	{
		if (arr != nullptr)
		{
			resize(n);
		}
		else
		{
			arr = new T[n];
			array_size = n;
		}
	}
	template<typename T>
	inline void KVector<T>::shrink_to_fit()
	{
		if (count != array_size)
		{
			T* newArr = new T[count];
			for (size_t i = 0; i < count; ++i)newArr[i] = arr[i];
			delete[] arr;
			arr = newArr;
			array_size = count;
		}
	}
	template<typename T>
	inline void KVector<T>::clear()
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
		count = 0;
		array_size = 0;
	}
	template<typename T>
	inline void KVector<T>::push_back(T value)
	{
		if (arr != nullptr)
		{
			if (count + 1 >= array_size)
			{
				doublesize();
			}
			arr[count++] = value;
		}
		else
		{
			count = 0;
			array_size = 10;
			arr = new T[array_size];

			arr[count++] = value;
		}
	}
	template<typename T>
	inline void KVector<T>::pop_back()
	{
		if (count > 0)--count;
	}
	template<typename T>
	inline void KVector<T>::insert(int idx, T value)
	{
		if (arr != nullptr)
		{
			if (count + 1 >= array_size)
			{
				doublesize();
			}
			if (idx != count)
			{
				for (int i = count - 1; i>=idx; --i)
				{
					arr[i + 1] = arr[i];
				}
				++count;
				arr[idx] = value;
			}
			else
			{
				push_back(value);
			}
		}
	}
	template<typename T>
	inline void KVector<T>::erase(T value)
	{
		bool check = true;
		for (int i = 0; i < count; ++i)
		{
			if (arr[i] == value)
			{
				check = false;
			}
			if (!check)
			{
				arr[i] = arr[i + 1];
			}
		}
		--count;
	}
	template<typename T>
	inline void KVector<T>::swap()
	{

	}
	template<typename T>
	inline T& KVector<T>::begin()
	{
		if(count >= 1)return arr[0];
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline T& KVector<T>::end()
	{
		if(count > 0)return arr[count-1];
		// TODO: 여기에 return 문을 삽입합니다.
	}
}