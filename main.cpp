//
// Created by lukasz on 09.07.23.
//

#include <stdexcept>
#include <fstream>

//mapa.txt status.txt rozkazy.txt [limit_czasowy]
int main(int argc, char *argv[])
{
    std::string mapFileName;
    std::string statusFileName;
    std::string ordersFileName;
    std::string limitTime = "0";
    std::ifstream mapFile;
    std::fstream statusFile;
    std::fstream ordersFile;

    if(argc < 4)
    {
        throw std::invalid_argument("Not enough arguments");
    }
    else {
        mapFileName = argv[1];
        statusFileName = argv[2];
        ordersFileName = argv[3];

        mapFile.open(mapFileName, std::ios::in);
        statusFile.open(statusFileName, std::ios::out|std::ios::in);
        ordersFile.open(ordersFileName, std::ios::out|std::ios::in);
    }
    if(argc == 5)
    {
        limitTime = argv[4];
    }
    if(argc > 5)
    {
        throw std::invalid_argument("Not much arguments");
    }
    // TODO: load files data
    // TODO: create objects or load from files
    // TODO: run game
    // TODO: make actions from opponent
    // TODO: make my actions
    // TODO: save status

    return 0;
}