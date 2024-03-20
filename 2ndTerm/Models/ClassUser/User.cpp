#include "User.h"

User::User(std::string name, std::string surname, int age, std::string login, std::string password)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->login = login;
	this->password = password;
}
User::User()
{
	this->name = " ";
	this->surname = " ";
	this->age = 0;
	this->login = " ";
	this->password = " ";
}

std::string User::GetName()
{
	return this->name;
}
std::string User::GetSurname()
{
	return this->surname;
}
int User::GetAge()
{
	return this->age;
}
std::string User::GetLogin()
{
	return this->login;
}
std::string User::GetPassword()
{
	return this->password;
}
