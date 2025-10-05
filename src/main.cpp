#include "main.hpp"

int main(int argc, char *argv[]){
    std::cout<<"WORKS!!!"<<std::endl;

    std::string pattern;
    std::vector<std::string> paths;
    try{
    Config config = parse_parameters(argc, argv, pattern, paths);
    } catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl<<"1"<<std::endl;
        return 1;
    }

    std::cout<<pattern<<std::endl;
    for(auto it=paths.begin(); it!=paths.end();it++){
        std::cout<<*it<<std::endl;
    }
    std::cout<<"0"<<std::endl;
    return 0;
}