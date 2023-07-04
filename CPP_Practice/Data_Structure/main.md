### 간단한 예제 파일

#### Linkedlist

```

#pragma once
#include "KLinkedlist.hpp"
#include <iostream>
#include "KVector.hpp"
#include "KString.hpp"
using namespace std;

int main()
{
	KK::LL<int> Linkedlist;
	for (int i = 0; i < 3; ++i)
		Linkedlist.add(KK::Node<int>{i * 10});
	
	Linkedlist.showAll();
	// 여기까지 okay
	Linkedlist.edit(0, 50);
	Linkedlist.edit(20, 100);

	cout << "\n==============\n";
	Linkedlist.showAll();

	cout << "\n==============\n";
	Linkedlist.remove(10);
	Linkedlist.remove(50);
	Linkedlist.remove(100);
	Linkedlist.showAll();

	cout << "\n==============\n";
	for (int i = 0; i < 3; ++i)
		Linkedlist.add(KK::Node<int>{100 + i * 10});
	Linkedlist.showAll();
	return 0;

}
```

#### String

```
#pragma once
#include "KLinkedlist.hpp"
#include <iostream>
#include "KVector.hpp"
#include "KString.hpp"
using namespace std;

using namespace KK;

int main()
{
	KString str("Hello World!");
	const char temp[] = "Hello!";
	cout << str; // Hello World!
	str += " Nice to meet you!";
 	cout << str;

	cout << "\n===============\n";
	//KString str2;
	//cin >> str2;
	//for (int i = 0; i<str2.length(); ++i)
	//{
	//	cout << str2[i] << " ";
	//}
	//cout << "\n--------\n";
	//for (int i = 0;i< str2.length(); ++i)
	//{
	//	cout << str2.at(i) << " ";
	//}

	//cout << "\n=============\n";
	//KString str3;
	//if (str3.empty())cout << "str3은 비어있는 문자열\n";
	//str2.clear();
	//if (str2.empty())cout << "str2는 비어있는 문자열\n";

	cout << "\n=============\n";
	KString str4("League of Legend");
	cout << str4 << "\n";
	str4.erase(0, 4);
	cout << str4 << "\n";

	str4.erase(3, 5);
	cout << str4 << "\n";

	str4.replace(0, 3, "I'm");

	cout << str4 << "\n";

	return 0;
}
```


### Vector

```

#pragma once
#include "KLinkedlist.hpp"
#include <iostream>
#include "KVector.hpp"
#include "KString.hpp"
using namespace std;

using namespace KK;
// KVector
int main()
{
	KVector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec.at(i) << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";

	vec.pop_back();
	vec.push_back(40);
	vec.push_back(50);
	cout << "Front : " << vec.front() << ", back : " << vec.back() << "\n";
	cout << "\n-=-=-=-=-=-=\n";

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec.at(i) << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";

	vec.push_back(60);
	vec.push_back(70);
	vec.push_back(80);
	vec.push_back(90);
	cout << "Size : " << vec.Size() << ", Capacity : " << vec.Capacity() << "\n";
	
	vec.shrink_to_fit();
	cout << "After shrink => Size : " << vec.Size() << ", Capacity : " << vec.Capacity() << "\n";

	vec.erase(70);
	vec.erase(50);
	vec.erase(30);

	cout << "\n-=-=-=-=-=-=\n";

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec.at(i) << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";

	vec.insert(4, 100);
	vec.insert(4, 200);
	vec.insert(5, 300);

	cout << "\n-=-=-=-=-=-=\n";

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec.at(i) << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";

	vec.clear();

	cout << "\n-=-=-=-=-=-=\n";

	for (int i = 0; i < vec.Size(); ++i)
	{
		cout << vec.at(i) << " ";
	}
	cout << "\n-=-=-=-=-=-=\n";
	return 0;
}
```