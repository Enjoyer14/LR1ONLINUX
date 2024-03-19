#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "/home/sso23ki223/Table/2ndTerm/Models/ClassUser/User.h"
//#include "C:\Users\stass\OneDrive\Рабочий стол\LR1-main\2ndTer\Models\ClassUser\User.h"

class FactoryWorker : public User {

public:
	FactoryWorker();
	FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle);

	void PrintInfo() override;
	void AddInfo() override;

	void operator = (FactoryWorker other);
	bool operator>(const FactoryWorker& right);

	friend std::istream& operator>> (std::istream& in, std::vector<FactoryWorker>& human);

	static int PrintFullInfo(std::vector<FactoryWorker>& human);
	static int FactoryAddInfo(std::vector<FactoryWorker>& human);
	static int DeleteWorkerInfo(std::vector<FactoryWorker>& human);

	std::string GetJobTitle();

	void Clear();

	static void ReadWorkersInfoFromTxt(std::vector<FactoryWorker>& workers);
	static void UpdateWorkersInfoInTxt(std::vector<FactoryWorker>& workers);

private:

	std::string jobTitle;

};
