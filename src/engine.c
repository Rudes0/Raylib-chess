#include "engine.h"
#include "chessRaylib.h"
#include <raylib.h>
#include <stdio.h>

Piece wPawn = {
    .type = pawn,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece wKnight = {
    .type = knight,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece wBishop = {
    .type = bishop,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece wRook = {
    .type = rook,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece wQueen = {
    .type = queen,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece wKing = {
    .type = king,
    .color = white,
    .hasMoved = false,
    .isPicked = false
};

Piece bPawn = {
    .type = pawn,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece bKnight = {
    .type = knight,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece bBishop = {
    .type = bishop,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece bRook = {
    .type = rook,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece bQueen = {
    .type = queen,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece bKing = {
    .type = king,
    .color = black,
    .hasMoved = false,
    .isPicked = false
};

Piece emptyPiece = {
    .type = empty,
    .color = noColor,
};

ChessBoard initChessBoard(void) 
{
    ChessBoard chessBoard;
    int xStartPosition = 450 + 36;
    int yStartPosition = 72;
    chessBoard.squares[0][0].position.x = xStartPosition;
    chessBoard.squares[0][0].position.y = yStartPosition; 
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            // positioin setup position algorythm 
            if((x == 0) && (y == 0)) continue;
            chessBoard.squares[x][y].position.x = xStartPosition + SQUARE_SIZE * x;
            chessBoard.squares[x][y].position.y = yStartPosition + SQUARE_SIZE * y;
            chessBoard.squares[x][y].piece.type = empty;
        }
    }
    //setup pawns
    for(int p = 0; p < 8; p++)
    {
        chessBoard.squares[p][1].piece = bPawn;
        chessBoard.squares[p][6].piece = wPawn;
    }
    //setup knights 
    chessBoard.squares[1][0].piece = bKnight;
    chessBoard.squares[6][0].piece = bKnight;
    chessBoard.squares[1][7].piece = wKnight;
    chessBoard.squares[6][7].piece = wKnight;
    //setup bishops
    chessBoard.squares[2][0].piece = bBishop;
    chessBoard.squares[5][0].piece = bBishop;
    chessBoard.squares[2][7].piece = wBishop;
    chessBoard.squares[5][7].piece = wBishop;
    //setup rooks 
    chessBoard.squares[0][0].piece = bRook;
    chessBoard.squares[7][0].piece = bRook;
    chessBoard.squares[0][7].piece = wRook;
    chessBoard.squares[7][7].piece = wRook;
    //setup queens
    chessBoard.squares[3][0].piece = bQueen;
    chessBoard.squares[3][7].piece = wQueen;
    //setup kings
    chessBoard.squares[4][0].piece = bKing;
    chessBoard.squares[4][7].piece = wKing;
    return chessBoard;
}

void gameUpdate(ChessBoard* chessBoardData)
{
    Vector2 mousePostion;
    mousePostion.x = GetMouseX();
    mousePostion.y = GetMouseY();
    Vector2 closestSquare = checkClosestToMouse(*chessBoardData, mousePostion);
    grabPiece(chessBoardData, closestSquare);
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            relasePiece(chessBoardData, closestSquare, x, y);
        }
    }
}

Vector2 checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos)
{
    Vector2 closestSquare = {0, 0};
    printf("mouse position x = %f, y = %f\n", mousePos.x, mousePos.y); 
    for(int x = 0; x < 8; x++)
    {
        if(Abs((int)mousePos.x - (int)chessBoard.squares[x][0].position.x - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.x = x;
            break;
        }
    }
    for(int y = 0; y < 8; y++)
    {
        if(Abs((int)mousePos.y - (int)chessBoard.squares[0][y].position.y - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.y = y;
            break;
        }
    }
    return closestSquare;
}

void grabPiece(ChessBoard* chessBoard, Vector2 closestSquare)
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.type != empty)
        {
            if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked == false)
            {
                chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked = true;
            }
        }
    }
}

void relasePiece(ChessBoard* chessBoard, Vector2 closestSquare, int x, int y)
{
    if(chessBoard->squares[x][y].piece.type != empty)
    {
        if(chessBoard->squares[x][y].piece.isPicked == true && IsMouseButtonUp(MOUSE_LEFT_BUTTON))
        {
            Piece tempPiece = chessBoard->squares[x][y].piece;
            chessBoard->squares[x][y].piece = emptyPiece; 
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece = tempPiece; 
            chessBoard->squares[x][y].piece.isPicked = false;
        }
    }
}


int Abs(int val)
{
    if(val == 0) return 0;
    if(val > 0) return val;
    if(val < 0) return -val;
    return 0;
}
