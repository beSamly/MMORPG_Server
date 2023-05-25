#include "pch.h"
#include "LibraryHeader.h"
#include "ServerApp.h"
#include "MinidumpHelp.h"

int main() {

	MinidumpHelp dbgDump;
	dbgDump.install_self_mini_dump();

	uptr<ServerApp> serverApplication = make_unique<ServerApp>();
	serverApplication->InitSystems();
	serverApplication->StartSystems();
	return 0;
}