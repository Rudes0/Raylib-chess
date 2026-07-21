#include "engine.h"
#include "moves.h"
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
    .type = emptyType,
    .color = noColor,
    .hasMoved = false,
    .isPicked = false
};

GameState initGameState(void)
{
    GameState gameState;
    float playerTime = 5;
    gameState.currentPlayerColor = white;
    gameState.whiteTime = playerTime;
    gameState.blackTime = playerTime;
    return gameState;
}

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
            chessBoard.squares[x][y].piece = emptyPiece;
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

void gameUpdate(ChessBoard* chessBoardData, GameState* gameState, GrabbedPiece* grabbedPieceData)
{
    Vector2 mousePostion;
    mousePostion.x = GetMouseX();
    mousePostion.y = GetMouseY();
    Position closestSquare = checkClosestToMouse(*chessBoardData, mousePostion);
    if(isMouseInsideBoard(mousePostion))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
        printf("mouse pos x = %f, y = %f\n", mousePostion.x, mousePostion.y);
        grabPiece(chessBoardData, closestSquare, grabbedPieceData);
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            printf("Square piece type is %d\n", chessBoardData->squares[closestSquare.x][closestSquare.y].piece.type); 
            printf("Relased piece type is %d\n", grabbedPieceData->pieceType);
            if(grabbedPieceData->pieceType != emptyType)
            {
                printf("Relasing not empty piece on square x %d, y %d\n", closestSquare.x, closestSquare.y);
                if(!isMouseInsideBoard(mousePostion)) relasePiece(chessBoardData, grabbedPieceData->piecePosition, grabbedPieceData->piecePosition);
                else if(isValidMove(*chessBoardData, *gameState, closestSquare, *grabbedPieceData))
                {
                    relasePiece(chessBoardData, closestSquare, grabbedPieceData->piecePosition);
                    changePlayer(gameState);
                }
                else
                {
                    relasePiece(chessBoardData, grabbedPieceData->piecePosition, grabbedPieceData->piecePosition);
                }
            }
            else
            {
                printf("Grabbing empty piece on square x %d y %d\n", closestSquare.x, closestSquare.y); 
            }
        ps_free(grabbedPieceData->possibleMoves);
        }
    }
    else
    {

    }
}

void changePlayer(GameState *gameState)
{
    if(gameState->currentPlayerColor == white)
    {
        gameState->currentPlayerColor = black;
    }
    else
    {
        gameState->currentPlayerColor = white;
    }
}

Position checkClosestToMouse(ChessBoard chessBoard, Vector2 mousePos)
{
    Position closestSquare = {0, 0};
    for(int x = 0; x < 8; x++)
    {
        if(Abs(mousePos.x - chessBoard.squares[x][0].position.x - ((float)SQUARE_SIZE / 2 ))<= (float)SQUARE_SIZE / 2)
        {
            closestSquare.x = x;
            break;
        }
    }
    for(int y = 0; y < 8; y++)
    {
        if(Abs(mousePos.y - chessBoard.squares[0][y].position.y - ((float)SQUARE_SIZE / 2)) <= (float)SQUARE_SIZE / 2)
        {
            closestSquare.y = y;
            break;
        }
    }
    return closestSquare;
}

int isMouseInsideBoard(Vector2 mousePos)
{
    if((mousePos.x > LEFT_BOARD_EDGE || mousePos.x < RIGHT_BOARD_EDGE) && (mousePos.y > TOP_BOARD_EDGE || mousePos.y < BOTTOM_BOARD_EDGE)) return 1; 
    return 0;
}

void grabPiece(ChessBoard* chessBoard, Position closestSquare, GrabbedPiece* grabbedPieceData)
{
    //if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.type != emptyType)
    //{
        if(chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked == false)
        {
            grabbedPieceData->piecePosition = closestSquare;
            grabbedPieceData->pieceColor = getPieceColor(*chessBoard, closestSquare);
            grabbedPieceData->pieceType = getPieceType(*chessBoard, closestSquare);
            grabbedPieceData->hasMoved = getPieceHasMoved(*chessBoard, closestSquare);
//            printf("grab piece type %d\n", grabbedPieceData->pieceType);
            grabbedPieceData->possibleMoves = getValidMoves(*chessBoard, *grabbedPieceData);
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.isPicked = true;
        }
    //}
}

void relasePiece(ChessBoard* chessBoard, Position closestSquare, Position piecePosition)
{
    if(chessBoard->squares[piecePosition.x][piecePosition.y].piece.type != emptyType)
    {
        if(chessBoard->squares[piecePosition.x][piecePosition.y].piece.isPicked == true && IsMouseButtonUp(MOUSE_LEFT_BUTTON))
        {
            Piece tempPiece = chessBoard->squares[piecePosition.x][piecePosition.y].piece;
            chessBoard->squares[piecePosition.x][piecePosition.y].piece = emptyPiece; 
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece = tempPiece;
            chessBoard->squares[(int)closestSquare.x][(int)closestSquare.y].piece.hasMoved = true;
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

int getPieceHasMoved(ChessBoard chessBoard, Position position)
{
    return chessBoard.squares[position.x][position.y].piece.hasMoved;
}

int isValidMove(ChessBoard chessBoard, GameState gameState, Position closestSquare, GrabbedPiece grabbedPiece)
{
    if(gameState.currentPlayerColor != grabbedPiece.pieceColor) return 0;
    if(grabbedPiece.possibleMoves.data == NULL) return 0;
    for(int i = 0; i < grabbedPiece.possibleMoves.lenght; ++i)
    {
        if(grabbedPiece.possibleMoves.data[i].x == closestSquare.x && grabbedPiece.possibleMoves.data[i].y == closestSquare.y) return 1;
    }
    return 0;
}

/*
int isValidMoveWhitePawn(ChessBoard chessBoard, Position closestSquare, GrabbedPiece grabbedPiece)
{
    for(int i = 0; i < grabbedPiece.possibleMoves.lenght; ++i)
    {
        //check for to 2 move
        if(grabbedPiece.possibleMoves.data[i].x == -1 && (grabbedPiece.possibleMoves.data[i].y == -1 || grabbedPiece.possibleMoves.data[i].y == 1))
        {
//check if there is a black piece
            if(chessBoard.squares
        }

        if(grabbedPiece.possibleMoves.data[i].x == closestSquare.x && grabbedPiece.possibleMoves.data[i].y == closestSquare.y) return 1;
    }
    return 0;

}
*/
ps_vector getValidMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    if(grabbedPiece.pieceType == pawn && grabbedPiece.pieceColor == white) return getValidWPawnMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == pawn && grabbedPiece.pieceColor == black) return getValidBPawnMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == knight) return getValidKnightMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == bishop) return getValidBishopMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == rook) return getValidRookMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == queen) return getValidQueenMoves(chessBoard, grabbedPiece);
    if(grabbedPiece.pieceType == king) return getValidKingMoves(chessBoard, grabbedPiece);
    ps_vector validMoves;
    ps_init(validMoves);
    return validMoves;
}


float Abs(float val)
{
    if(val == 0.0) return 0.0;
    if(val > 0.0) return val;
    if(val < 0.0) return -val;
    return 0.0;
}
