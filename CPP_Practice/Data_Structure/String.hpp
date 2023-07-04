#pragma once
#include <iostream>
using namespace std;

namespace KK
{
	class KString
	{
	private:
		char* str;
		size_t Klength;

	public:
		KString();
		KString(const char* ctr);
		KString(const KString& ctr);
		KString(KString&& ctr) noexcept;
		KString& operator=(const KString& ctr);
		KString& operator=(KString&& ctr) noexcept; 
		KString operator+(const KString& ctr);
		KString& operator+=(const KString& ctr);

		friend ostream& operator<<(ostream & os, const KString & ctr);
		friend istream& operator>>(istream& is, KString& ctr);
		// char* operator*();
		char& operator[](int idx);
		bool operator==(const KString& ctr);
		bool operator!=(const KString& ctr);

		bool operator<(const KString& ctr);
		bool operator>(const KString& ctr);

		char& at(int idx);
		char front() const;
		char back() const;
		size_t length() const;
		size_t size() const;
		//void resize(int size) const;
		bool empty() const;
		
		// 수정
		void replace(int n, int k, KString&& ctr);
		// 삭제
		void erase(int n, int m);
		void clear();
	};
}