#include "PrivateCompany.h"
#include "StateCompany.h"
#include "Consortium.h"
#include <iostream>

int main() {
    Consortium c("Автомагистрални Авантюристи");
	c.addCompany(new PrivateCompany("Български Багери", 2));
	c.addCompany(new StateCompany("Върховни Влекачи"));
	Consortium *c2 = new Consortium("Грандиозни Грънчари");
	c2->addCompany(new PrivateCompany("Далновидни Дърводелци", 4));
    c.addCompany(c2);
    
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
    
    return 0;
}