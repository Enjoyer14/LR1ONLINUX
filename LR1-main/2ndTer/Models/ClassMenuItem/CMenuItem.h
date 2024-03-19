#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/sso23ki223/Table/2ndTerm/Models/ClassUser/User.h"
#include "/home/sso23ki223/Table/2ndTerm/Models/ClassProduct/Product.h"
//#include "C:\Users\stass\OneDrive\Рабочий стол\LR1-main\2ndTer\Models\ClassUser\User.h"
//#include "C:\Users\stass\OneDrive\Рабочий стол\LR1-main\2ndTer\Models\ClassProduct\Product.h"

using namespace std;

class CMenuItem {

public:
    typedef int(*Func)();
    typedef int(*FunctionWorker)(std::vector<FactoryWorker>&);
    typedef int(*FunctionProvider)(std::vector<Provider>&);
    typedef int(*FunctionProduct)(std::vector<Product>&);

    CMenuItem(string, FunctionWorker);
    CMenuItem(string, FunctionProvider);
    CMenuItem(string, FunctionProduct);
    CMenuItem(string, Func);

    FunctionWorker functionWorkerInt{};
    FunctionProvider functionProviderInt{};
    FunctionProduct functionProductInt{};
    Func func{};

    string item_name{};
    void print();

    int run(std::vector<FactoryWorker>& human);
    int run(std::vector<Provider>& human);
    int run(std::vector<Product>& products);
    int run();
};

