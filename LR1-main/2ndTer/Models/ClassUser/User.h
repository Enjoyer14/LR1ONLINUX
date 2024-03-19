#pragma once

#include <string>

class User {

public:
	User(std::string name, std::string surname, int age, std::string login, std::string password);
	User();

	virtual void PrintInfo() = 0;
	virtual void AddInfo() = 0;

	friend std::ostream& operator<< (std::ostream& out, User& providers);

	std::string GetName();
	std::string GetSurname();
	int GetAge();
	std::string GetLogin();
	std::string GetPassword();

protected:

	std::string name;
	std::string surname;
	int age;
	std::string login;
	std::string password;

};