#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"

using namespace sf;
// NOTE: Don't use "using" in .h files!

class Engine
{
private:
	// The Texture Holder
	TextureHolder th;
	//NOTE: Don't name things "th" (single letter abbreviations)

	// create a particle system
	ParticleSystem m_PS;

	// Our Playable charcters, Thomas and his friend Bob
	Thomas m_Thomas;
	Bob m_Bob;

	// A class to manage the levels
	LevelManager m_LM;

	//Sound Manager
	SoundManager m_SM;

	// The Hud
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Sprite and texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Declare a shader for the background
	Shader m_RippleShader;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;
	// NOTE: use enum instead

	// Full or split screen?
	bool m_SplitScreen = false;

	// Time left in current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first leve?
	bool m_NewLevelRequired = true;

	// The vertext array for the level tiles
	VertexArray m_VALevel;
	// The 2D array with the map for the level (data) (0-3)
	// A point to a point (aka 2D Array)
	int** m_Arraylevel = NULL;
	// Texture for the level tiles
	Texture m_TextureTiles;

	// Private functions for internal use
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new level
	void loadLevel();

	// Detect collision
	// POLYMORPHISM
	bool detectCollisions(PlayableCharacter& character);

	// Make a vector of the best places to emit sounds from
	void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);

	// a list (vector) of Vector2f to contain the fire emitter locations
	vector<Vector2f> m_FireEmitters;
public:
	// Constructor
	Engine();

	// Run will call all the private functions in a loop
	void run();
};
