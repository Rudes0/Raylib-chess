#include "raylib.h"
#include "src/chessRaylib.h"
#include "src/engine.h"
#include <stdio.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    //chess board is size 938x938px where every tile is 117x117px 
    //117 * 117 + 2 = 938  
    //you can round up to 116 for center 
    //image is 1080x1080px
    InitWindow(0, 0, "raylib [core] example - basic window");
    ToggleBorderlessWindowed();   
    RaylibChessBoard board;
    loadChessBoard(&board);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        gameUpdate(&board.chessBoardData);
        int mouseX = GetMouseX();
        int mouseY = GetMouseY(); 
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            drawChessBoard(board, mouseX - SQUARE_SIZE / 2, mouseY - SQUARE_SIZE / 2);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    unloadChessBoard(&board);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

