#include <iostream>
#include <string>
#include <vector>

/*class Person {
protected:
	std::string _name;
	unsigned int _age;
public:
	Person(std::string name, unsigned int age) {
		this->_name = name;
		this->_age = age;
	}

	virtual void showData() = 0;

};

class Student : public Person {
private:
	std::vector<int>_marks;
public:
	Student(std::string name, unsigned int age, std::vector<int>&marks) : Person(name, age){
		_marks = marks;
	}
	void showData() override {
		std::cout << "________________________________" << std::endl;
		std::cout << "Имя:     |" << _name << std::endl;
		std::cout << "Возраст: |" << _age << std::endl;
		std::cout << "Оценки:  |";
		for (const auto& it : _marks)
			std::cout << it << " ";
		std::cout << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
	}
};

class Professor : public Person{
private:
	std::string _degree;
public:
	Professor(std::string name, unsigned int age, std::string degree) : Person(name, age) {
		_degree = degree;
	}
	void showData() override{
		std::cout << "________________________________" << std::endl;
		std::cout << "Имя:         |" << _name << std::endl;
		std::cout << "Возраст:     |" << _age << std::endl;
		std::cout << "Уч. степень: |" << _degree << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
	}
};*/

class Worker {
private:
	std::string _name;
	unsigned int _age;
	float _bill;
public:
	Worker(std::string name, unsigned int age) : _name(name), _age(age) {}
	virtual void Work() = 0;//Чистая вирт. функция

	void Bill(int hoursOfWork) {
		_bill = 250 * hoursOfWork;
		std::cout << "З/п: " << _bill << '\n';
	}

	std::string GetName() {
		return _name;
	}
	unsigned int GetAge() {
		return _age;
	}
	float GetBill() {
		return _bill;
	}
};

class Buyer : public Worker {
public:
	Buyer(std::string name, unsigned int age): Worker(name, age){}
	void Work() override {
		std::cout << GetName() << " - " << GetAge() << " лет" << ": " << "Покупает. ";
	}
};

class Builder : public Worker {
public:
	Builder(std::string name, unsigned int age): Worker(name, age) {}
	void Work() override {
		std::cout << GetName() << " - " << GetAge() << " лет" << ": " << "Строит. ";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	/*std::vector<int>marks = {12, 5, 6, 4, 8, 12};
	Student student("John", 20, marks);
	Professor professor("Alex", 35, "Доктор фил. наук");
	std::cout << "Студент: " << std::endl;
	student.showData();
	std::cout << "Профессор: " << std::endl;
	professor.showData();*/

	Buyer buy("John", 20);
	Builder build("Chris", 34);
	buy.Work();
	buy.Bill(20);
	build.Work();
	build.Bill(30);


	return 0;
}