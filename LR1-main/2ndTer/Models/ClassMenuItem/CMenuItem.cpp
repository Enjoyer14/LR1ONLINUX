#include "CMenuItem.h"

CMenuItem::CMenuItem(string name, Func func) : item_name(name), func(func) {}
CMenuItem::CMenuItem(string name, FunctionWorker function) : item_name(name), functionWorkerInt(function) {}
CMenuItem::CMenuItem(string name, FunctionProvider function) : item_name(name), functionProviderInt(function) {}
CMenuItem::CMenuItem(string name, FunctionProduct function) : item_name(name), functionProductInt(function) {}

void CMenuItem::print()
{
    std::cout << item_name;
}

int CMenuItem::run(std::vector<FactoryWorker>& human)
{
    return functionWorkerInt(human);
}

int CMenuItem::run(std::vector<Provider>& human)
{
    return functionProviderInt(human);
}

int CMenuItem::run(std::vector<Product>& products)
{
    return functionProductInt(products);
}

int CMenuItem::run()
{
    return func();
}

