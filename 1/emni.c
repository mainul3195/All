#include<stdio.h>
void cyclicSwap(int &a, int &b, int &c)
{
   b^=c^=b^=c;
   a^=b^=a^=b;
   return;
}
int main()
{
   int x = 4, y = 6, z = 1;
   cyclicSwap(x, y, z);
   printf("%d %d %d\n", x,y,z);
   return 0;
}