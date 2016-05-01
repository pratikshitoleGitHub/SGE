#ifndef sge_object_h
#define sge_object_h

#include "../ID/sge_id.hpp"
#include "Shape/sge_shape.hpp"

namespace SGE {
	class ObjectManager;
	class Object;

	enum class LogicPriority
	{
		Highest = 0,
		High,
		Mid,
		Low,
		None
	};

	class ObjectID : public ID {
		friend class ObjectManager;
		Object* obj = nullptr;
	public:
		ObjectID(const long id) : ID(id) {
		}
		ObjectID(const long id, Object* o) : ID(id), obj(o) {
		}

		Object* getObject() const
		{
			return this->obj;
		}

        ObjectID(const ObjectID&) = default;
        ObjectID& operator=(const ObjectID&) = default;
	};

    class GLTexture;
    
	class Object
	{
	protected:
		float X;
		float Y;
		bool drawable = false;
		Shape* shape = getShapeless();
		LogicPriority lock = LogicPriority::None;

	public:
		Object() = default;
		Object(float x, float y) : X(x), Y(y){}
        Object(float x, float y, Shape* shape): X(x), Y(y), shape(shape){}
		Object(float x, float y, bool draw) : X(x), Y(y), drawable(draw){}
		Object(float x, float y, bool draw, Shape* shape) : X(x), Y(y), drawable(draw), shape(shape){}
		virtual ~Object() = 0;
		using ID = ObjectID;
        
        GLTexture* texture = nullptr;
        
        virtual float& getX() noexcept final
        {
            return this->X;
        }
        
        virtual float& getY() noexcept final
        {
            return this->Y;
        }
        
        virtual void setDrawable(bool e) noexcept final{
            this->drawable = e;
        }
        
        virtual bool getDrawable(void) const noexcept final {
            return this->drawable;
        }
        
        virtual void setPosition(float x, float y){
            this->X=x;
            this->Y=y;
        }
        
        virtual Shape* getShape() noexcept final {
            return this->shape;
        }

		virtual LogicPriority getLock() const noexcept final
		{
			return lock;
		}

		virtual void setLock(const LogicPriority lock) noexcept final
		{
			this->lock = lock;
		}
    };

	inline Object::~Object()
	{
		if(this->shape->isDisposable()) delete this->shape;
	}
}

#endif /* sge_object_h */
