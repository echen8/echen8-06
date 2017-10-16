#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node * next; };

void print_list( struct node * front ) {

  if ( front ) {
  
    while ( front->next ) {
      printf( "[%d]->", front->i );
      front = front->next;
    }

  }
  printf( "end\n" );
  
}

struct node * insert_front( struct node * front, int x ) {
  
  struct node * new = ( struct node * )calloc( 1, sizeof( struct node ) );
  
  new->i = x;
  new->next = front;
  
  return new;
  
}

struct node * free_list( struct node * front ) {

  struct node * n = front;
  struct node * temp;
  
  while ( front ) {
    temp = front;
    front = front->next;
    free( temp );
  }

  return n;
  
}

int main() {
  printf( "\n========================\n" );
  
  int x = 3;

  printf( "\nTesting insert_front()\n" );
  struct node * n = ( struct node * )calloc( x, sizeof( struct node ) );
  
  printf( "Initial node:\t" );
  print_list( n );

  int a = 0;
  for ( ; a < x; a++ ) {
    n = insert_front( n, a );
    printf( "After add#%d:\t", a+1 );
    print_list( n );
  }

  printf( "\nTesting print_list()\n" );
  print_list( n );

  printf( "\nTesting free_list()\n" );

  printf( "Before freeing: %p\n", n );
  free_list( n );
  //print_list( n );
  printf( "After freeing: %p\n", n );
  // Same pointer address before and after, but segmentation fault occurs if I print_list it???

  printf( "\n========================\n" );
  return 0;
}
