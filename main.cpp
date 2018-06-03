#include "scene.h"
#include <ctime>
#include <cstdlib>

int main()
{
	srand((unsigned int)time(0));
	Scene* scene = new Scene();
	scene->SetInput("./input/scene.txt");
	scene->SetOutput("./output/piceture.png");
	scene->GenerateScene();
	scene->Rendering();
	//scene->Show();
	return 0;
}
