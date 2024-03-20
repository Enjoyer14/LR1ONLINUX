#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "/home/sso23ki223/2ndTerm/Models/ClassProduct/Product.h"
#include "/home/sso23ki223/2ndTerm/Models/ClassWorker/Worker.h"
#include "/home/sso23ki223/2ndTerm/Models/ClassProvider/Provider.h"

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

