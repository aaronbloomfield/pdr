int mult(int x,int y) {
  if ( y == 0 )
    return 0;
  else
    return x+mult(x,y-1);
}
