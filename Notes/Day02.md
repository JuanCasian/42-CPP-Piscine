# Day02 notes

- [Day02 notes](#day02-notes)
	- [Adhoc Polymorphism](#adhoc-polymorphism)
	- [Operator Overload](#operator-overload)
	- [Canonical form](#canonical-form)

## Adhoc Polymorphism

- a.k.a. Function overload
- In C++ you can have many functions with the same name but accepting diferent parameters
- It works on any function: class methods, member non member functions, normal functions etc.
- You call them like normal functions

```
**main.cpp**

void	sample(char c) const {
	std::cout << "Printing char: " << c << std::endl;
}

void	sample(int i) const {
	std::cout << "Printing  int: " << i << std::endl;
}

void	sample(int i, char c) {
	std::cout << "Printing  int: " << i << "and char: " << c << std::endl;
}

int main(void) {
	sample('a');
	sample(43);
	sample(43, 'a');
	return 0;
}
```

---

## Operator Overload

- In cpp you can extend cpp operators adding semantics and syntax to the language
- Vocabulary:
  - Infix notation:
    - When the operator is in between the two operands
    - Ex: `1 + 1`
  - Prefix notation (a.k.a. functional notation):
    - When the operator is before the operands
    - Ex: `+ 1 1` which looks similar to `+(1, 1)` and `1.+(1)`
  - Post fix notation
    - Operands in front the operator
    - Ex: `1 1 +`
```
**Integer.hpp**

class Integer {
public:
	Integer(int const n);
	~Integer(void);

	int		getValue(void) const;

// Assignment operator overload
	Integer		&operator=(Integer const &rhs);
	Integer		operator+(Integer const &rhs) const;
// rhs is for right hand side ; lhs is hidden and passed as this
private:
	int _n;
};

std::ostream	&operator<<(std::ostream &o, Integer const & rhs);
```
```
***Integer.cpp**

...
Integer		&Integer::operator=(Integer const &rhs) {
	this->_n = rhs.getValue();
	return *this;
}

Integer		Integer::operator+(Integer const &rhs) const {
	return Integer(this->_n + rhs.getValue());
}
// Notice that  here we return a new instance of the integer
```
- Notation works like `ReturnType	operator+(parameter);`
- The operator between `operator` keyword and `()` can be any operator: binary, unary, etc.
- The number of parameters depend on the type of operator.
  - On the `=` sign we have the variable we want ot assign to the left and the asigned value to the right.
  - On the `+` we have the first number left and the second one to the right.
  - Both are binary operators (operand to left and right)
- Remember that in cpp you always have a unseen argument which is `this`, so on the example above you are actually getting both numbers
  - If it was a unary operator you wouldn't have any parameters in the function declaration but you would have `this`
- Side note: preincrementation and postincrementation have a dummy integer to diferentiate them
  - Preincrement would be `Integer  &operator++(void);`
  - Post would bet `Integer &operator++(int);`
  - Same would be for `--`
- Usually you return the reference to the object so that multiple operators can be chained together
  - CPP allows lines like `a = b = c = d`

```
std::stream		&operator<<(std::stream &o, Integer const &rhs) {
	o << rhs.getValue();
	return o;
}
```
- For input stream and output stram overload what you do is to create a function overload of the stream because you can't really go into the class and change it.
  - So you overload the `<<` operator function by adding a function overload to your COD
- You will recieve the stream and then you can use it however you need to, but always remember to return it so that you can chain the operators.
- **After doing your overloads you only use the operators normally with their new functionality.**
- **WARNINGS**
  - Overload must be natural
  - Overload must be related to the natural semantics
  - Don't really do operator overloads, they are used rarely

---

## Canonical form

- Is a good practice/norm for classes
- a.k.a. coplian form
- There are a certain number of functions available in all of your classes
- It must have:
  - Normal constructor
  - Copy constructor
  - `=` operator overload
  - Destructor
- Basic canonical class Ex:
```
**sample.hpp**
class Sample {
public:
	Sample(void); //Basic constructor
	Sample(Sample const &src); // Copy constructor
	~Sample(void); // Basic destructor

	Sample	&operator=(Samnple const &rhs); // asignment overload
}
```

