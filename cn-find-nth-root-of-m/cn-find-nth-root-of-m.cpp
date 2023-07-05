int NthRoot(int n, int m) {
  // Write your code here.
  if (m == 1 || n == 1)
  return m;
  int l=2, h=m-1, md;

  while(l<=h)
  {
    md=l+(h-l)/2;
    if (pow(md,n) == m)
    return md;
    else if (pow(md,n) > m)
    h = md-1;
    else
    l = md+1;
  }
  return -1;
}