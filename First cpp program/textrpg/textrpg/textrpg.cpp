#include <iostream>
using namespace std;

#include "headers/app.h"

int textrpg() {
    App* app = new App();//For use heap store to avoid out of scope
    app->run();

    delete app;



    return 0;
}