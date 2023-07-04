#include "KString.hpp"
#include <cstring>
using namespace KK;

KK::KString::KString()
	:str(nullptr), Klength(0)
{
}

KK::KString::KString(const char* ctr)
	:str(nullptr)
{
	if (str != nullptr)delete[] str;
	Klength = strlen(ctr);
	str = new char[Klength + 1];
	strcpy_s(str, Klength + 1, ctr);
}

KK::KString::KString(const KString& ctr)
{
	if (this != &ctr)
	{
		if (str != nullptr)delete[] str;
		Klength = strlen(ctr.str);
		str = new char[Klength + 1];
		strcpy_s(str, Klength + 1, ctr.str);
	}
}

KK::KString::KString(KString&& ctr) noexcept
{
	if (str != nullptr)delete[] str;
	swap(str, ctr.str);
	Klength = strlen(str);
}

KString& KK::KString::operator=(const KString& ctr)
{
	if (this != &ctr)
	{
		if (str != nullptr)delete[] str;
		Klength = strlen(ctr.str);
		str = new char[Klength + 1];
		strcpy_s(str, Klength + 1, ctr.str);
	}
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

KString& KK::KString::operator=(KString&& ctr) noexcept
{
	if (str != nullptr)delete[] str;
	swap(str, ctr.str);
	Klength = strlen(str);
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

KString KK::KString::operator+(const KString& ctr)
{
	char* newchar = new char[Klength + ctr.Klength + 1];
	strcpy_s(newchar, Klength, str);
	strncat_s(newchar, sizeof(newchar), ctr.str, sizeof(ctr.str));
	return KString(newchar);
}

KString& KK::KString::operator+=(const KString& ctr)
{
	char* newchar = new char[Klength + ctr.Klength + 2];
	strcpy_s(newchar, strlen(newchar)+1, str);
	strcat_s(newchar, strlen(newchar) + strlen(ctr.str) + 1,ctr.str);
	if (str != nullptr)delete str;
	str = newchar;
	Klength = strlen(newchar);
	// TODO: 여기에 return 문을 삽입합니다.
	return *this;
}

//
//char* KK::KString::operator*()
//{
//	return str;
//	// TODO: 여기에 return 문을 삽입합니다.
//}

char& KK::KString::operator[](int idx)
{
	return str[idx];
}

bool KK::KString::operator==(const KString& ctr)
{
	if (Klength == ctr.Klength)
	{
		if (strcmp(str, ctr.str) == 0)return true;
	}
	return false;
}

bool KK::KString::operator!=(const KString& ctr)
{
	return !(*this == ctr);
	return false;
}

bool KK::KString::operator<(const KString& ctr)
{
	if (Klength != ctr.Klength)
	{
		return Klength < ctr.Klength;
	}
	return (strcmp(str, ctr.str) < 0)?true:false;
}

bool KK::KString::operator>(const KString& ctr)
{
	if (Klength != ctr.Klength)
	{
		return Klength > ctr.Klength;
	}
	return (strcmp(str, ctr.str) < 0) ? false : true;
}

char& KK::KString::at(int idx)
{
	if (idx >= 0 && idx <= Klength)return *(str + idx);
}

char KK::KString::front() const
{
	if (str != nullptr)
		return str[0];
	return NULL;
}

ostream& KK::operator<<(ostream& os, const KString& ctr)
{
	os << ctr.str;
	return os;
	// TODO: 여기에 return 문을 삽입합니다.
}

istream& KK::operator>>(istream& is, KString& ctr)
{
	char temp[USHRT_MAX];
	cin >> temp;
	ctr = KString(temp);
	return is;
	// TODO: 여기에 return 문을 삽입합니다.
}

char KK::KString::back() const
{
	if (str != nullptr)
		return str[Klength];
	return NULL;
}

size_t KK::KString::length() const
{
	return Klength;
}

size_t KK::KString::size() const
{
	return Klength;
}

bool KK::KString::empty() const
{
	if (Klength == 0)return true;
	return false;
}

void KK::KString::replace(int n, int k, KString&& ctr)
{
	if (n >= 0 && n + k <= Klength)
	{
		for (int i = n; i < n + k; ++i)str[i] = ctr.str[i];
	}
}

void KK::KString::erase(int n, int m)
{
	size_t size = Klength - (m - n);
	if (size < Klength && Klength != 0)
	{
		int k = 0;
		char* newStr = new char[size+1];
		for (int i = 0; i < n; ++i)newStr[k++] = str[i];
		for (int j = m; j <= Klength; ++j)newStr[k++] = str[j];
		delete[] str;
		str = newStr;
		Klength = strlen(str);
	}
}

void KK::KString::clear()
{
	if (str != nullptr)delete[] str;
	str = nullptr;
	Klength = 0;
}
