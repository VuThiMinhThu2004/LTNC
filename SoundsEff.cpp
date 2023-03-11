#include "SoundsEff.h"

SoundsEff::SoundsEff() {
}
SoundsEff::~SoundsEff() {
    for (auto &c : Chunks)
    {
        Mix_FreeChunk(c.second);
    }
}
void SoundsEff::addSound(std::string name, std::string path) {
    Mix_Chunk *new_chunk = Mix_LoadWAV(path.c_str());
    Chunks.emplace(name, new_chunk);
}
void SoundsEff::PlaySound(std::string name) {
    Mix_PlayChannel(-1, Chunks[name], 0);
}