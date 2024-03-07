#pragma once

#include "Version.h"
#include "Application.h"
#include "Log.h"

#ifdef LACY2D_PLATFORM_WINDOWS

extern Lacy2D::Application* Lacy2D::CreateApplication();

int main(int argc, char** argv)
{
	Lacy2D::Log::Init();
	LACY2D_CORE_WARN("Initialized Log!");
	LACY2D_SERVER_INFO("Initialized Log!");
	LACY2D_INFO("Initialized Log!");

	auto app = Lacy2D::CreateApplication();
	app->Run();
	delete app;
}

#endif