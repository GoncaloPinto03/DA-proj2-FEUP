#include <iostream>
#include "Read_files.h"
#include "Manager.h"
#include "menu.h"

int main() {


    Menu menu;
    bool run = true;
    while (run) {
        run = menu.nextState(0);
    }



    return 0;
}