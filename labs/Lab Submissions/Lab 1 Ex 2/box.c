/* box.c
** computes surface area of a and length of diagonal between two vertices of the box that are furtherest apart
** Deepak Buddha
** group31
*/

#include<stdio.h>
#include<math.h>

int compute_surface_area(int, int, int);
double  compute_diagonal(int, int, int);

int main(void) {

	int length,
	    width,
		height,
		sarea;
	
	double diagonal;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	sarea = compute_surface_area(length, width, height);

	diagonal = compute_diagonal(length, width, height);

	printf("Surface area = %d\n", sarea);
	printf("Diagonal = %.2f\n", diagonal);

	return 0;
}

int compute_surface_area(int l, int w, int h) {

	int res;

	res = 2 * ( ( l * w) + (w * h) + (h * l) ) ;

	return res;
}

double compute_diagonal(int l, int w, int h) {

	double res;

	res = sqrt(pow(l, 2) + pow(w, 2) + pow(h, 2)) ;

	return res;
}






