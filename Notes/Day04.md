# Day04 notes

- [Day04 notes](#day04-notes)
	- [Sub-typing polymorphism](#sub-typing-polymorphism)
	- [Abstract classes and interfaces](#abstract-classes-and-interfaces)
		- [Abstract classes](#abstract-classes)
		- [Interfaces](#interfaces)

## Sub-typing polymorphism

```
class Character {
	public:
		void sayHello(std::string const & target);
};

class Warrior : public Character {
	public:
		void sayHello(std::string const & target);
};

class Cat {
	//[...]
};

void Character::sayHello(std::string const & target) {
	std::cout << "Hello " << target << std::endl;
}

void Warrior::sayHello(std::string const & target) {
	std::cout << "F*** off " << target << std::endl;
}

int main(void) {
	Warrior*	a = new Warrior(); // Ok

	Character*	b = new Warrior(); // Ok

	//Warrior*	c = new Character(); // NOT OK
	// Character is not necesary a warrior

	a->sayHello("students");

	b->sayHello("students");
}

PRINTS:
F*** off students
Hello students;
```

- You can assing a parent class pointer the address of a child class instance without a problem
  - But you can't do it the other way because children will always be like parent, but parents don't always are like children
- When doing this you change the behavior of the overriden functions
  - In `Character*	b = new Warrior();` when you call the `sayHello` function you are actually going to call the character function, not the warrior one
    - This is because when you compile, you are telling the compiler that it is a character
- In order for the compiler to check if it needs to call the warrior or the character function in the run time you use the keyword `virtual` before the declaration of the member function:
  - In Character: `virtual void sayHello(std::string const & target);`
  - In Warrior: `virtual void sayHello(std::string const & target);`
  - Note: You don't need to change the cpp part of it
- When you declare a function like `virtual` it creates a dynamic link to the function, so in execution the compiler will need to resolve which function to call.
- **Virtual member function** = method = which is a function which resolution will be dynamic.
  - This are the base of subtyping polymorphsm

## Abstract classes and interfaces

### Abstract classes

- **Pure functions**
  - Recognized because you have `= 0;` at the end of its declaration
  - Pure functions have 2 consecuences:
    - The method can not be implemented. (There's no implementation of the function)
    - You can not instantiate the class because the pure functions is not implemented.
  - **Abstact class** = class which has some functions undefined (pure functions);
  - Convention is that you write the class as: `AClassName`

```
class ACharacter {
	public:
		virtual void	attack(std::string const &target) = 0;
		void			sayHello(std::string const &target);
};

class Warrior : public ACharacter {
	public:
		virtual void attack(std::string const &target);
};

void	ACharacter::sayHello(std::string const &target) {
	std::cout << "Hello " << target << std::endl;
}

void	Warrior::attack(std::string const &target) {
	std::cout << "*attacks " << target << " with a sword" << std::endl;
}

int main(void) {
	ACharacter	*a = new Warrior(); //OK

	// ACharacter	*b = new ACharacter(); // NOT OKAY
	// Because Acharacter is abstract

	a->sayHello("Juan");
	a->attack("Juan");
}
```
- All children classes of an abstract class must define the behavior of the Abstract class pure functions
- Abstract classes can not be instantiated.

### Interfaces

- It is a class with **only** pure functions and **can't** have attributes
- Contract for inheriting classes
- Ways to define a behavior
- The convention is to put an `I` before the class. Ex: `ICoffeeMaker`
- Useful when you develop with others so that you can just show them how you are using the coffeemaker and then they can do whichever coffee makers they want

```
class ICoffeeMaker {
	public:
		virtual void	fillWaterTank(IWaterSource *src) = 0;
		virtual ICoffee	*makeCoffee(std::string const &type) = 0;
};
```