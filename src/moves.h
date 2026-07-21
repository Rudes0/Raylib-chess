#ifndef MOVES
#define MOVES

#include "engine.h"


ps_vector getValidMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidWPawnMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidBPawnMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidKnightMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidBishopMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidRookMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidQueenMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
ps_vector getValidKingMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece);
int isMoveInsideBoard(Position position);
int isPositionFriendly(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);
int isPositionEnemy(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);
int isPositionEmpty(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position);

#endif // MOVES
