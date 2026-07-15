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
}GrabbedPiece;

typedef struct {
    Square squares[8][8];
}ChessBoard; 

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
		ps.data = realloc(ps.data, ps.capacity * sizeof(*ps.data));\
		}\
	ps.data[ps.lenght++] = value;\
}while(0)\

#define ps_free(ps) do{\
	free(ps.data);\
}while(0)\

ChessBoard initChessBoard(void);
void gameUpdate(ChessBoard* chessBoardData, GrabbedPiece* grabbedPieceData);
void grabPiece(ChessBoard* chessBoard, Position closestSquare, GrabbedPiece* grabbedPieceData);
void relasePiece(ChessBoard* chessBoard, Position closestSquare, Position piecePosition);
Position checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos);
int getPieceType(ChessBoard chessBoard, Position position);
int getPieceColor(ChessBoard chessBoard, Position postion);
Piece choosePiece(PieceType type);
ps_vector getValidMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
int isValidMove(ChessBoard chessBoard, Position closestSquare, GrabbedPiece grabbedPiece);
int isInsideBoard(Position position);
int isPositionEmpty(ChessBoard chessBoard, Position position);
int Abs(int val);

#endif // ENGINE_H
