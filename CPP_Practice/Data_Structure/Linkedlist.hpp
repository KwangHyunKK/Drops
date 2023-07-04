#pragma once
#include <iostream>
using namespace std;

// 모든 프로젝트에 KK namespace 생성
namespace KK
{
	// Template 활용한 구조
	template<typename T>
	class Node
	{
	private:
		T data;
		Node* prev;
		Node* next;
	public:
		Node(T d=-1, Node* p=nullptr, Node* n=nullptr) :data(d), prev(p), next(n) {} // 기본 생성자 역할을 한다.
		~Node() = default; 
		Node(const Node& n); // 복사 생성자
		Node(Node&& n) noexcept; // 이동 생성자
		Node& operator=(const Node& n); // 대입 연산자
		Node& operator=(Node&& n) noexcept; // 이동 대입 연산자

		// private 변수를 얻기 위한 getter/setter
		Node* getPrev() const { return prev; } 
		Node* getNext() const { return next; }
		void setPrev(Node* n) { prev = n; }
		void setNext(Node*  n) { next = n; }

		T getValue() const { return data; }
		T setValue(T value) { return data = value; }
	};
	template<typename T>
	inline Node<T>::Node(const Node& n)
	{
		if (this != &n)
		{
			data = n.data;
			prev = n.prev;
			next = n.next;
		}
	}
	template<typename T>
	inline Node<T>::Node(Node&& n) noexcept
	{
		data = n.data;
		swap(prev, n.prev);
		swap(next, n.next);
	}
	template<typename T>
	inline Node<T>& Node<T>::operator=(const Node<T>& n)
	{
		if (this != &n)
		{
			data = n.data;
			prev = n.prev;
			next = n.next;
		}
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline Node<T>& Node<T>::operator=(Node<T>&& n) noexcept
	{
		data = n.data;
		swap(prev, n.prev);
		swap(next, n.next);
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	

	// Linkedlist
	// 환형 링크드리스트는 아님
	template<typename T>
	class LL
	{
	private:
		Node<T>* header; // Node list
		size_t size; // size
	public:
		LL();
		LL(const LL& l);
		~LL();
		LL(LL&& l);
		LL& operator=(const LL& l);
		LL& operator=(LL&& l);

		// 추가
		bool add(Node<T>&& node);
		// 수정
		bool edit(T origin, T change);
		// 찾기
		Node<T>* find(T value);
		// 삭제
		bool remove(T value);
		// 읽기
		void showAll();
	};

	template<typename T>
	inline LL<T>::LL()
		:size(0)
	{
		header = nullptr;
	}
	template<typename T>
	inline LL<T>::LL(const LL& l)
	{
		if (this != &l)
		{
			header = l.header;
			size = l.size;
		}
	}
	template<typename T>
	inline LL<T>::~LL()
	{
		Node<T>* it = header;

		if (header != nullptr)
		{
			for (int i = 0; i < size; ++i)
			{
				Node<T>* delit = it;
				it = it->getNext();
				delete delit;
			}
		}
		size = 0;
	}
	template<typename T>
	inline LL<T>::LL(LL&& l)
	{
		swap(header, l.header);
		size = l.size;
	}
	template<typename T>
	inline LL<T>& LL<T>::operator=(const LL<T>& l)
	{
		if (this != &l)
		{
			header = l.header;
			size = l.size;
		}
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline LL<T>& LL<T>::operator=(LL<T>&& l)
	{
		swap(header, l.header);
		size = l.size;
		return *this;
		// TODO: 여기에 return 문을 삽입합니다.
	}
	template<typename T>
	inline bool LL<T>::add(Node<T>&& node)
	// add : 
	// size : 0 => header를 새로 생성하고 size + 1
	// size > 0 => next에 추가
	{
		if (header != nullptr)
		{
			Node<T>* it = header;
			while (it->getNext() != nullptr)it = it->getNext();
			Node<T>* newNode = new Node<T>{ std::move(node) };
			it->setNext(newNode);
			it->getNext()->setPrev(it);
			++size;
			return true;
		}
		else
		{
			Node<T>* newNode = new Node<T>{ std::move(node) };
			header = newNode;
			++size;
			return true;
		}
		return false;
	}
	template<typename T>
	inline bool LL<T>::edit(T origin, T change)
		// origin 값이 들어오면 change로 변형
	{

		Node<T>* it = find(origin);
		if (it != nullptr)
		{
			it->setValue(change);
			return true;
		}
		return false;
	}
	template<typename T>
	inline Node<T>* LL<T>::find(T value)
		// value 값에 해당하는 값을 찾는다.
	{
		if (size == 0)return nullptr;
		Node<T>* it = header;
		while (it != nullptr)
		{
			if (it->getValue() == value)return it;
			it = it->getNext();
		}
		return nullptr;
	}
	template<typename T>
	inline bool LL<T>::remove(T value)
	// 1. 지우는 값이 header인 경우 => 
	// 2. 그렇지 않은 경우
	{
		if (size == 0)return false;
		Node<T>* it = find(value);

		if (it != nullptr)
		{
			if (it == header) // header 인 경우
				header = it->getNext();
			else
			{
				it->getPrev()->setNext(it->getNext());
				if (it->getNext() != nullptr)
				{
					it->getNext()->setPrev(it->getPrev());
				}
			}

			--size;
			delete it;
		}
		return false;
	}
	template<typename T>
	inline void LL<T>::showAll()
		// 모두 보여주도록
	{
		Node<T>* it = header;
		for (int i = 0; i < size; ++i)
		{
			cout << it->getValue() << "\t";
			it = it->getNext();
		}
	}
}

