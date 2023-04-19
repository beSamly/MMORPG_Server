#include "pch.h"
#include "LibraryHeader.h"
#include "ServerApp.h"

int main() {
	uptr<ServerApp> serverApplication = make_unique<ServerApp>();
	serverApplication->InitSystems();
	serverApplication->StartSystems();
	return 0;
}