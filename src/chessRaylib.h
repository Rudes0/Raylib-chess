#ifndef CHESS_RAYLIB_H
#define CHESS_RAYLIB_H
#include "engine.h"


typedef struct {
    Texture2D chessBoardTexture;
    Texture2D chessPieces[pieceColorCount][pieceTypeCount];
}RaylibChessBoard;

void loadChessBoard(RaylibChessBoard* raylibChessBoard); // Initialization of all the textures of chess board
void drawChessBoard(RaylibChessBoard raylibChessBoard, ChessBoard chessBoard, int mouseX, int mouseY); // update textures of chess board
void unloadChessBoard(RaylibChessBoard* raylibChessBoard);
#endif //CHESS_RAYLIB_H
