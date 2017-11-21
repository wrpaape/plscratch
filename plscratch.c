#include "plcdemos.h"
#define NSIZE    101


static const PLFLT xmin = 0.0;
static const PLFLT xmax = 1.0;
static const PLFLT ymin = 0.0;
static const PLFLT ymax = 100.0;
static const PLINT just = 0;
static const PLINT axis = 0;

int
main(int argc,
     char *argv[])
{
	PLFLT x[NSIZE];
	PLFLT y[NSIZE];
	int   i;

	// Prepare data to be plotted.
	for ( i = 0; i < NSIZE; i++ ) {
		x[i] = (PLFLT) ( i ) / (PLFLT) ( NSIZE - 1 );
		y[i] = ymax * x[i] * x[i];
	}

	// Parse and process command line arguments
	plparseopts( &argc, argv, PL_PARSE_FULL );

	// Initialize plplot
	plinit();

	// Create a labelled box to hold the plot.
	plenv(xmin, xmax,
	      ymin, ymax,
	      just, axis);

	pllab("x",
	      "y=100 x#u2#d",
	      "Simple PLplot demo of a 2D line plot");

	// Plot the data that was prepared above.
	plline(NSIZE, x, y);

	PLFLT point_x = (xmax - xmin) / 2.0;
	PLFLT point_y = (ymax - ymin) / 2.0;

	plstring(1,
		 &point_x, &point_y,
		 "o");

	// Close PLplot library
	plend();

	return 0;
}
