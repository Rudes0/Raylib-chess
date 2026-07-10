#include "raylib.h"
#include "src/chessRaylib.h"
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
    Vector2 closestSquare;
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            closestSquare = checkClosestToMouse(board.chessBoardData);
            printf("closest x = %d, closest y = %d\n", (int)closestSquare.x, (int)closestSquare.y);
        }
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            drawChessBoard(board);
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

