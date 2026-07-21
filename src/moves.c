#include "moves.h"

ps_vector getValidWPawnMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    //Simple forward move 
    Position nextPosition = {grabbedPiece.piecePosition.x + 0, grabbedPiece.piecePosition.y - 1};
    if(isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //Long move
    nextPosition.x = grabbedPiece.piecePosition.x + 0;
    nextPosition.y = grabbedPiece.piecePosition.y - 2;
    Position previousPosition = nextPosition;
    previousPosition.y = grabbedPiece.piecePosition.y - 1;
    if(isPositionEmpty(chessBoard, grabbedPiece, previousPosition) 
    && isPositionEmpty(chessBoard, grabbedPiece, nextPosition) 
    && (!grabbedPiece.hasMoved)) 
    ps_append(validMoves, nextPosition);
    
    //Taking enemy piece left
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;

    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //Taking enemy piece right
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;

    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //if(!isInsideBoard(nextPosition))
    //ps_append(validMoves, nextPosition);

    return validMoves;
}

ps_vector getValidBPawnMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    //Simple forward move 
    Position nextPosition = {grabbedPiece.piecePosition.x + 0, grabbedPiece.piecePosition.y + 1};
    
    if(isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //Long move
    nextPosition.x = grabbedPiece.piecePosition.x + 0;
    nextPosition.y = grabbedPiece.piecePosition.y + 2;
    Position previousPosition = nextPosition;
    previousPosition.y = grabbedPiece.piecePosition.y + 1;

    if(isPositionEmpty(chessBoard, grabbedPiece, previousPosition) 
    && isPositionEmpty(chessBoard, grabbedPiece, nextPosition) 
    && (!grabbedPiece.hasMoved)) 
    ps_append(validMoves, nextPosition);
    
    //Taking enemy piece left
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;

    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //Taking enemy piece right
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;

    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //if(!isInsideBoard(nextPosition))
    //ps_append(validMoves, nextPosition);

    return validMoves;

}

ps_vector getValidKnightMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    //Top left move
    Position nextPosition = {grabbedPiece.piecePosition.x - 1, grabbedPiece.piecePosition.y - 2};
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    //Top right move
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y - 2;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
   
    //Left top move
    nextPosition.x = grabbedPiece.piecePosition.x - 2;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    //Left bottom move
    nextPosition.x = grabbedPiece.piecePosition.x - 2;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    //Bottom left move 
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 2;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    //Bottom right move 
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 2;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    //Right bottom move
    nextPosition.x = grabbedPiece.piecePosition.x + 2;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);

    //Right top move
    nextPosition.x = grabbedPiece.piecePosition.x + 2;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition) || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) ps_append(validMoves, nextPosition);
    
    return validMoves;
}

ps_vector getValidBishopMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    Position nextPosition;
    int xOffset = -1;
    int yOffset = -1;
    //Diagonal top left
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }
    
    xOffset = -1;
    yOffset = 1;
    //Diagonal bottom left
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }

    xOffset = 1;
    yOffset = 1;
    //Diagonal bottom right
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }

    xOffset = 1;
    yOffset = -1;
    //Diagonal bottom right
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }

    return validMoves;
}

ps_vector getValidRookMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    Position nextPosition;
    int xOffset = -1;
    int yOffset = 0;
    //Left move 
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
    }
    
    xOffset = 1;
    //Right move 
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
    }

    yOffset = 1;
    //Bottom move
    nextPosition.x = grabbedPiece.piecePosition.x;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.y += yOffset;
    }

    yOffset = -1;
    //Top move
    nextPosition.x = grabbedPiece.piecePosition.x;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.y += yOffset;
    }

    return validMoves;

}

ps_vector getValidQueenMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    Position nextPosition;
    int xOffset = -1;
    int yOffset = 0;
    //Left move 
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
    }
    
    xOffset = 1;
    //Right move 
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
    }

    yOffset = 1;
    //Bottom move
    nextPosition.x = grabbedPiece.piecePosition.x;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.y += yOffset;
    }

    yOffset = -1;
    //Top move
    nextPosition.x = grabbedPiece.piecePosition.x;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.y += yOffset;
    }

    xOffset = -1;
    yOffset = -1;
    //Diagonal top left
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }
    
    xOffset = -1;
    yOffset = 1;
    //Diagonal bottom left
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }

    xOffset = 1;
    yOffset = 1;
    //Diagonal bottom right
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }

    xOffset = 1;
    yOffset = -1;
    //Diagonal bottom right
    nextPosition.x = grabbedPiece.piecePosition.x + xOffset;
    nextPosition.y = grabbedPiece.piecePosition.y + yOffset;
    while(isMoveInsideBoard(nextPosition))
    {
        if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition))
        {
            ps_append(validMoves, nextPosition);
            break;
        }
        else if(isPositionFriendly(chessBoard, grabbedPiece, nextPosition)) break;
        
        ps_append(validMoves, nextPosition);
        nextPosition.x += xOffset;
        nextPosition.y += yOffset;
    }
    
    return validMoves;
}

ps_vector getValidKingMoves(ChessBoard chessBoard, GrabbedPiece grabbedPiece)
{
    ps_vector validMoves;
    ps_init(validMoves);
    
    Position nextPosition;
    //Left move 
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 0;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Diagonal left top
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Top
    nextPosition.x = grabbedPiece.piecePosition.x - 0;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Diagonal top right
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y - 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Right
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 0;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Diagonal right down
    nextPosition.x = grabbedPiece.piecePosition.x + 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Down
    nextPosition.x = grabbedPiece.piecePosition.x + 0;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    //Diagonal down left
    nextPosition.x = grabbedPiece.piecePosition.x - 1;
    nextPosition.y = grabbedPiece.piecePosition.y + 1;
    
    if(isPositionEnemy(chessBoard, grabbedPiece, nextPosition)
    || isPositionEmpty(chessBoard, grabbedPiece, nextPosition)) 
    ps_append(validMoves, nextPosition);
    
    return validMoves;
}

int isMoveInsideBoard(Position position)
{
    if((position.x >= 0 && position.x < 8) && (position.y >= 0 && position.y < 8)) return 1;
    else return 0;
}

int isPositionFriendly(ChessBoard chessBoard,GrabbedPiece grabbedPiece, Position position)
{
    if(isMoveInsideBoard(position))
    {
        if(chessBoard.squares[position.x][position.y].piece.color == grabbedPiece.pieceColor) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else return 0;
}

int isPositionEnemy(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position)
{
    if(isMoveInsideBoard(position))
    {
        if(grabbedPiece.pieceColor == white)
        {
            if(chessBoard.squares[position.x][position.y].piece.color == black) 
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if(chessBoard.squares[position.x][position.y].piece.color == white) 
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else return 0;
}

int isPositionEmpty(ChessBoard chessBoard, GrabbedPiece grabbedPiece, Position position)
{
    
    if(isMoveInsideBoard(position))
    {
        if(chessBoard.squares[position.x][position.y].piece.type == emptyType)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
    }
    else return 0;
}
