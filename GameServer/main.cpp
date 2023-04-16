#include "pch.h"
#include "LibraryHeader.h"
#include "ServerApp.h"

int main() {


	uptr<ServerApp> serverApplication = make_unique<ServerApp>();

	serverApplication->dataSystem->LoadJsonData();

	serverApplication->StartSocketServer();
	serverApplication->StartGameSystem();
	serverApplication->JoinThread();

	return 0;
}