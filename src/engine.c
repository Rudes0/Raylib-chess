#include "engine.h"
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

void mouseMechanics(void)
{
        
}

Vector2 checkClosestToMouse(ChessBoard chessBoard)
{
    Vector2 mousePos;
    mousePos.x = GetMouseX();
    mousePos.y = GetMouseY();

    Vector2 closestSquare = {0, 0};
    for(int x = 0; x < 8; x++)
    {
        if(Abs(mousePos.x - (int)chessBoard.squares[x][0].position.x - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.x = x;
            break;
        }
    }
    for(int y = 0; y < 8; y++)
    {
        if(Abs(mousePos.y - (int)chessBoard.squares[0][y].position.y - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.y = y;
            break;
        }
    }
    return closestSquare;
}

void grabPiece(ChessBoard* chessBoard, Vector2 closestSquare)
{
    if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.type != empty)
    {
        if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked == false)
        {
            printf("Picked peace of type %d\n", chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.type);
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked = true;
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
