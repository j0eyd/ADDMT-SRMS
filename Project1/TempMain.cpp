#include "LazyHeader.h"

int main(int argc, char* argv[])
{
	// PerfCounter: most exact time measurement on windows
	LARGE_INTEGER CounterFreq;
	QueryPerformanceFrequency(&CounterFreq);
	int64_t PerfCounterFreq = CounterFreq.QuadPart;
	LARGE_INTEGER Start;
	QueryPerformanceCounter(&Start);
	fgetc(stdin);
	LARGE_INTEGER End;
	QueryPerformanceCounter(&End);
	real32 Result = (real32)((real64)(End.QuadPart - Start.QuadPart) / (real64)PerfCounterFreq);
	printf("%e", Result);
	fgetc(stdin);

}