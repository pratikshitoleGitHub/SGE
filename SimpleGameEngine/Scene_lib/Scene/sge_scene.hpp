#ifndef sge_scene_h
#define sge_scene_h

#include "sge_id.hpp"
#include "sge_vertex.hpp"
#include "sge_background_element.hpp"
#include "sge_level_parser.hpp"

#include <map>
#include <string>
#include <vector>

namespace SGE {
	
	class Scene;
	class Director;
	class ObjectManager;

	class SceneID final : public ID {
		friend class Director;
		friend class ObjectManager;

		Scene* scene;

	public:
		SceneID(const long id, Scene* s) : ID(id), scene(s) {};
	};

    class Scene{
	private:
		using LogicVector = std::vector<Logic::Binder>;
        using ObjectVector= std::vector<ObjectID>;
        
		Level level;
		LogicVector Logics;
        ObjectVector* Objects = nullptr;

	public:
		bool TextureLoaded = false;
		using ID = SceneID;

		LogicVector& getLogics()
		{
			return this->Logics;
		}

		virtual ~Scene() = default;

		virtual void loadLevel(const char* path, std::map<char, std::string> levelMask) final
		{
			LevelParser parser(path, levelMask);
			this->level = parser.parse();
			this->TextureLoaded = true;
		}

		virtual Level& getLevel() final
		{
			return this->level;
		}
        
        virtual void BindObjects(ObjectVector* obj) final
        {
            this->Objects=obj;
        }
        
        virtual ObjectVector& getObjects() final
        {
            return *this->Objects;
        }

		virtual void finalize() = 0;
        virtual void onDraw() = 0;
        
    protected:
        ;; //??
    };
    
}

#endif /* sge_scene_h */