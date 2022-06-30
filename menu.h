#ifndef GIMBABHEAVEN_MENU_H
#define GIMBABHEAVEN_MENU_H
#include <cstring>


class Menu {
private:
    char * name;
    int price;
public:
    Menu(char * menuname, int menuprice) {
        name = new char[strlen(menuname) + 1];
        strcpy(name, menuname);
        price = menuprice;
    }
    Menu() {
        name = new char[0];
        strcpy(name, " ");
        price = 0;
    };
    char * getName() {
        return name;
    }
    int getPrice() const {
        return price;
    }
};


#endif //GIMBABHEAVEN_MENU_H
