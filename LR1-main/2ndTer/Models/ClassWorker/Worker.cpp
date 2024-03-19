#include "Worker.h"

FactoryWorker::FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle) : User(name, surname, age, login, password)
{
	this->jobTitle = jobTitle;
}
FactoryWorker::FactoryWorker() : User()
{
	this->jobTitle = " ";
}

void FactoryWorker::operator=(FactoryWorker other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->login = other.login;
	this->password = other.password;
	this->jobTitle = other.jobTitle;
}
bool FactoryWorker::operator>(const FactoryWorker& right)
{
	return (strcmp(this->surname.c_str(), right.surname.c_str()) > 0);
}

void FactoryWorker::PrintInfo()
{
	std::cout << "Name: " << this->name << '\n' << "Surname: " << this->surname << '\n' << "Age: " << this->age << '\n' << "Job title: " << this->jobTitle << std::endl;
}
void FactoryWorker::AddInfo()
{
	std::cout << "Enter name: ";
	std::cin >> this->name;

	std::cout << "Enter surname: ";
	std::cin >> this->surname;

	std::cout << "Enter age: ";
	std::cin >> this->age;
	std::cin.ignore(32767, '\n');

	std::cout << "Enter login: ";
	std::cin >> this->login;

	std::cout << "Enter password: ";
	std::cin >> this->password;

	std::cout << "Enter job title: ";
	std::cin >> this->jobTitle;
}

std::string FactoryWorker::GetJobTitle()
{
	return this->jobTitle;
}

int FactoryWorker::PrintFullInfo(std::vector<FactoryWorker>& human)
{
	for (int i = 0; i < human.size(); i++)
	{
		std::cout << i + 1 << "-th" << std::endl << human[i] << std::endl;
	}
	return 1;
}
int FactoryWorker::FactoryAddInfo(std::vector<FactoryWorker>& human)
{
	std::cin >> human;
	return 2;
}
int FactoryWorker::DeleteWorkerInfo(std::vector<FactoryWorker>& human)
{
	PrintFullInfo(human);
	int variant{};
	std::cout << "Choose variant: ";
	std::cin >> variant;
	std::cin.ignore(32767, '\n');
	variant--;

	human.erase(human.begin() + variant);
	return 3;
}

void FactoryWorker::Clear()
{
	this->name.clear();
	this->surname.clear();
	this->age = 0;
	this->login.clear();
	this->password.clear();
	this->jobTitle.clear();
}

void FactoryWorker::ReadWorkersInfoFromTxt(std::vector<FactoryWorker>& workers)
{
	int i{};
	std::ifstream fin("Workers.txt");
	FactoryWorker buff;
	while (fin >> buff.name >> buff.surname >> buff.age >> buff.login >> buff.password >> buff.jobTitle) {
		workers.push_back(buff);
		buff.Clear();
	}
	fin.close();
}
void FactoryWorker::UpdateWorkersInfoInTxt(std::vector<FactoryWorker>& workers)
{
	std::ofstream fout("Workers.txt");
	for (int i{}; i < workers.size(); i++)
	{
		fout << workers[i].GetName() << '\t' << workers[i].GetSurname() << '\t' << workers[i].GetAge() << '\t' << workers[i].GetLogin() << '\t' << workers[i].GetPassword() << '\t' << workers[i].GetJobTitle() << std::endl;
	}
	fout.close();
}
