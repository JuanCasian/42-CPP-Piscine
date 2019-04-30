# Day 00 Notes

- [Day 00 Notes](#day-00-notes)
	- [Namespaces](#namespaces)
	- [STDIO Streams](#stdio-streams)
	- [Class and instance](#class-and-instance)
	- [Member attributes and member functions](#member-attributes-and-member-functions)
	- [This](#this)
	- [Initialization list](#initialization-list)
	- [Const](#const)
	- [Visibility](#visibility)
	- [Class vs Struct](#class-vs-struct)
	- [Accerssors C++](#accerssors-c)
	- [Comparison C++](#comparison-c)
	- [Non member attributes and non member functions](#non-member-attributes-and-non-member-functions)
	- [Pointers to members](#pointers-to-members)

## Namespaces

- Used to group together symbols and functions

```
// Definition of namespace
namespace Foo {
	int my_var = 5;

	int my_function(void) {
		return 4;
	}
}

// Aliasing a namespace
// Useful for when you have a lot of namespaces inside each other.
namespace Final = Foo;

int main(void) {
	printf("var: %i\n", Foo::my_var);
	printf("function res: %i\n", Foo::my_function());
}

// var: 5
// function res: 4
```

- You can alias them
- You can put namespaces inside the other
- The `::` is a scope resolution operator
- When using the global scope you can use `variable` or `::variable`, same with functions

---

## STDIO Streams

- C++ has integrated 2 objects
  - `cin` == stdin
  - `cout` == stdout
- This objects include 2 new use for operators
  - `<<` operator to redirect flow to stdout
  - `>>` operator to redirect input to varible

```
#include <iostream>

int main(void) {
	char buff[512];

	// std::endl es el carriage return incluido en std namespace
	std::cout << "Hello World" << std::endl;

	std::cin >> buff;
}
```

---

## Class and instance

- CPP is OOP language
- Header file you only define the class
```
class Sample {
	public:
		// Constructor
		Sample(void);

		// Destructor
		~Sample(void);
};
// Don't forget the semicolon
```
- CPP file is where you actually write the functions
```
#include "Sample.hpp"
#include <iostream>

Sample::Sample(void) {
	std::cout << "Constructor called" << std::endl;
	return ;
	// You add the return to see you finished the function
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}
```
- Constructors and destructors don't have a return type
- Main file
```
int main() {
	// instanciation of the class
	// This same line calls the constructor
	Sample sample_instance;

	return 0;
}
```
- Destructor is run when the scope ends
- We will later see dynamic allocation of memory

---

## Member attributes and member functions

- Member attribute is a variable set in the class, that you can use from the instance
- Member functions is a function set in clas, that can be used from the instance

```
**Sample.hpp**

class Sample {

public:
	int foo;

	Sample(void);
	~Sample(void);

	void bar(void);
};
```
```
**Sample.cpp**

#include "Sample.hpp"
#include <iostream>

Sample::Sample(void) {
	std::cout << "Constructor called" << std::endl;
	return ;
	// You add the return to see you finished the function
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar(void) {
	std::cout << "Bar function called" << std::endl;
	return ;
}
```

- All the member functions have a speacial pointer passed which is `this`
  - it is passed even if they don't take parameters

```
**main.cpp**

#include Sample.hpp

int main(void) {
	Sample sample;

	sample.foo = 42;
	std::cout << sample.foo << std::endl;

	sample.bar();
}

PRINTS:
> Constructor called
> 42
> Bar function called
> Destructor called
```

---

## This

- This is a pointer to the instance
- You can use it on methods

```
**Sample.hpp**

// In order to not write a lot constructors and destructors 
// are not added

class Sample {

public:
	int foo;

	void bar(void);
};
```
```
**Sample.cpp**

void	Sample::bar(void) {
	this->foo = 42;
}
```

- Here when `bar` function is called the value of the instance variable `foo` is going to become `42`

---

## Initialization list

- Solves the problem of constructors taking a lot of parameters
- Instead of assigning each variable by using `this->var_name = something` you use the init list
- init list is used for more complex uses but we'll see that later

```
**Sample.hpp**

class Sample {

public:
	char a1;
	int a2;
	float a3;

	Sample(char a1, int a2, float a3);
	~Sample(void);
};
```
```
**Sample.cpp**

Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) {
	// Notice the varibles will be assigned in the init list
	return ;
}
```
```
**main.cpp**

#include Sample.hpp

int main(void) {
	// Here is how you initialize with parameters
	Sample sample('a', 42, 7.8f);
}
```

---

## Const

- Is a keyword to make a constant
  - Important for long term programs
- Try to work with as many constants as posible
- The initialization in cpp is different because you might want to do it on the constructor.

```
**Sample.hpp**

class Sample {

public:
	float const pi;
	int			qd;

	Sample(float const f);
	~Sample(void);

	void bar(void) const;
};
```
- Constants can be initialized in constructors with init lists
- When you place const in the end of a function `void bar(void) conts;` means that that function won't modify the instance
  - This will prevent the program from compiling which is good for long programs

```
**Sample.cpp**

Sample::Sample(float const f) : pi(f), qd(42) {
	return ;
}

void Sample::bar(void) const {
	...
	// You can't modify things here
	// this->qd = 8; wouldn't work
	return ;
}
...
```
- Here we used init list to initialize the instance constant `pi`

---

## Visibility

- Inside classes there are some keywords that control the encapsulation of the members of the class
- `public` means it is posible to access from **inside the class and outside** of the class
- `private` means it is only posible to access the members **only from the inside** of the class
- You usually name private members with a `_` previous to the name

```
class Sample {

public:
	int		publicFoo;

	Sample(void);
	~Sample(void);
	
	void	publicBar(void) const;

private:

	int		_privateFoo;

	void	_privateBar(void) const;

}
```

- On the cpp file the definition stays the same
- If you try to access a private member from the outside the program won't compile.

---

## Class vs Struct

- The only diference between `struct` and `class` in cpp is that s**tructures have public members** by default and **class have private members** by default
```
**Struct syntax**

struct Sample1 {
	int foo;

	Sample(void);
	~Sample(void);

	void	bar(void) const;
};
```

---

## Accerssors C++

- Getters are functions used to get private attributes
- All atributes of class should be private
- Setters are functions used to set private attributes
- This is a good coding convention and helps you limit the values of your varibles

```
**Sample.hpp***

class Sample {
public:
	...
	int		getFoo(void) const;
	void	setFoo(int val);
private:
	int _foo;
};
```

```
**Sample.cpp**

int Sample::getFoo(void) const {
	return this->_foo;
}

void Sample::setFoo(int val) {
	if (val >= 0)
		this->_foo = val;
}
```

---

## Comparison C++

- In c++ you can use `==` to compare the address as in c
- In C you want to compare the diferent parts of the class/structure
- For this you use a function
- Physical equality is checked by `==` which is the address equality
- Structural equality is that the parts of the class/Structure have the same values

---

## Non member attributes and non member functions

- Variables and functions in class level, not instance level
- You can use them without the class being instantiated
- You use the `static` keyword

```
**Sample.hpp**

class Sample {
public:
	Sample(void);
	...
	static int getNumOfInst(void);
private:
	static int _numInst;
};
```
```
**Sample.cpp**
#include Sample.hh

Sample::Sample(void) {
	Sample::_numInst += 1;
}

int Sample::getNumOfInst(void) {
	// In non member functions you don't get the this keyword
	// You get the non member things like namespaces Sample::
	return Sample::_numInst;
}

// Here we give the value for the static variable (initialize it)
// Only way to initialize a static attribute
int Sample::_nbInst = 0;
```

```
**main.cpp**
#include "Sample.hpp"

int main(void) {
	std::cout << Sample::getNumOfInst() << std::endl;
	return (0);
}
PRINTS:
0
```

- You use namespace notation to get non member attributes and functions `Sample::`

---

## Pointers to members

```
**Sample.hpp**

class Sample {
public:
	int foo;

	Sample(void);
	~Sample(void);

	void bar(void) const;
};
```

```
**main.cpp**
#include "Sample.hpp"

int main(void) {
	Sample instance;
// Normal pointer to class instance
	Sample *instanceP = &instance;

// Pointer to member atribute from class definition
	int Sample::*p = NULL;
// Pointer to member function from class definition
	void (Sample::*f)(void) const;

// asingning the value of foo member from Sample class
	p = &Sample::foo;

// Using the pointer to asign a value to the instance foo variable
	instance.*p = 21;

// Same but with pointer referenced variable
	isntancep->*p = 42;

// Asigning the value of bar member function from sample class
	f = &Sample::bar;

// Running the bar function on the stack instance
	(instance.*f)();

// Same but with pointer
	(instancep->*f)();

	return 0;
}
```

- `p = &Sample::foo;` This is really interesting because it will asign the value of the foo member from any instantiated class. As you see later you can use `instance.*p` or `instancep->*p` to get the value of that instance;
- `.*` is an operator to tell which instance you want to use your pointer on
- `->*` same but with pointers
- Function pointer on member `ReturnType (Class::*pointerName)(parameters) const;`
- Variable pointer on member `VarType Class::*pointerName`

--- 
