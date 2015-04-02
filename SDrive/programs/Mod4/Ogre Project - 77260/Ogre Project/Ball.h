// Ball.h
// Ball class definition (represents a bouncing ball).
#ifndef BALL_H
#define BALL_H

#include <Ogre.h> // Ogre class definition
using namespace Ogre; // use the Ogre namespace

#include <OgreAL.h> // OgreAL class definition

class Paddle; // forward declaration of class Paddle

const int RADIUS = 5; // the radius of the Ball

class Ball
{
public:
   Ball( SceneManager *sceneManagerPtr ); // constructor
   ~Ball(); // destructor
   void addToScene(); // add the Ball to the scene
   void moveBall( Real time ); // move the Ball across the screen

private:
   SceneManager *sceneManagerPtr; // pointer to the SceneManager
   SceneNode *nodePtr; // pointer to the SceneNode
   OgreAL::SoundManager *soundManagerPtr; // pointer to the SoundManager
   OgreAL::Sound *wallSoundPtr; // sound played when Ball hits a wall
   OgreAL::Sound *paddleSoundPtr; // sound played when Ball hits a Paddle
   OgreAL::Sound *scoreSoundPtr; // sound played when someone scores
   int speed; // speed of the Ball
   Vector3 direction; // direction of the Ball

   // private utility functions
   void reverseHorizontalDirection(); // change horizontal direction
   void reverseVerticalDirection(); // change vertical direction
   void hitPaddle(); // control the Ball hitting the Paddles
}; // end class Ball

#endif // BALL_H

