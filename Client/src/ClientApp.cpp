#include "Lacy2D.h"

class ClientApp : public Lacy2D::Application
{
public:
	ClientApp()
	{
		
	}

	~ClientApp()
	{

	}
};

Lacy2D::Application* Lacy2D::CreateApplication()
{
	return new ClientApp();
}