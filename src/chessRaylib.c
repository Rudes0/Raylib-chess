#include "chessRaylib.h"
#include <stdio.h>

void loadChessBoard(RaylibChessBoard* raylibChessBoard)
{
    Image chessBoardImage = LoadImage("assets/mychessboard.png");
    raylibChessBoard->chessBoardTexture = LoadTextureFromImage(chessBoardImage);
    UnloadImage(chessBoardImage);
    const char* piecePaths[pieceColorCount][pieceTypeCount] = {
        {
        "assets/white-pawn.png",
        "assets/white-knight.png",
        "assets/white-bishop.png",
        "assets/white-rook.png",
        "assets/white-queen.png",
        "assets/white-king.png"
        },
        {
        "assets/black-pawn.png",
        "assets/black-knight.png",
        "assets/black-bishop.png",
        "assets/black-rook.png",
        "assets/black-queen.png",
        "assets/black-king.png"
        }};
    for(int color = 0; color < pieceColorCount; color++)
    {
        for(int piece = 0; piece < pieceTypeCount; piece++)
        {
            Image chessPieceImage = LoadImage(piecePaths[color][piece]);
            raylibChessBoard->chessPieces[color][piece] = LoadTextureFromImage(chessPieceImage);
            UnloadImage(chessPieceImage);
        }
    }
    raylibChessBoard->chessBoardData = initChessBoard();
}

void drawChessBoard(RaylibChessBoard raylibChessBoard, int mouseX, int mouseY)
{
    DrawTexture(raylibChessBoard.chessBoardTexture, (1980 - 1080 - 71)/2, 0, WHITE);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            switch(raylibChessBoard.chessBoardData.squares[i][j].piece.type)
            {
                case empty:
                    break;
                case pawn:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][pawn], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][pawn], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][pawn], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][pawn], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                case knight:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][knight], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][knight], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][knight], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][knight], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                case bishop:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][bishop], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][bishop], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][bishop], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][bishop], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                case rook:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][rook], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][rook], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][rook], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][rook], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                case queen:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][queen], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][queen], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][queen], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][queen], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                case king:
                    if (raylibChessBoard.chessBoardData.squares[i][j].piece.color == white)
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][king], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[white][king], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    else
                    {
                        if(raylibChessBoard.chessBoardData.squares[i][j].piece.isPicked == true)
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][king], mouseX, mouseY, WHITE);
                        }
                        else
                        {
                            DrawTexture(raylibChessBoard.chessPieces[black][king], raylibChessBoard.chessBoardData.squares[i][j].position.x, raylibChessBoard.chessBoardData.squares[i][j].position.y , WHITE);
                        }
                    }
                    break;
                default:
                break;
            }
        }
    }
}

void unloadChessBoard(RaylibChessBoard* raylibChessBoard)
{
    UnloadTexture(raylibChessBoard->chessBoardTexture);
    for(int color = 0; color < pieceColorCount; color++)
    {
        for(int piece = 0; piece < pieceTypeCount; piece++)
        {
            UnloadTexture(raylibChessBoard->chessPieces[color][piece]);
        }
    }
}
