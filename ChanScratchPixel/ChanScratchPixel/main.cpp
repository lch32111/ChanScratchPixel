#include <iostream>
#include <crtdbg.h>

#if _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif

#include "ChSPMath.h"

#define printVec3(s) std::cout << '(' << s.x << ", " << s.y << ", " << s.z << ')' << '\n';

int main()
{
	ChSP::Vec3<float> myVec;
	ChSP::Vec3<float> yourVec(1, 2, 3);
	
	myVec += yourVec;
	printVec3(myVec);

	myVec.normalize();
	printVec3(myVec);

	return 0;
}