#ifndef GAME
#define GAME

#include "engine.h"
#include "chessRaylib.h"


typedef struct {
	GameState gameState;
	RaylibChessBoard raylibChessBoard;
	ChessBoard chessBoard;
    GrabbedPiece grabbedPieceData;
}Game;


void initGame(Game* game);
#endif //GAME
