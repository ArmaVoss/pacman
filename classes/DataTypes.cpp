#include "DataTypes.h"

std::unordered_map<int, std::string> uiScore;

void initializeUIScore(){
    std::string path = "../sprites/ui/_.png"; 
    int len = path.length() - 5; 

    for (int i = 0; i < 10; i++) {
        path[len] = '0' + i; 
        uiScore.insert({i, path});
    }
    uiScore.insert({10, "../sprites/ui/score.png"});

}
