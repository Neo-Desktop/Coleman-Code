// Pong.h
// Pong class definition (represents a game of Pong).
#ifndef PONG_H
#define PONG_H

#include <Ogre.h> // Ogre class definition
using namespace Ogre; // use the Ogre namespace

#include <OIS\OISEvents.h> // OISEvents class definition
#include <OIS\OISInputManager.h> // OISInputManager class definition
#include <OIS\OISKeyboard.h> // OISKeyboard class definition
#include <OIS\OISMouse.h>
#include <OgreWindowEventUtilities.h>

class Ball; // forward declaration of class Ball
class Paddle; // forward declaration of class Paddle

enum Players { PLAYER1, PLAYER2 };

class Pong : public FrameListener, public OIS::KeyListener, public Ogre::WindowEventListener, public OIS::MouseListener
{
public:
   Pong(); // constructor
   ~Pong(); // destructor
   void run(); // run a game of Pong

   // handle keyPressed and keyReleased events
   virtual bool keyPressed( const OIS::KeyEvent &keyEventRef );
   virtual bool keyReleased( const OIS::KeyEvent &keyEventRef );

   // handle mouseMoved, mousePressed, and mouseReleased events
   virtual bool mousePressed(const OIS::MouseEvent &,OIS::MouseButtonID);
   virtual bool mouseReleased(const OIS::MouseEvent &,OIS::MouseButtonID);
   virtual bool mouseMoved(const OIS::MouseEvent &);

   // move the game objects and control interactions between frames
   virtual bool frameStarted( const FrameEvent &frameEvent );
   virtual bool frameEnded( const FrameEvent &frameEvent );
   static void updateScore( Players player); // update the score

private:
   void createScene(); // create the scene to be rendered
   static void updateScoreText(); // update the score on the screen

   // Ogre objects
   Root *rootPtr; // pointer to Ogre's Root object
   SceneManager *sceneManagerPtr; // pointer to the SceneManager
   RenderWindow *windowPtr; // pointer to RenderWindow to render scene in
   Viewport *viewportPtr; // pointer to Viewport, area that a camera sees
   Camera *cameraPtr; // pointer to a Camera in the scene

   // OIS input objects
   OIS::InputManager *inputManagerPtr; // pointer to the InputManager
   OIS::Keyboard *keyboardPtr; // pointer to the Keyboard
   OIS::Mouse *mousePtr; // pointer to the mouse

   // Ogre::WindowEventListener
   virtual void windowResized(Ogre::RenderWindow* rw);
   virtual void windowClosed(Ogre::RenderWindow* rw);

   // game objects
   Ball *ballPtr; // pointer to the Ball
   Paddle *leftPaddlePtr; // pointer to player 1's Paddle
   Paddle *rightPaddlePtr; // pointer to player 2's Paddle

   // variables to control game states
   bool quit, pause; // did user quit or pause the game?
   Real time; // used to delay the motion of a new Ball
   static bool wait; // should the Ball's movement be delayed?

   static int player1Score; // player 1's score
   static int player2Score; // player 2's score

   int paddle[2];

}; // end class Pong

#endif // PONG_H


