#include "BaseObject.h"

BaseObject::BaseObject() {
    p_Object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObject::~BaseObject() { // ham huy doi tuong
    Free(); //ct ket thuc thuc hien ham huy tranh ton bo nho
}

bool BaseObject::LoadImg(std::string path,SDL_Renderer* screen) {
    Free();

    SDL_Texture* new_Texture = NULL;
    
    SDL_Surface* load_Surface = IMG_Load(path.c_str());
    if (load_Surface != NULL) {
        SDL_SetColorKey(load_Surface, SDL_TRUE, SDL_MapRGB(load_Surface->format, COLOR_KEY_R,COLOR_KEY_G, COLOR_KEY_B));
        new_Texture = SDL_CreateTextureFromSurface(screen, load_Surface);
        if (new_Texture != NULL) {
            rect_.w = load_Surface->w;
            rect_.h = load_Surface->h;
        }

        SDL_FreeSurface(load_Surface);
    }

    p_Object_ = new_Texture;

    return p_Object_ != NULL;
}

void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};

    SDL_RenderCopy(des, p_Object_, clip, &renderquad);
}

void BaseObject::Free()
{
    if(p_Object_ != NULL)
    {
        SDL_DestroyTexture(p_Object_);
        p_Object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}
