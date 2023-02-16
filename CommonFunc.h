#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <windows.h>
#include <string>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// Screen
const int FPS = 16;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 40;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0xff; // = 255


#define TILE_SIZE 16
#define BLANK_TILE 0
#define RATIO_PLAYER 2
#define RATIO_MAP 2
#define SIZE_BACK 1

#define MAX_MAP_X 80
#define MAX_MAP_Y 50

#define START_PLAYER 7

#define MAX_FRAME 6
#define MAX_FRAME_SLIME 7
#define MAX_FRAME_SKELETON 6
#define MAX_FRAME_H 5



#define DELAY_ATTACK 20
#define START_ATTACK 5      //thoi gian quai danh player khi va cham
#define DELAY_FRAME 50      //giam toc do ra frame khi chet cho tu nhien hon


typedef struct Input {
    int left_;
    int right_;
    int up_;
    int down_;
    int stop_;
    int attack_;
    bool direction_ = false;
} Input;

typedef struct Map {
    int start_x_;
    int start_y_;

    int max_x_;
    int max_y_;

    int tile[MAX_MAP_X][MAX_MAP_Y];
    std::string file_name_;
} Map;

#endif
