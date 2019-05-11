# Notes Day08

## STL

- Standard template library
- Contains 2 really important things
  - Containers to anything
  - Algorithms to make operations in a collection

### Containers

```
#include <iostream>
#include <map>
#include <vector>
#include <list>

class IOPeration;

int main() {
	std::list<int>						lst1; // templated containers
	std::map<std::string, IOperation*>	map1; // c++ version of the hashtable
	std::vector<int>					v1; // array, in this case an empty array
	std::vector<int>					v2(42, 100); // 

	lst1.push_back(1); // operation in container(collection)
	lst1.push_back(17);
	lst1.push_back(42);

	map1["opA"] = new OperationA;
	map1["opB"] = new OperationB;

	std::list<int>::const_iterator it; // iterators are like the pointers of containers
	std::list<ind>::const_iterator	ite = lst.end(); // lsdt.end() would be like the \0 of the list

	for (it = lst1.begin(); it = ite; ++it) { // Here you can see that we handle the iterator result as a pointer
		std::cout << *it << std::endl;
	}

	return (0);
}
```

- In maps you can use any type of key you want
- There is a lot of container clases and each class has iterators
- there are a lot of algorithms saved in the STL
  - Like the `foreach()`

---

## Typename keyword

- This keyword is used inside templates to specify a variable that can be any other when instantiated
- But `typename` can also be written for dependant variables

Ex: 

```
template<typename T>
typename T::iterator easyfind(T &cont, int n) {
	return (std::find(cont.begin(), cont.end(), n));
}
```

- In the example above the `typename` keyword is used to tell the template which variables you are going to use
  - And then a second time inside the template to tell the compiler that that unknown variable is going to be anything that `T` is + `::iterator`
    - In other words ::iterator is dependant to T
- In a template declaration, typename can be used as an alternative to class to declare type template parameters and template template parameters (since C++17).
- Inside a declaration or a definition of a template, typename can be used to declare that a dependent qualified name is a type.
- Inside a declaration or a definition of a template, (until C++11) typename can be used before a non-dependent qualified type name. It has no effect in this case.
- Inside a requirements for type requirements (since C++20)