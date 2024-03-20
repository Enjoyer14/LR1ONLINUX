#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Product {

public:

	Product(std::string productType, std::string productTitle, double cost, int quantity);
	Product();

	void Print();
	
	std::string GetType();
	std::string GetTitle();
	double GetCost();
	int GetQuantity();

	void SetCost(double cost);
	void SetQuantity(int quantity);
	void AddInfo();

	static int PrintFullInfo(std::vector<Product>& products);
	static int ProductAddInfo(std::vector<Product>& products);
	static int ProductDeleteInfo(std::vector<Product>& products);

	void Clear();

	static void ReadProductsInfoFromTxt(std::vector<Product>& products);
	static void UpdateProductsInfoInTxt(std::vector<Product>& products);

private:

	std::string productType;
	std::string productTitle;
	double cost;
	int quantity;

};