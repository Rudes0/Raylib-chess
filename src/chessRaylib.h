#ifndef CHESS_RAYLIB_H
#define CHESS_RAYLIB_H
#include "engine.h"


typedef struct {
    ChessBoard chessBoardData;
    Texture2D chessBoardTexture;
    Texture2D chessPieces[pieceColorCount][pieceTypeCount];
}RaylibChessBoard;

void loadChessBoard(RaylibChessBoard* raylibChessBoard); // Initialization of all the textures of chess board
void drawChessBoard(RaylibChessBoard raylibChessBoard); // update textures of chess board
void unloadChessBoard(RaylibChessBoard* raylibChessBoard);
void drawsome(int a);
#endif //CHESS_RAYLIB_H
