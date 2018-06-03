#include "photonmap.h"

Photonmap::Photonmap(Scene* _scene)
{
    scene = _scene;
    lighthead = NULL;
	//To be continue...
}

void Photonmap::AddLight(Light* _light)
{
    _light->SetNext(lighthead);
    lighthead = _light;
}
