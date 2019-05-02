# Day03 Notes

# Inheritance

- A way to make classes relate to each other so that the child will have the same attributes as the parent
  
```
class Animal {
private:
	int _nLegs;

public:
	Animal(void);
	Animal(Animal const &src);
	~Animal(void);

	Animal	&operator=(Animal const &src);

	void	run(int distance);
	void	call(void);
	void	eat(std::string const &what);
	void	walk(int distance);
};

class Cat : public Animal {
public:
	Cat(void);
	Cat(Cat const &src);
	Cat& operator=(Cat const &src);
	~Cat(void);

	void scornSomeone(std::string const &target);
};

class Pony : public Animal {
public:
	Pony(void);
	Pony(Pony const &src);
	Pony& operator=(Pony const &src);
	~Pony(void);

	void	doMagic(std::string const &target);
	void	run(int distance);
};
```

- Both `Pony` and `Cat` inherit all the attributes adn functions from animal
- In `Pony` we are overriding the run method into a new one
- When a child is created you need to instantiate the parent first and then instantiate the kid
  - Same when you destroy it `delete`
- Class scopes:
  - `public` = Accesible from anywhere
  - `protected` = Accesible from the object and their children
  - `private` = accesible only from the object
- Types of inheritance:
  - **Single**: When you inherit from only one class
  - **Multiple**: When you inherit properties and behaviors from more than 1 class
  - **Hierarchical**: When many classes inherit from the same one
  - **Multilevel**: When a class inherits from a class that is already inheriting other one
  - **Hybrid (aka diamond)**: When you inherit from different classe and all this classes where inheriting from a single class
- Encapsulation levels of inheritance is the way you inherit from a class, it can be:
  - **`public`**: public members of the base class stay public in the child and protected stay protected in the new class
  - **`protecter`**: Both public and protected members become protected members of the child class
  - **`private`**: Public and protected members of the base class become private in the child class
- In order to call the constructor or  any other function from the base class you do: `BaseName::Function()`
  - Same for attributes
  - Constructors and destructors need to be called by ourselves right now because we haven't learned what `virtual` is.
```
class Parent {
private:
	int _n;
public:
	Parent(int n);
	~Parent(void);
};

class Child : public Parent {
public:
// This
	Child(int n) : Parent(n) {
		return ;
	}
// Or this is also accepted
	Child(int n) {
		Parent::Parent(n);
		return ;
	}

	~Child(void) {
		Parent::~Parent();
		return ;
	}
};
```