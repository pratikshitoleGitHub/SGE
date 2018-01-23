#include "sge_action_handler.hpp"
#include "sge_action.hpp"
#include <algorithm>

SGE::ActionHandler::ActionHandler()
{
}

void SGE::ActionHandler::setActions(std::vector<Action*>& actionsVec)
{
    this->actions = &actionsVec;
}

void SGE::ActionHandler::triggerActionSingle(Action* action)
{
    action->action_begin();
	//Main should be called as a part of action queue.
	this->addAction(action);
}

void SGE::ActionHandler::addAction(Action* a)
{
	this->actions->push_back(a);
}

void SGE::ActionHandler::performSingleAction(Action* action, LogicPriority priority)
{
	if (priority == LogicPriority::Highest)
	{
		this->triggerActionSingle(action);
	}
	else
	{
		this->addAction(action);
        //set object locks
        //auto objects = action->getObjects();
        //if (objects)
        //{
        //    for (auto object : *objects)
        //    {
        //        object->setLock(priority);
        //    }
        //}
	}
}

std::vector<SGE::Action*>& SGE::ActionHandler::getActions()
{
    return *this->actions;
}
