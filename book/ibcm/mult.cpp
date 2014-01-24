int mult(int x,int y) {
  if ( y == 0 )
    return 0;
  else
    return x+mult(x,y-1);
}

int main(void) {
  int x, y;
  cin >> x;
  cin >> y;
  cout << mult(y,x) << endl;
}
