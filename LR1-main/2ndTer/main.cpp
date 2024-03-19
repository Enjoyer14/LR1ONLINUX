#include "Models/ClassMenu/CMenu.h"
#include "Models/ClassMenuItem/CMenuItem.h"
#include "Models/ClassProduct/Product.h"
#include "Models/ClassWorker/Worker.h"
#include "Models/ClassProvider/Provider.h"
#include <fstream>
#include <vector>

using namespace std;

const int ITEM_NUMBER = 3;
const int ITEM_NUMBER_2 = 3;

int LogIn()
{
    bool isLogIn{};
    std::string login, password;
    while (isLogIn == false) {

        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;

        ifstream fin("Logs.txt");
        std::string buffLogin, buffPassword;
        if (fin.is_open())
        {
            while (fin >> buffLogin >> buffPassword)
            {
                if (login == buffLogin && password == buffPassword)
                {
                    isLogIn = true;
                    fin.close();
                    std::cout << "Succesfully. " << std::endl;

                    return 1;
                }
            }
            std::cout << "Wrong login or password, try again." << std::endl;
        }
    }
}

//дружественные перегрузки операторов
std::ostream& operator<< (std::ostream& out, User& human) {
    human.PrintInfo();
    return out;
}
std::istream& operator>> (std::istream& in, std::vector<FactoryWorker>& human)
{
    FactoryWorker buff;
    buff.AddInfo();
    human.push_back(buff);

    return in;
}
std::istream& operator>> (std::istream& in, std::vector<Provider>& human)
{
    Provider buff;
    buff.AddInfo();
    human.push_back(buff);

    return in;
}

int Factory()
{
    std::vector<FactoryWorker> workers{};

    FactoryWorker::ReadWorkersInfoFromTxt(workers);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print worker info", (CMenuItem::FunctionWorker)FactoryWorker::PrintFullInfo},
        CMenuItem{"Add worker info.", (CMenuItem::FunctionWorker)FactoryWorker::FactoryAddInfo},
        CMenuItem{"Delete worker info.", (CMenuItem::FunctionWorker)FactoryWorker::DeleteWorkerInfo},
        //CMenuItem{"Sort human info.", (CMenuItem::FunctionU)Sort}// сюда сортировку
    };
    CMenu menu("Factory Menu", items, ITEM_NUMBER_2);
    while (menu.runCommand(workers)) {
    };

    FactoryWorker::UpdateWorkersInfoInTxt(workers);

    return 1;
}

int Provide()
{
    std::vector<Provider> workers{};

    Provider::ReadProvidersInfoFromTxt(workers);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print provider info", (CMenuItem::FunctionProvider)Provider::PrintFullInfo},
        CMenuItem{"Add provider info.", (CMenuItem::FunctionProvider)Provider::ProviderAddInfo},
        CMenuItem{"Delete provider info.", (CMenuItem::FunctionProvider)Provider::DeleteProviderInfo},
        //CMenuItem{"Sort human info.", (CMenuItem::FunctionU)Sort} // сюда сортировку 
    };
    CMenu menu("Provider Menu", items, ITEM_NUMBER_2);
    while (menu.runCommand(workers)) {
    };

    Provider::UpdateProvidersInfoInTxt(workers);

    return 2;
}

// g++ ./main.cpp ./Models/ClassMenuItem/CMenuItem.cpp ./Models/ClassMenu/CMenu.cpp ./Models/ClassUser/User.cpp ./Models/ClassWorker/Worker.cpp ./Models/ClassProvider/Provider.cpp ./Models/ClassProduct/Product.cpp

int Production()
{

    std::vector<Product> products{};

    Product::ReadProductsInfoFromTxt(products);

    CMenuItem items[ITEM_NUMBER_2]{
        CMenuItem{"Print product info", (CMenuItem::FunctionProduct)Product::PrintFullInfo},
        CMenuItem{"Add product info.", (CMenuItem::FunctionProduct)Product::ProductAddInfo},
        CMenuItem{"Delete product info.", (CMenuItem::FunctionProduct)Product::ProductDeleteInfo}
    };
    CMenu menu("Product Menu", items, ITEM_NUMBER_2);
    while (menu.runCommand(products)) {
    };

    Product::UpdateProductsInfoInTxt(products);

    return 3;
}

int main() {

    setlocale(LC_ALL, "RU");

    LogIn();

    CMenuItem items[ITEM_NUMBER]{
         CMenuItem{"Factory", Factory},
         CMenuItem{"Provider", Provide},
         CMenuItem{"Production", Production}
    };
    CMenu menu("Choosing", items, ITEM_NUMBER);

    while (menu.runCommand()) {
    };

    return 0;
}