#ifndef SCENE_H
#define SCENE_H
#include "typdef.h"
#include "object.h"
#include "light.h"
#include "camera.h"
#include "color.h"
#include "photonmap.h"


class Scene
{
    public:
		Scene();
        void AddObj(Object*);
        void AddLight(Light*);
        Object* getObjHead()			{return objhead;}
        Light*  getLightHead()			{return lighthead;}
		void SetInput(str _input)		{input = _input;}
		str GetInput()					{return input;}
		void SetOutput(str _output)		{output = _output;}
		str GetOutput()					{return output;}
		void SetCamera(Camera* _camera)	{camera = _camera;}
		Camera*	GetCamera()				{return camera;}
        void CameraRead(str var, ssm& finv) {camera->Read(var, finv);}
        void CameraInit()               {camera->Init();}
        void SetBackground(str var, ssm& finv);
        Color GetBackground()           {return background;}

        Intsct* GetNearstObj(const Ray& rO,const Ray& rt);
        LightIntsct* GetNearstLight(const Ray& rO, const Ray& rt);
        Color GivePhongColor(Intsct* intsct);

        void Show()
        {
            std::cout << "Show scene info:" << std::endl;
            std::cout << "Camera info:" << std::endl;
            camera->Show();
            std::cout << "Obj info list:" << std::endl;
            Object* tmp = objhead;
            while(tmp)
            {
                tmp->Show();
                tmp = tmp->GetNext();
            }
            std::cout << "Light info list:" << std::endl;
            Light* tmpl = lighthead;
            while(tmpl)
            {
                tmpl->Show();
                tmpl = tmpl->GetNext();
            }
            std::cout << "BackGround info:" << std::endl;
            background.Show();
            std::cout << "input = " << input << " output = " << output;
        }

		void GenerateScene();
		void Rendering();
    private:
        Object* objhead;
        Light* lighthead;
        Camera* camera;
        Color background;
		Photonmap* photonmap;
		str input, output;
};

#endif
