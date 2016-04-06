//
//  main.cpp
//  ZombieGame
//
//  Created by Hamashy on 13.02.2016.
//  Copyright © 2016 Hamashy. All rights reserved.
//

#include <iostream>

#include "MainGameWindow.hpp"

#include "../SimpleGameEngine/SGE/Relay/sge_relay.hpp"

std::function<void(void)> game = []{
    float gameBox[] = {SCREEN_WIDTH, SCREEN_HEIGHT};
    
    MainGameWindow* mainWindow = new MainGameWindow(gameBox[0], gameBox[1]);
    mainWindow->init();
    mainWindow->show();
    
    mainWindow->run();
    
    delete mainWindow;
};

int main(int argc, char * argv[]) {
    std::cout.setf(std::ios::boolalpha);

	SGE::Relay* r = SGE::Relay::getRelay(); //Testing 
//	delete r; //this will not compile, user cannot delete Relay.

    game();
    
    return 0;
}
