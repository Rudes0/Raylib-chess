#include "game.h"
#include "engine.h"

void initGame(Game* game)
{
    game->chessBoard = initChessBoard();
	game->gameState = initGameState();
}
