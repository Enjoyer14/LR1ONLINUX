#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "/home/sso23ki223/2ndTerm/Models/ClassMenuItem/CMenuItem.h"

using namespace std;

class CMenu {

public:
    CMenu(string, CMenuItem*, size_t);

    void print();

    int runCommand(std::vector<FactoryWorker> &human);
    int runCommand(std::vector<Provider>& human);
    int runCommand(std::vector<Product>& products);
    int runCommand();

private:
    int select{ -1 };
    size_t count{};
    string title{};
    CMenuItem* items{};
};