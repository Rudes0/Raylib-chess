#ifndef ENGINE_H
#define ENGINE_H
#include "raylib.h"

#define SQUARE_SIZE 117
#define LEFT_BOARD_EDGE 483
#define RIGHT_BOARD_EDGE 70
#define TOP_BOARD_EDGE 1419
#define BOTTOM_BOARD_EDGE 1008
typedef enum{
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king,
    pieceTypeCount,
    emptyType
}PieceType;

typedef enum{
    white,
    black,
    pieceColorCount,
    noColor
}PieceColor;

typedef struct {
    int x;
    int y;
}Position;

typedef struct{
    PieceType type;
    PieceColor color;
    bool hasMoved;
    bool isPicked;
}Piece;

typedef struct {
    Piece piece;
    Position position;
}Square;

#include <stdlib.h>
typedef struct {
	Position* data;
	int capacity;
	int lenght;
}ps_vector;

typedef struct {
    Position piecePosition;
    PieceType pieceType;
    PieceColor pieceColor;
    ps_vector possibleMoves;
    int hasMoved;
}GrabbedPiece;

typedef struct {
    Square squares[8][8];
}ChessBoard; 

typedef struct{
    PieceColor currentPlayerColor;
    float whiteTime;
    float blackTime;
}GameState;

// macros for ps_vector
#define ps_init(ps) do{\
	ps.capacity = 4;\
	ps.lenght = 0;\
	ps.data = malloc(sizeof(void *) * ps.capacity);\
}while(0)\

#define ps_append(ps, value) do{\
	if(ps.lenght >= ps.capacity) {\
		if(ps.capacity == 0)\
			ps.capacity = 4;\
		else\
			ps.capacity *= 2;\
		Position* newData = realloc(ps.data, ps.capacity * sizeof(*ps.data));\
		if(newData != NULL){\
            (ps).data = newData;\
        }\
    }\
	ps.data[ps.lenght++] = value;\
}while(0)\

#define ps_free(ps) do{\
	free(ps.data);\
    ps.data = NULL;\
    ps.capacity = 0;\
    ps.lenght = 0;\
}while(0)\

GameState initGameState(void);
ChessBoard initChessBoard(void);
void gameUpdate(ChessBoard* chessBoardData, GrabbedPiece* grabbedPieceData);
int isMouseInsideBoard(Vector2 mousePos);
void grabPiece(ChessBoard* chessBoard, Position closestSquare, GrabbedPiece* grabbedPieceData);
void relasePiece(ChessBoard* chessBoard, Position closestSquare, Position piecePosition);
Position checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos);
int getPieceType(ChessBoard chessBoard, Position position);
int getPieceColor(ChessBoard chessBoard, Position postion);
int getPieceHasMoved(ChessBoard chessBoard, Position position);
Piece choosePiece(PieceType type);
int isValidMove(ChessBoard chessBoard, Position closestSquare, GrabbedPiece grabbedPiece);
int isMoveInsideBoard(Position position);
int isPositionFriendly(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);
int isPositionEnemy(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);
int isPositionEmpty(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);
float Abs(float val);

#endif // ENGINE_H
