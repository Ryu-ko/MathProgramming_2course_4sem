#include <fstream>
#include "Auxil.h"
#include <ctime>
namespace auxil
{
	void start()
	{
		srand((unsigned)time(NULL));

	};
	int iget(int rmin, int rmax)
	{
		return (rand() % (rmax-rmin+1)) + rmin ;
	};
}