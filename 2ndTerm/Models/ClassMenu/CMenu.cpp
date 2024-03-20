#include "/home/sso23ki223/2ndTerm/Models/ClassMenu/CMenu.h"

CMenu::CMenu(string title, CMenuItem* items, size_t count) : title(title), items(items), count(count) {}

void CMenu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ".";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0.Exit" << std::endl;
}

int CMenu::runCommand(std::vector<FactoryWorker> &human)
{
    print();
    std::cout << "\nSelect: ";
    std::cin >> select;
    std::cin.ignore(32767, '\n');
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run(human);
}

int CMenu::runCommand(std::vector<Provider>& human)
{
    print();
    std::cout << "\nSelect: ";
    std::cin >> select;
    std::cin.ignore(32767, '\n');
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run(human);
}

int CMenu::runCommand(std::vector<Product>& products)
{
    print();
    std::cout << "\nSelect: ";
    std::cin >> select;
    std::cin.ignore(32767, '\n');
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run(products);
}

int CMenu::runCommand() {
    print();
    std::cout << "\nSelect: ";
    std::cin >> select;
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run();
}