#include "raylib.h"
#include "src/engine.h"
#include "src/game.h"
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
    Game chessGame;
    initGame(&chessGame);
    loadChessBoard(&chessGame.raylibChessBoard);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        gameUpdate(&chessGame.chessBoard, &chessGame.gameState, &chessGame.grabbedPieceData);
        int mouseX = GetMouseX();
        int mouseY = GetMouseY(); 
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            drawChessBoard(chessGame.raylibChessBoard, chessGame.chessBoard, mouseX - SQUARE_SIZE / 2, mouseY - SQUARE_SIZE / 2);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    unloadChessBoard(&chessGame.raylibChessBoard);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

