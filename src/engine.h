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
    pieceColorCount,
    noColor
}PieceColor;

typedef struct{
    PieceType type;
    PieceColor color;
    bool hasMoved;
    bool isPicked;
}Piece;

typedef struct {
    Piece piece;
    Vector2 position;
}Square;

typedef struct {
    Square squares[8][8];
}ChessBoard; 

ChessBoard initChessBoard(void);

void gameUpdate(ChessBoard* board);
void grabPiece(ChessBoard* chessBoard, Vector2 closestSquare);
void relasePiece(ChessBoard* chessBoard, Vector2 closestSquare, int x, int y);
Vector2 checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos);
Piece choosePiece(PieceType type);
int Abs(int val);

#endif // ENGINE_H
