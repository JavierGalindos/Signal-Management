//
//  main.cpp
//  Projectv2
//
//  Created by Javier Galindos on 29/11/20.
//

#include <iostream>

#include "FileManagement.hpp"
#include "SquareWave.hpp"
#include "UI.hpp"


using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<SquareWave> Signals;
    
    init();
    Menu(Signals);
    
    return 0;
}
