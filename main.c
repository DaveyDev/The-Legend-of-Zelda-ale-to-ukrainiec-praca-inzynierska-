//Wiktor
#include <stdio.h>
#define RAYGUI_IMPLEMENTATION

#include "lib/raygui.h"
#include "lib/raylib.h"
#include "src/scripts/player/player.h"
#include "src/scenes/scenes.h"
#include "src/scripts/global.h"
#include "src/scripts/styles.h"
#include "src/scripts/textures.h"
#include "src/scripts/translation.h"

bool exitMenu = false;

int main(){



    // Raylib Initialization
    //const int screenWidth = 1024;
    //const int screenHeight = 768;
    loadProperties("game.properties");

    
    InitWindow(resolutions[currentResolutionIndex].width, resolutions[currentResolutionIndex].height, ".P.R.I.S.O.N.E.R.");
    SetTargetFPS(600);
    initGuiStyle();
    
    loadTextures();

    //Player player;
    //initPlayer(&player, resolutions[currentResolutionIndex].width, resolutions[currentResolutionIndex].height, 200.0f); // Initial position and speed
    initGlobals();
    
    loadTranslations("data/lang/polish.json");

    while (!WindowShouldClose()) {

        //BeginDrawing();
        //ClearBackground(RAYWHITE);


        //float deltaTime = GetFrameTime();
        //updatePlayer(&player, deltaTime);
        //drawPlayer(&player);

        //int countFPS = GetFPS();
        //DrawText(TextFormat("FPS: %i", countFPS), screenWidth - 100, 15, 20, BLUE);
        //DrawText(TextFormat("ver. 021024"), screenWidth - 150, screenHeight - 100, 20, BLUE);

        //EndDrawing();


        BeginDrawing();

        // Function to print a language-specific greeting
    
    
        
        switch (*currentScene){
            case MENU:
                menuScene();
                break;
            case OPTIONS:
                optionsScene();
                break;
            case GAME:
                prisonScene();
                break;
            default:
                WindowShouldClose();
                break;
        }   
            

        EndDrawing();

    
    }

    freeTranslations();
    unloadTextures();
    CloseWindow(); // Close window and OpenGL context

    return 0;
}