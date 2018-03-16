typedef int ElementType;
#define SpaceSize 100


#ifndef _Cursor_H
#define _Cursor_H

typedef int List;
typedef int Position;

void InitializeCursorSpace( void );
List MakeEmpty( List L );
void Insert( ElementType X, List L );
Position Find( ElementType X, List L );
Position Header( List L );
Position First( List L );

#endif  /* _Cursor_H */
