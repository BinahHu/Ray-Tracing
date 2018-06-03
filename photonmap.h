#ifndef PHOTONMAP_H
#define PHOTONMAP_H
#include "typdef.h"
#include "light.h"

class Scene;
class Photonmap
{
	public:
		Photonmap(Scene* scene);
		void AddLight(Light* light);
	private:
		Scene* scene;
		Light* lighthead;

};

#endif
