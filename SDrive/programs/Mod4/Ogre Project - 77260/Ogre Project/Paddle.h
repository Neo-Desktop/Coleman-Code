// Paddle.h
// Paddle class definition (represents a paddle in the game).
#ifndef PADDLE_H
#define PADDLE_H

#include <Ogre.h> // Ogre class definition
using namespace Ogre; // use the Ogre namespace

class Paddle
{
public:
   // constructor
   Paddle( SceneManager *sceneManagerPtr, String paddleName, 
      int positionX); 
   ~Paddle(); // destructor
   void addToScene(); // add a Paddle to the scene
   void movePaddle( const Vector3 &direction ); // move a Paddle

private:
   SceneManager* sceneManagerPtr; // pointer to the SceneManager
   SceneNode *nodePtr; // pointer to a SceneNode
   String name; // name of the Paddle
   int x; // x coordinate of the Paddle
}; // end of class Paddle

#endif // PADDLE_H

