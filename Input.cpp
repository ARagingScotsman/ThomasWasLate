#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// Handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle player starting game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between Thomas and Bob camera focus
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			// Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}

		} //End if KeyPressed
	} // End while event polling

	// Handle input specific to Thomas
	if (m_Thomas.handleInput())
	{
		// Play jump sound
		m_SM.playJump();
	}

	// Handle input specific to Bob
	if (m_Bob.handleInput())
	{
		// Play jump sound
		m_SM.playJump();
	}

} // End input()