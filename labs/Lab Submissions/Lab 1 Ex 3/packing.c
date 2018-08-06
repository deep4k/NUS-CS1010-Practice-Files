/* packing.c
** computes maximum number of possible slabs that could be packed into the tray
** Deepak Buddha
** group31
*/

#include<stdio.h>

int compute_max_slabs(int, int, int, int);

int main(void) {

	int trayH,
	    slabH,
		trayL,
		slabL, // heights & lengths of trays and slabs
		ans;   

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayH, &trayL);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabH, &slabL);

	ans = compute_max_slabs(trayL, trayH, slabL, slabH);

	printf("Maximum number of slabs = %d\n", ans);

	return 0;
}

int compute_max_slabs(int tL, int tH, int sL, int sH){

	int res,
	    ansH,
		ansV; // answers considering horizonal and Vertical position 

		ansH = (tH / sH) * (tL / sL);

		ansV = (tH / sL) * (tL / sH);

		if (ansH > ansV) {

			res = ansH;
		}

		else { 
			res = ansV;
		}

		return res;
}




