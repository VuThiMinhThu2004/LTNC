#ifndef SOUNDSEff_H
#define SOUNDSEff_H
#include "CommonFunc.h"
#include <map>


class SoundsEff {
public:
    SoundsEff();
    ~SoundsEff();
    void addSound(std::string name,std::string path);
    void PlaySound(std::string name);

private:
    std::map<std::string,Mix_Chunk* > Chunks;
};


#endif