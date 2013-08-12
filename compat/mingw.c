#include <winsock.h>
#include <windows.h>
#include <stdio.h>

#include "kovan/kovan_compat.hpp"

// Derived from: https://github.com/jamescoxon/dl-fldigi/blob/master/src/compat/mingw.c
INITIALIZER(wsa_init)
{
	static int s_init = 0;
	if (s_init) return;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa)) {
		fprintf(stderr, "ERROR: WSAStartup failed. Code: %d\n", WSAGetLastError());
		fprintf(stderr, "ERROR: Network communication will not work.\n");
	}

	atexit((void(*)(void)) WSACleanup);
	s_init = 1;
}