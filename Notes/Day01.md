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

