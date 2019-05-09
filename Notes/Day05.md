# Notes Day05

- [Notes Day05](#notes-day05)
	- [Nested Classes](#nested-classes)
	- [Exceptions](#exceptions)

## Nested Classes

- aka Imbricated classes 
- You can define a class inside other class
- Then you would use the main class as a namespace to access the inside class
- It is good because the nested class is considered a member of the outside class, which gives it access to all the private attributes of the outside class
  - But it does not work the other way around: outside class has on acces to the inside classs private attributes
- It is comonly used to hide implementation details, like creating a node class inside a list class
- Good because they don't polute the global scope namespaces

```
class Cat {
	public:
		class Leg {
				...
		};
};

int main(void) {
	Cat			somecat; // instantiating a cat
	Cat::Leg 	somecatLeg; // Instantiating a cat leg
}
```

```
class List
{
    public:
        List(): head(nullptr), tail(nullptr) {}
    private:
        class Node
        {
              public:
                  int   data;
                  Node* next;
                  Node* prev;
        };
    private:
        Node*     head;
        Node*     tail;
};
```

---

## Exceptions

- Is a way of reporting errors with a message though the stack
- Try / catch block
  - on `try` you put the code you want to run which could throw exceptions
  - on `catch` what you would do if you run into an error
- `throw` will go send an error going back to the stack of functions until it finds a catch statement
  - if there is no `catch` then it will end the program in an error

```
void test1() {
	try {
		if (/* Some error condition */) {
			throw std::exception();
		} else {
			// Do somthing
		}
	} catch (std::exception e) {
		// Handle the error
	}
}
```

- You can see the catch as a function which has the error as a parameter. It is not realy a function
- std::exception.what() will give the message for the error
- You can inherit the std::exception to create your own exceptions
- At th end of functions you should add a `throw(exceptions that can be thrown)` which will help you know which exceptions can be thrown by each function.
  - It is a clean way to work
  - If there is no error just do `throw()`
  - Ex: `vitual void test1(void) const throw(NumberException);`
- When handing exceptions thrown by other functions you want to catch them using a reference
  - ex: `catch (std::exception &e)`

```
void test4() {
	// Creating my own exception
	class MyException : public std::exception {
		public:
			// Overriding what() method from std::exception
			virtual const char *what(void) const throw() {
				return "error message";
			}
	};

	try {
		ImaginaryTest();
	} catch (MyException &e) {
		// Handle MyException error specifically
	} catch (std::exception &e) {
		// Handle any other exception
	}
}
```

- You can do specific and generic catch
  - specific catch is when you handle for a specific exception
  - generic catch is when you handle any exception
- **You should use them in exceptions!** Do not use exceptions for every error
  - Exceptions are resource consuming
  - If your function might fail half of the time then you should not handle it with an exception
  - If the error is part of the main functioning of the function don't do exceptions


