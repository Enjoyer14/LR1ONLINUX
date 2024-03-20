#include "Provider.h"

Provider::Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType) : User(name, surname, age, login, password)
{
	this->productType = productType;
}
Provider::Provider() : User()
{
	this->name = " ";

}

void Provider::operator=(Provider other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->login = other.login;
	this->password = other.password;
	this->productType = other.productType;
}

void Provider::PrintInfo()
{
	std::cout << "Name: " << this->name << '\n' << "Surname: " << this->surname << '\n' << "Age: " << this->age << '\n' << "Product type: " << this->productType << std::endl;
}
void Provider::AddInfo()
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

	std::cout << "Enter product type: ";
	std::cin >> this->productType;
}

std::string Provider::GetProductType()
{
	return this->productType;
}

int Provider::PrintFullInfo(std::vector<Provider> &human)
{
	for (int i = 0; i < human.size(); i++)
	{
		std::cout << i + 1 << "-th" << std::endl << human[i] << std::endl;
	}
	return 1;
}
int Provider::ProviderAddInfo(std::vector<Provider>& human)
{
	std::cin >> human;
	return 2;
}
int Provider::DeleteProviderInfo(std::vector<Provider>& human)
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

void Provider::Clear()
{
	this->name.clear();
	this->surname.clear();
	this->age = 0;
	this->login.clear();
	this->password.clear();
	this->productType.clear();
}

void Provider::ReadProvidersInfoFromTxt(std::vector<Provider>& human)
{
	int i{};
	std::ifstream fin("Providers.txt");
	Provider buff;
	while (fin >> buff.name >> buff.surname >> buff.age >> buff.login >> buff.password >> buff.productType) {
		human.push_back(buff);
		buff.Clear();
	}
	fin.close();
}
void Provider::UpdateProvidersInfoInTxt(std::vector<Provider>& human)
{
	std::ofstream fout("Providers.txt");
	for (int i{}; i < human.size(); i++)
	{
		fout << human[i].GetName() << '\t' << human[i].GetSurname() << '\t' << human[i].GetAge() << '\t' << human[i].GetLogin() << '\t' << human[i].GetPassword() << '\t' << human[i].GetProductType() << std::endl;
	}
	fout.close();
}