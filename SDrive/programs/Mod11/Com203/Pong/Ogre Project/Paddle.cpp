// Paddle.cpp
// Paddle class member-function definitions.
#include <Ogre.h> // Ogre class definition
using namespace Ogre; // use the Ogre namespace

#include "Paddle.h" // Paddle class definition

// constructor
Paddle::Paddle( SceneManager *ptr, String paddleName, int positionX )
{
   sceneManagerPtr = ptr; // set the pointer to the SceneManager
   name = paddleName; // set the Paddle's name
   x = positionX; // set the Paddle's x coordinate
} // end Paddle constructor

// destructor
Paddle::~Paddle()
{
   // empty body
} // end Paddle default destructor

// add the Paddle to the scene
void Paddle::addToScene()
{
   Entity *entityPtr = sceneManagerPtr->
      createEntity( name, "cube.mesh" ); // create an Entity
   entityPtr->setMaterialName( "paddle" ); // set the Paddle's material
   entityPtr->setNormaliseNormals( true ); // fix the normals when scaled
   nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode( name ); // create a SceneNode for the Paddle
   nodePtr->attachObject( entityPtr ); // attach Paddle to the SceneNode
   nodePtr->setScale( .02, .3, .1 ); // set the Paddle's size
   nodePtr->setPosition( x, 0, 0 ); // set the Paddle's position
} // end function addToScene

// move the Paddle up and down the screen
void Paddle::movePaddle( const Vector3 &direction )
{
   nodePtr->translate( direction ); // move the Paddle
   if ( nodePtr->getPosition().y > 52.5 ) // top of the box
      nodePtr->setPosition( x, 52.5, 0 ); // place Paddle at top of box
   else if ( nodePtr->getPosition().y < -52.5 ) // bottom of the box
      // place the Paddle at the bottom of the box
      nodePtr->setPosition( x, -52.5, 0 );
} // end function movePaddle

