#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"

#define SQUARE_SIZE 117

typedef enum{
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king,
    pieceTypeCount,
    empty
}PieceType;

typedef enum{
    white,
    black,
    pieceColorCount
}PieceColor;

typedef struct{
    PieceType type;
    PieceColor color;
    bool hasMoved; 
}Piece;

typedef struct {
    Piece piece;
    Vector2 position;
}Square;

typedef struct {
    Square squares[8][8];
    
}ChessBoard; 


ChessBoard initChessBoard(void);   


#endif // ENGINE_H