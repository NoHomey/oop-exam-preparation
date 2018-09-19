#include "PrivateCompany.h"
#include "StateCompany.h"
#include "Consortium.h"
#include <iostream>

int main() {
    Consortium c("Автомагистрални Авантюристи");
	c.addCompany(new PrivateCompany("Български Багери", 2));
	c.addCompany(new StateCompany("Върховни Влекачи"));
    
    c.printStatus(std::cout);

    c.removeCompany("Грандиозни Грънчари");

    c.printStatus(std::cout);

    Consortium copy = c;
    std::cout << "copy" << std::endl;
    copy.printStatus(std::cout);

    c.perform("taks");

    c.printStatus(std::cout);
    std::cout << "copy" << std::endl;
    copy.printStatus(std::cout);

    copy = c;

    c.printStatus(std::cout);
    std::cout << "copy" << std::endl;
    copy.printStatus(std::cout);

    c.perform("taks");
    
    return 0;
}