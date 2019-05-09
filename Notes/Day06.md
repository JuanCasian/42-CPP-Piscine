# Day 06 Notes

- [Day 06 Notes](#day-06-notes)
	- [C type conversion casts](#c-type-conversion-casts)
	- [C Type reinterpretation](#c-type-reinterpretation)
	- [C type qualifier reinterpretation](#c-type-qualifier-reinterpretation)
	- [C++ Upcast and Downcast](#c-upcast-and-downcast)
	- [C++ Static Cast](#c-static-cast)
	- [C++ Dynamic Casts](#c-dynamic-casts)
	- [C++ Reinterpret cast](#c-reinterpret-cast)
	- [C++ Const cast](#c-const-cast)
	- [C++ Type Cast Operators](#c-type-cast-operators)
	- [Explicit keyword](#explicit-keyword)
	- [Conclusion](#conclusion)
		- [Information table](#information-table)

## C type conversion casts

```
int a = 42;

double b = a; // implicit cast
double c = (double)a; // explicit cast

double d = a; // implicit promotion -> Ok
int e = d; // implicit demotion => dangerous
int f = (int)d; // explecit dmotion -> Ok because you are in charge
```

- When you cast you can do
  - promotion: when a lower precision/smaller variable is converted into a biger one. Ex: `int -> double`
  - Demotion: The other way around. Ex: `double -> int`
    - Looses accurary

- There are:
  - implicit casts: when you don't put the cast
    - Are dangerous because you are not noticing the information loss in demotions!
  - explicit: when you actually write the cast
  - See above for examples

- When doing a small calculation loosing accuracy is not that relevant but when doing multiple calculations the error can grow a lot.
  - You can look for a flag which prevents compilation if there are implicit casts which demote

---

## C Type reinterpretation

- Another type of conversion is when you have an identity cast
  - The base value keeps the same numbr of bits in the same order so there is no conversion
  - It is called reinterpretation
- In here the hiearchy is on which type is more general. for example a float pointer is less general than a void pointer

```
float a = 420.042f; // Reference value

void *b = &a; // implicit reinterpretation cast
void *c = (void*) &a; // explicit reinterpretation cast -> lost in accurary but win in generality

void *d = &a; // implicit promotion -> Ok
int *e = d; // Implicit demotion -> Hazardous
int *f = (int*) d; // Explicit demotion -> Ok becuase you are in charge
```

- Explicit casts demonstrates that the cast was not a mistake
- Never use implicit syntax on demotion reinterpretation.

---

## C type qualifier reinterpretation

- type qualifiers are keywords like `const` 
- Casting into  diferent qualifier
  - Ex: `int -> const int`
- It is not advice to do a type qualifier cast, because it means that the code is not well defined
  - This can happen if you are using a library which should be a constant but you can't change it so you do the cast to solve it.
```
int a = 42;

int const *b = &a;	// Implicit type qualifier cast
int const *c = (int const *) &a; // Explicit type qualifier cast

int const *d = &a; // Implicir promotion -> OK
int *e = d; // Implicit demotions -> NOT OK, won't compile becuase 
			//this would mean you have write access to a read only address
int *f = (int*) d; // Implicit demotion -> OK because you are in charge -> It WILL compile
```

---

## C++ Upcast and Downcast

- In this section we are using the C type casting to learn the notions in c++, on the next video we'll see the syntax in c++
- In c++ there is a new hierchy because of the classes
  - The parent classes are more generic
  - Child classes are more accurate one
- Upcast will be going from a child pointer to a parent pointer
- Downcast is the other way around

```
class Parent {};
class Child1 : public Parent {}
class Child2 : public Parent {}


int main(void) {
	Child1 a; // Reference value

	Parent *b = &a; // Implicit reinterpretation cast
	Parent *c = (Parent*) &a; // Explicit reinterpretation cast

	Parent *d = &a; // implicit upcast -> OK
	Child1 * e = d; // Implicit downcast -> NOT OK
	Child2  *f = (Child2 *) d; // Explicit downcast -> OK but really?
}
```

- The explicit downcast of the d to child 2 does not have compilation issues, but it may have runtime errors becuase the classes might not have the same attributes or functions

---

## C++ Static Cast

- There are 5 posible casts:
  - Conversion
  - Reinterpretation
  - Type qualifier changes
  - Downcast
  - Upcast

- The static cast allows to make the simplest conversions and upcast and downcast

```
int main(void) {
	int a = 42;

	double b = a;	// implicit promotion -> ok
	int c = b; // implicit demotion -> not okay
	int d = static_cast<int>(b); // Explicit demotion -> ok, I obey

	return (0);
}
```

- this is like the c++ cast `(int)b;`
  - From now own this is how you should cast it

```
class Parent {};
class Child1 : public Parent {}
class Child2 : public Parent {}

class Unrelated {};

int main(void) {
	Child1 a;

	Parent *b = &a; // Implicit upcast -> OK
	Child1 *c = b // Implicit downcast -> NOT OKAY
	Child2 *d = static_cast<Child2 *>(b); // Explicit downcast -> OK, but not the best
	
	Unrelated *e = static_cast<Unrelated *>(a&); // Explicit conversion -> NOT COOL, won't compile
	return (0);
}
```

- Static cast ensures that casts can only be done between classes in the same hierchical tree
  - Child classes are in the same tree but Unrelated is horizontal to the parent class, so the cast is imposible
  - static cast protects us and will stop the compilation 

---

## C++ Dynamic Casts

- This cast is very special
  - It is the only one that happens in the runtime
  - All the other are done during compilation
- Program may compile and then dynamic cast will fail in runtime
  - This means you need create an architecture that can handle the cast failing
- This only work with polymorphic instances
  - classes with virtual
  - when having subtyping polymophism (`virtual`) it activates a RTTI (Run time type info)
    - which stores information about your class to check if the dynamic class is posible
- The dynamic casts can only be used for downcasts

```
class Parent {public: virtual ~Parent(void) {}};
class Child1 : public Parent {}
class Child2 : public Parent {}


int main(void) {
	Child a;		//Reference
	Parent *b = &a; // Implicit upcast -> OK

	// Explicit donwcast using a pointer -> suspense -> This would be okay
	Child1 * c = dynamic_cast<Child1 *>(b);
	if (c == NULL) {
		std::cout << "Conversion is not okay" << std::endl;
	} else {
		std::cout << "Conversion is okay" << std::endl;
	}

	// Explicit downcast using a reference -> suspense
	try {
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is okay" << std::endl;
	} catch (std::bad_cast &bc) { //bc = bad cast
		std::cout << "Conversion is not OK: " << bc.what() << std::endl;
		return (0);
	}
	return (0);
}
```

- When using dynamic casts with pointers you will be returned with an address
  - if the pointer is null then the cast failed
- When working with a reference you need to unreference the pointer
  - It will throw an error, since the references can't point to null
- Dynamic casts are really useful to know which type of class are you recieving because it will fail with all of them unless it is a useful one.
  - This is useful when working with plugins/other libraries. You might do a universal plugin class which can be used for any plugin, but if then you need to specify which type of plugin you are using you will use a dynamic cast to try to convert it. If the class you think it was is not correct then the dynamic class will tell you which is the type
- Remember that this cast need to be with classes with RTTI, so they must be classes with subtyping polymorphism, in other words at least a virtual member.

---

## C++ Reinterpret cast

- This cast will allow reinterpretation, upcast & downcast
- It allows to reinterpret any address as any other

```
int main(void) {
	float a = 420.042f;

	void *b = &a; // Implicit promotion ->OK
	int *c = reinterpret_cast<int*>(b) // Explicit demotion -> OK I obey
	int &d = reinterpret_cast<int&>(b); // Explicit demotion -> OK, I obey

	return (0);
}
```

- When doing reinterpret cast, the compiler will never prevent compilation, but you need to be sure of the consecuences of your reinterpretation
- It is really useful when using data obtained by a comunication, like internet. You recieve a string of bytes which you can then reinterpret as whatever is needed to understand it
- It may cause runtime errors if you are not careful with what you're casting

---

## C++ Const cast

- Used to make a transformation of the type qualifiers
- Doing const casts are still wrong as in C

```
int main(void) {
	int a = 42;

	int const *b = &a; // Implicit promotion -> OK
	int  *c = b; // Implicit demotion -> NOT OK, compiler won't allow it
	int *d = const_cast<int*>(b); // Explicit demotion -> OK, I obey

	return (0);
}
```

---

## C++ Type Cast Operators

- Used inside class to define implicit casts for your class

```
class Foo {
	public:
		Foo(float const v) : _v(v) {}
		float getV(void) { return this->_v; }

		// Implicit cast operators
		operator float() {return this->_v;}
		operator int() {return static_cast<int>(this->_v);}
		// Here we are definning implicit casts from foo to int and float
};

int main(void) {
	Foo a(42.042f);

// Both are posible because we defined the implicit cast
	float b = a;
	int c = a;
}
```
- Syntax: `operator typeOfVar() {logic}`
- Improves expresivity of your classes

--- 

## Explicit keyword

- Constructors are conceptually close to the casts
  - You send data and you are return a diferent type of data
  - Casts are the other way around

```
class A {};
class B {};

class C {
	public:
		C(A const & _) {return; } // takes reference to A class
		explicit C(B const & _) {return ;} // takes reference to B class

// what matters is that you can use other class to get a C class
};

void f(C const & _) {
	return ;
}

int main(void) {
	f(A()); // Passing an A class instance -> OK
	f(B()); // Passsing a B class instance -> Not OK because constructor is explicit

	return (0);
}
```

- When calling the C function you can use it with an A class becasue the A class will be converted into a C class implicitly and the used
- When using the B class this is not posible because the the `explicit` keyword doesn't allow to do the implicit construction of an instance
  - To make it work you would need to create the C instance from B first and then pass it to the function

---

## Conclusion

- Conversion allows to convert a type into another
- Identity conversion is when the bits order is not changed (reinterpretations)
- Upcast & downcast are when you use the cast between classes

### Information table

| Casts                     | Conversion | Reinterpretation | Upcast | Downcast | Type Qualifier Cast |
| ------------------------- | ---------- | ---------------- | ------ | -------- | ------------------- |
| **Implicit**              | Yes        |                  | Yes    |          |                     |
| **static_cast**           | Yes        |                  | Yes    | Yes      |                     |
| **dynamic_cast**          |            |                  | Yes    | Yes      |                     |
| **const_cast**            |            |                  |        |          | Yes                 |
| **reinterpretation_cast** |            | Yes              | Yes    | Yes      |                     |
| **Legacy C cast**         | Yes        | Yes              | Yes    | Yes      | Yes                 |

| Cast                      | Semantic ckeck | Reliable at run | Tested at run |
| ------------------------- | -------------- | --------------- | ------------- |
| **Implicit**              | Yes            | Yes             |               |
| **static_cast**           | Yes            |                 |               |
| **dynamic_cast**          | Yes            | Yes             | Yes           |
| **const_cast**            |                |                 |               |
| **reinterpretation_cast** |                |                 |               |
| **Legacy C cast**         |                |                 |               |