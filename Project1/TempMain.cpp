#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
	float Result = (float)((double)(End.QuadPart - Start.QuadPart) / (double)PerfCounterFreq);
	printf("%e", Result);
	fgetc(stdin);

}