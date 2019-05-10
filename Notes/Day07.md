# Notes Day07 

- [Notes Day07](#notes-day07)
	- [Introduction](#introduction)
	- [C Parametric macros](#c-parametric-macros)
		- [Limits with macros](#limits-with-macros)
		- [Chained list problem](#chained-list-problem)
	- [Templates](#templates)
	- [Template Default type](#template-default-type)
	- [Template specialization](#template-specialization)
		- [Partial Specialization](#partial-specialization)
		- [Complete Specialization](#complete-specialization)

## Introduction

- Templates is a special syntax of c++ that allows to write patreons
- You make the compiler code for you
- You'll need to learn a new syntax
- When using templates a simple mistake will make thousands of errors to appear but you might only be missing a `;`

## C Parametric macros

### Limits with macros

- The problem that appeared in c was that simple functions that are the same for many data types would need to be declared once per data type

```
int max_int (int x, int y) {return y >= x ? y : x};
int max_float (float x, float y) {return y >= x ? y : x};
...
```

- This could be solved with parametric macros

```
# define max(x, y) (((x)>=(y)) ? (x) : (y))
```

- This is a good solution most of the time but sometimes this could be a bad thing because whatever you send will be done in both part when they recieve it, when you do the comparison and when you return it.

```
Foo(int x) {//long computaition return x;}

int main(void) {
	max(Foo(3) , Foo(4));
}
```

- In the example above the Foo funciton would be call 3 times, one for each varibale in the comparison and then call again when they return it.

- Macros are limited

### Chained list problem

- When you want to do a link list you need to do a node for every data type you want to use. 

```
struct int_list_s {int n; struct int_list_s *next;};
struct float_list_s {float n; struct float_list_s *next;};

// Then the functions to manipulate each of this list
```

- The common solution would be to do a `void*` list.
- But the problem is that everytime you want to access the context you'll need to unreference the data everytime
- This makes it really slow
- The only advantage is that you have only one list
- Another problem is that you always need to cast the information
- This is more generic but more demanding on runtime

Both of this problems are solved with templates which allow you to leave a hole in the type which you will fill

---

## Templates

- Do not need to be compiled
- Is a syntax that allows you to define cod in which you'll introduce type variables
- This allow you to define class, function and structure templates
- Then the compiler will define which type you want and fill it up for you

```
#include <iostream>

// Reference normal function
int max(int x, int y) {
	return x >= y ? x : y;
}

// but we want a max function that works with any type

// template
template<typename T>
T const	&max(T const &x, T const &y) {
	return x >= y ? x : y;
}
```
- T represents a global type (c++ will allow it)
- You need to anounce that you are using a template
- Then you are defining which varible you'll use
  - it can be whatever you want
- This new max template can accept any type of variable
- You'll always need to use `template<type varibales>` and then write the function
  - You can have more than 1 type
- This template can recieve any type, even a class, structure etc.
- You don't really need to use const

```
int foo(int x) { return x;}

// How to use it
int main(void) {
	int a = 23;
	int b = 12;

	max<int>(a, b);
	max(a, b); // Since both variables are ints the compiler is smart enough to instantiate implicitly
	max(foo(a), foo(b));
}
```
- In order to use the max template you need to instantiate it explicitly or implicitly
   - Explict: `max<int>(34, 54);`
      - You just add the type of variable in `<>`
   - Implicit: `max(15, 24)`
- when sending the foo function it will not have the same problem of the parametrized functions
  - It will only run the function once per each parameter

```
template<typename T>
class List {
	public:
	List<T>(T const & content) {
		...
	}
	List<T>(List<T> const & list) {
		...
	}
	~List<T>(void) {
		...
	}
	private:
	T *_content;
	List<T> *_next;
}
```
- Here we solve the second problem of having to write diferent lists for each type of variables
- This is how you wrte a list class template

```
int main(void) {
	List<int>	a(42);
	List<float>	b(3.14f);
	List<List<int>> c(a); // List of lists of intergers
}
```

- This is how you instantiate the class template
- STL = standard template library -> going to learn tomorrow

---

## Template Default type

- you tell the template that if you are not telling it which type it is, assume that it is the one you added as default
  - You do so by adding an = sing. Ex: 	`template<typename T = float>`

```
template<typename T = float>
Class Vertex {
public:
	Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}
	~Vertec(void) {}

	T const &getX(void) const {return this->_x;}
	T const &getY(void) const {return this->_y;}
	T const &getZ(void) const {return this->_z;}

	...
private:
	T const _x;
	T const _y;
	T const _z;

	Vertex(void);
};

template<typename T>
std::ostream &operator<<(std::ostream &o, Vertex<T> const &v) {
	std::cout.precision(1);
	o << v.getX() << std::endl;
	o << v.getY() << std::endl;
	o << v.getZ() << std::endl;
}

int main(void) {
	Vextex<int> v1(12, 23, 34); // Normal instantiation
	Vertex<>	v2(12, 23, 34); // With the  <> you use the default type which is float in this case
}

```
- Default type lets you let the varible unwritten in the instantiation and it will use the one you set as default
  - in this case float
- Template files can have `.tpp` extension

---

## Template specialization

- Using a slighty diferent behavior depending on the type of varible
- You can specialize your templace partially or completely

```
// Generic template
template<typename T, typename U>
class Pair {
public:
	Pair<T, U>(T const &lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) {
		std::cout << "Generic template" << std::endl;
		return ;
	}

	~Pair<T, U>(void) {}

	T const &fst(void) const {return this->_lhs;}
	U const &snd(void) const {return this->_rhs;}

private:
	T const &_lhs;
	U const &_rhs;

	Pair<T, U>(void);
}

template<typename T, typename U>
std::ostream	&operator<<(std::ostream &o, Pair<T, U> const &p) {
	...
	return o;
}
```
### Partial Specialization

```
// Partial specialization where the fist part is always int
template<typename U>
class Pair<int, U> {
	public<int, U>(int lhs, U const &rhs) : _lhs(lhs), _rhs(rhs) { 
		std::cout << "Int partial specialization" << std::endl;
		return ;
	}
	~Pair<T, U>(void) {}

	int		fst(void) const {return this->_lhs;}
	U const &snd(void) const {return this->_rhs;}

private:
	int		_lhs;
	U const &_rhs;

	Pair<T, U>(void);
}
```

- When you pass a generic variable at least and other defined type variable
- In a specialization you need to put which types you are using after the definition of the class
  - `class Pair<int, U>`
- You will use int instead of T on the specialization
- You can see that this specialization does not have the operator overload, so the generic one would be used instead

### Complete Specialization
- On a complete specialization you'll define both varibles.
- Complete specialization tells the compiler to always use the generic except when the variables are of the type defined

```
template<>
class Pair<bool, bool> {
	Pair<bool, bool>(bool lhs, bool rhs) {
		...
	}
	~Pair<bool, bool>(void) {}

	...
}

std::ostream	&operator<<(std::ostream &o, Pair<bool, bool> const &p) {
	...
	return o;
}
```

- This is an example of the same class but used only with 2 bools
- Here you can see that we use `template<>` which does not have any variable inside because both types are specialized

Code for main that uses all the previous classes:
```
int main(void) {
	Pair<int, int>				p1(4, 2);	// It will use the partial specialized
	Pair<std::string, float>	p2("Pi", 3.14f); // Will use the generic template
	Pair<float, bool>			p3(4.2f, true);	// Generic
	Pair<bool, bool>			p4(true, false); // Complete specialization of bool and bool
}
```

- With templates you can write everything
- It unlocks the real power of C++
- You can use typedef to make your code more readable

