#include "sge_input_handler.hpp"
#include "sge_game.hpp"
#include "sge_input_manager.hpp"
#include "sge_mouse.hpp"
#include "sge_input_binder.hpp"

#include <glm/glm.hpp>

namespace SGE {

	InputHandler::MouseHandler::MouseHandler() noexcept : mouse(new MouseObject) {

	}

	void InputHandler::MouseHandler::setMouseCoords(glm::vec2 coords) noexcept {
		this->mouse->setMouseCoords(coords);
	}

	glm::vec2 InputHandler::MouseHandler::getMouseCoords(void) const noexcept {
		return this->mouse->getMouseCoords();
	}

	MouseObject* InputHandler::MouseHandler::getMouseObject(void) noexcept {
		return this->mouse;
	}

	InputHandler::InputHandler(Game* game) noexcept : game(game), input_manager(new InputManager), mouseHandler(new MouseHandler) {
	}

	void InputHandler::mapAction(const InputBinder& bind)
	{
		auto p = this->keyMap.insert(std::make_pair(bind.getKey(), bind.getBind()));
		if (!p.second) throw std::runtime_error("You are an idiot");
	}

	void InputHandler::unmapAction(const InputBinder& bind)
	{
		if (this->keyMap.erase(bind.getKey()) == 0) throw std::runtime_error("You are an idiot");
	}

	void InputHandler::pressKey(Key k)
	{
		auto it = this->keyMap.find(k);
		if (it == this->keyMap.end()) return;
		this->game->action_handler->handleInputAction(it->second);
	}

	void InputHandler::operator()(void) noexcept {

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: {
					this->game->windowClosing();
				}break;

				case SDL_KEYDOWN: {
					this->pressKey(Key(event.key.keysym.sym));
				}break;

				case SDL_MOUSEMOTION: {
					this->mouseHandler->setMouseCoords({ event.motion.x, event.motion.y });
				}break;

				case SDL_MOUSEBUTTONDOWN: {
					this->mouseHandler->setMouseCoords({ event.motion.x, event.motion.y });
					this->pressKey(Key(-10));
				}break;

				case SDL_MOUSEBUTTONUP: {

				}break;
			}
		}

	}

	InputHandler::MouseHandler* InputHandler::getMouseHandler() noexcept {
		return this->mouseHandler;
	}

}