#include <iostream>
#include <SDL.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "Map.h"
#include "MainObject.h"
#include "Time.h"

BaseObject g_background;

bool InitData() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }
     
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"); // ti le chat luong

    g_window = SDL_CreateWindow("Game SDL", SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SCREEN_WIDTH,
                                                SCREEN_HEIGHT,
                                                SDL_WINDOW_SHOWN);//cap nhat do dai rong cua man hinh

    if (g_window == NULL) {
        success = false;
    }
    else {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL) {
            success = false;
        }   
        else {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) && imgFlags)) {
                success = false;
            }
        }
    }

    return success;
}

bool LoadBackground() {
    bool ret = g_background.LoadImg("assets/menu.png", g_screen);
    if (ret == false)   return false;
    return true;
}

void close() {
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}
int main( int argc, char *argv[] ) {

    Time fps_time;
    //srand((int)time(0));
    if(InitData() == false) {
        return -1;
    }
    
    if (LoadBackground() == false) {
        return -1;
    }

    GameMap game_map;
    game_map.LoadMap("map/Map1/map_layer0.txt");
    game_map.LoadTiles(g_screen);


    GameMap game_map1;
    game_map1.LoadMap("map/Map1/map_layer1.txt");
    game_map1.LoadTiles(g_screen);

    GameMap game_map2;
    game_map2.LoadMap("map/Map1/map_layer2.txt");
    game_map2.LoadTiles(g_screen);

    MainObject p_player;
    p_player.LoadImg("img/player.png",g_screen);
    //p_player.set_clips();
    
    bool is_quit = false;
    while(!is_quit) {
        fps_time.start();
        while(SDL_PollEvent(&g_event)) {
            if (g_event.type == SDL_QUIT) {
                is_quit = true;
            }

            p_player.HandelInputAction(g_event, g_screen);
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        //g_background.Render(g_screen, NULL);
                
        Map map_data = game_map.getMap();
        // Map map_data1 = game_map1.getMap();
        // Map map_data2 = game_map2.getMap();


        p_player.SetMapXY(map_data.start_x_, map_data.start_y_); // chia thanh map nho hon
        // p_player.SetMapXY(map_data1.start_x_, map_data1.start_y_); // chia thanh map nho hon
        // p_player.SetMapXY(map_data2.start_x_, map_data2.start_y_); // chia thanh map nho hon

        p_player.DoPlayer(map_data);
        // p_player.DoPlayer(map_data1);
        // p_player.DoPlayer(map_data2);
        //p_player.CheckToMap(map_data);
        

        game_map.SetMap(map_data);
        game_map.DrawMap(g_screen); 


        // game_map1.SetMap(map_data1);
        // game_map1.DrawMap(g_screen); 


        // game_map2.SetMap(map_data2);
        // game_map2.DrawMap(g_screen); 


        p_player.set_clips();
        p_player.Show(g_screen);
       

        SDL_RenderPresent(g_screen);

        int real_time = fps_time.getTicks();
        int time_one_frame = 1000/FPS; // ms

        if (real_time < time_one_frame) {
            int delay_time = time_one_frame - real_time;

            if (delay_time >= 0) {
                SDL_Delay(delay_time);
            }
        }
    }

    close(); 
    return 0;
}
