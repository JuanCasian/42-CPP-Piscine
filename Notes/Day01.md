# Day01 Notes

## New and Delete

- Two new operators that replace `malloc` and `free`
  - `new` allocate memory
  - `delete` deletes the memory
- Malloc and free can't be used any more because they don't call the constructor nor the destructor
- When you call `new` you get a pointer to the instance, not the instance itself
- You always need to `delete` the instances allocated in memory
```
**Student.cpp**

class Student {
	private:
		std::string _login;
	
	public:
		Student(std::string login) : _login(login) {
			return;
		}

		~Student(void) {
			return ;
		}
};
```
```
**main.cpp**

int main(void) {
	// Student in stack
	Student bob = Student("bfubar");
	// Student allocated in memory
	Student *jim = new Student("jfubar");

	// Student allocated needs to be deleted;
	delete jim;
	return (0);
}
```
- You can allocate an array of classes but your constructor should not take any parameters, because you can't pass them
```
**Student.cpp**

class Student {
	private:
		std::string _login;
	
	public:
		Student(void) : _login("default") {
			return;
		}

		~Student(void) {
			return ;
		}
};
```
```
**main.cpp**

int main(void) {
	// allocating array of students
	Student students = new Students[42];

	// Deleting an array of students
	delete [] students;
}
```

--- 

## References

- Kind of like pointers but not the same
- They are an alias for an existing variable
- "Is a pointer that is constant and never dereferenced" 
- References are constants, you can't change them
- References can't point to nothing, you need to assign them from the beginning
- References don't need to be unreferenced (no need for `*varname`)
- You are using the reference as if it was the variable
- The problem with refernces is that you can't do uninitialized references
```
**main.cpp**

#include <iostream>

int main(void) {
	int nBalls = 42;

	// Creating pointer
	int *ballsPtr = &nBalls;
	// Creating a reference
	int &ballsRef = nBalls;

	// Changes the value of nBalls to 21
	*ballsPtr = 21;

	// Changes value of nBalls to 84
	ballsRed = 84;
}
```

- You can also pass references as parameters
- Note that you don't need to call the function any diferent

```
**other.cpp***

void byRef(std::string &str) {
	std::cout << str << std::endl;
}
```
```
**main.cpp**

int main(void) {
	std::string str = "HELLO";
	byRef(str);
	return 0;
}
```

- You can also return references
- Notice that you don't need to change anything on the return statement
- When you return references you can actually change values from the end of a function
```
**Student.cpp**

class Student {
private: 
	std::string _login;
public:
	...
	std::string	&getLoginRef(void) {
		return this->_login;
	}
	std::string const &getLoginRefConst(void) {
		return this->_login;
	}
};
```
```
**main.cpp**

int main(void) {
	Student bob = Student("bfubar");

	// this will use the returned reference to change the value of
	// _login in the class
	bob.getLoginRef() = "bobfubar";
	return 0;
}
```
- If at some point the var should not exist or will change use a pointer, else use a reference

---

## Filestreams

- Used to learn from diferent streams, stdin, stdout, stderr, or files
- `std::ifstream` == input filestream
- `std::ofstream` == output filestream

```
**numbers**

FILE:
15 3 12 33 52 623 53
```
```
**main.cpp**
int main(void)
{
	// Creating input stream
	std::ifstream ifs("numbers");
	int dst1;
	int dst2;

// Reading from file numbers. dst1 = 15, dst2 = 3
	ifs >> dst1 >> dst 2;
	ifs.close();

	std::ofstream	ofs("test.out");

	ofs << "Writing into the file << std::endl;
	ofs.close();
}
```
- You can also do the stream in two parts
  - `std::ifstream ifs`
  - `ifs.open("FILENAME")`
- There are a lot of functions for streams, you can look them up in cpp documentation