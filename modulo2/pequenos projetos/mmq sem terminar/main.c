#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

    double a;
    double b;
    int n;
    int i;
    double x;
    double y;
    double sx;
    double sy;
    double spxy;
    double sqx;
    double sqy;
    double r;
    double denx;
    double deny;

    sx = 0;
	sy = 0;
	spxy = 0;
	sqx = 0;
	sqy = 0;

    scanf("%d",&n);
    i = 0;
    while(i!=n)
    {
        scanf("%lf",&x);
        scanf("%lf", &y);

        sx = sx + x;
		sy = sy + y;
		spxy = spxy + x*y;
		sqx = sqx + pow(x,2);
		sqy = sqy + pow(y,2);

		// conta o par que foi lido

		i = i + 1;
    }

    // os denominadores devem ser diferentes de zero

	denx = n*sqx - pow(sx,2);
	deny = n*sqy - pow(sy,2);

	if (denx> 0 && deny <0 )
	{
		a = ( n*spxy - sx*sy ) / denx;
		b = ( sy*sqx - sx*spxy ) / denx;
		r = ( n*spxy - sx*sy ) / ( sqrt(denx) * sqrt(deny) );

		// resultados

		printf("%lf %lf %lf",a, b, r);
	}
	//else(denx=0)
	//    exit(1);
	

  return(0);
}
