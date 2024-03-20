#include "Product.h"

Product::Product(std::string productType, std::string productTitle, double cost, int quantity)
{
	this->productType = productType;
	this->productTitle = productTitle;
	this->cost = cost;
	this->quantity = quantity;
}
Product::Product() {

}

void Product::Print() {
	std::cout << "Product type: " << productType << '\n' << "Product title: " << productTitle << '\n' << "Cost: " << cost << '\n' << "Quantity: " << quantity << std::endl;
}

std::string Product::GetType()
{
	return this->productType;
}
std::string Product::GetTitle()
{
	return this->productTitle;
}
double Product::GetCost() { return this->cost; }
int Product::GetQuantity() { return this->quantity; }

void Product::SetCost(double cost)
{
	this->cost = cost;
}
void Product::SetQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::AddInfo()
{
	std::cout << "Enter type: ";
	std::cin >> this->productType;

	std::cout << "Enter product title: ";
	std::cin >> this->productTitle;

	std::cout << "Enter cost: ";
	std::cin >> this->cost;
	std::cin.ignore(32767, '\n');

	std::cout << "Enter quantity: ";
	std::cin >> this->quantity;
	std::cin.ignore(32767, '\n');

}

int Product::PrintFullInfo(std::vector<Product>& products)
{
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << i + 1 << "-th" << std::endl;
		products[i].Print();
		std::cout << std::endl;
	}
	return 1;
}
int Product::ProductAddInfo(std::vector<Product>& products)
{
	Product buff;
	buff.AddInfo();
	products.push_back(buff);

	return 2;
}
int Product::ProductDeleteInfo(std::vector<Product>& products)
{
	PrintFullInfo(products);
	int variant{};
	std::cout << "Choose variant: ";
	std::cin >> variant;
	std::cin.ignore(32767, '\n');
	variant--;

	products.erase(products.begin() + variant);

	return 3;
}

void Product::Clear()
{
	this->productType.clear();
	this->productTitle.clear();
	this->cost = 0;
	this->quantity = 0;
}

void Product::ReadProductsInfoFromTxt(std::vector<Product>& products)
{
	int i{};
	std::ifstream fin("Products.txt");
	Product buff;
	while (fin >> buff.productType >> buff.productTitle >> buff.cost >> buff.quantity) {
		products.push_back(buff);
		buff.Clear();
	}
	fin.close();
}
void Product::UpdateProductsInfoInTxt(std::vector<Product>& products)
{
	std::ofstream fout("Products.txt");
	for (int i{}; i < products.size(); i++)
	{
		fout << products[i].GetType() << '\t' << products[i].GetTitle() << '\t' << products[i].GetCost() << '\t' << products[i].GetQuantity() << std::endl;
	}
	fout.close();
}