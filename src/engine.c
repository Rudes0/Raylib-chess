#include "engine.h"
#include "chessRaylib.h"
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

Piece emptyPiece = {
    .type = empty,
    .color = noColor,
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

void gameUpdate(ChessBoard* chessBoardData, GrabbedPiece* grabbedPieceData)
{
    Vector2 mousePostion;
    mousePostion.x = GetMouseX();
    mousePostion.y = GetMouseY();
    Position closestSquare = checkClosestToMouse(*chessBoardData, mousePostion);
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        grabPiece(chessBoardData, closestSquare, grabbedPieceData);
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        if(isValidMove(*chessBoardData, closestSquare, *grabbedPieceData))
        {
            relasePiece(chessBoardData, closestSquare, grabbedPieceData->piecePosition);
            ps_free(grabbedPieceData->possibleMoves);
        }
        else
        {
            relasePiece(chessBoardData, grabbedPieceData->piecePosition, grabbedPieceData->piecePosition);
            ps_free(grabbedPieceData->possibleMoves);
        }
    }
}

Position checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos)
{
    Position closestSquare = {0, 0};
    for(int x = 0; x < 8; x++)
    {
        if(Abs((int)mousePos.x - (int)chessBoard.squares[x][0].position.x - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.x = x;
            break;
        }
    }
    for(int y = 0; y < 8; y++)
    {
        if(Abs((int)mousePos.y - (int)chessBoard.squares[0][y].position.y - (int)(SQUARE_SIZE / 2)) < SQUARE_SIZE / 2)
        {
            closestSquare.y = y;
            break;
        }
    }
    return closestSquare;
}

void grabPiece(ChessBoard* chessBoard, Position closestSquare, GrabbedPiece* grabbedPieceData)
{
    if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.type != empty)
    {
        if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked == false)
        {
            grabbedPieceData->piecePosition = closestSquare;
            grabbedPieceData->pieceColor = getPieceColor(*chessBoard, closestSquare);
            grabbedPieceData->pieceType = getPieceType(*chessBoard, closestSquare);
            grabbedPieceData->possibleMoves = getValidMoves(*chessBoard, *grabbedPieceData);
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked = true;
        }
    }
}

void relasePiece(ChessBoard* chessBoard, Position closestSquare, Position piecePosition)
{
    if(chessBoard->squares[piecePosition.x][piecePosition.y].piece.type != empty)
    {
        if(chessBoard->squares[piecePosition.x][piecePosition.y].piece.isPicked == true && IsMouseButtonUp(MOUSE_LEFT_BUTTON))
        {
            Piece tempPiece = chessBoard->squares[piecePosition.x][piecePosition.y].piece;
            chessBoard->squares[piecePosition.x][piecePosition.y].piece = emptyPiece; 
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece = tempPiece; 
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked = false;
        }
    }
}

int getPieceType(ChessBoard chessBoard, Position postion)
{
    return chessBoard.squares[postion.x][postion.y].piece.type;
}

int getPieceColor(ChessBoard chessBoard, Position postion)
{
    return chessBoard.squares[postion.x][postion.y].piece.color;
}

int isValidMove(ChessBoard chessBoard, Position closestSquare, GrabbedPiece grabbedPiece)
{
    for(int i = 0; i < grabbedPiece.possibleMoves.lenght; ++i)
    {
        if(grabbedPiece.possibleMoves.data[i].x == closestSquare.x && grabbedPiece.possibleMoves.data[i].y == closestSquare.y) return 1;
    }
    return 0;
}

Position wPawnMoves[] =
{
    {0, -1},
    {-1, -1},
    {1, -1},
    {0, -2}
};

ps_vector getValidMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    int dirCount = sizeof(wPawnMoves) / sizeof(wPawnMoves[0]);
    for(int i = 0; i < dirCount; i++)
    {
        Position nextPosition = {grabbedPiece.piecePosition.x + wPawnMoves[i].x, grabbedPiece.piecePosition.y + wPawnMoves[i].y};
        if(!isInsideBoard(nextPosition)) continue;
        if(!isPositionEmpty(chessBoard, nextPosition)) continue;
        ps_append(validMoves,nextPosition);
    }
    return validMoves;
}

int isInsideBoard(Position position)
{
    if((position.x >= 0 && position.x < 8) && (position.y >= 0 && position.y < 8)) return 1;
    else return 0;
}

int isPositionEmpty(ChessBoard chessBoard, Position position)
{
    if(chessBoard.squares[position.x][position.y].piece.type == empty) return 1;
    else return 0;
}


int Abs(int val)
{
    if(val == 0) return 0;
    if(val > 0) return val;
    if(val < 0) return -val;
    return 0;
}
