#include "Lacy2D.h"

class ServerApp : public Lacy2D::Application
{
public:
	ServerApp()
	{

	}

	~ServerApp()
	{

	}
};

Lacy2D::Application* Lacy2D::CreateApplication()
{
	return new ServerApp();
}