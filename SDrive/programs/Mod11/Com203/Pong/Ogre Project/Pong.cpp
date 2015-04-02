// Pong.cpp
// Pong class member-function definitions.
#include <sstream>
#include <stdexcept>
#include <Ogre.h> // Ogre class definition
using namespace Ogre; // use the Ogre namespace
using namespace std; // use the Standard C namespace

#include <OgreAL.h> // OgreAL class definition
#include <OgreStringConverter.h> // OgreStringConverter class definition
#include <OIS/OISEvents.h> // OISEvents class definition
#include <OIS/OISInputManager.h> // OISInputManager class definition
#include <OIS/OISKeyboard.h> // OISKeyboard class definition
#include "Ball.h" // Ball class definition
#include "Paddle.h" // Paddle class definition
#include "Pong.h" // Pong class definition

int Pong::player1Score = 0; // initialize player 1's score to 0
int Pong::player2Score = 0; // initialize player 2's score to 0
bool Pong::wait = false; // initialize wait to false

// directions to move the Paddles
const Vector3 PADDLE_DOWN = Vector3( 0, -1, 0 ); 
const Vector3 PADDLE_UP = Vector3( 0, 1, 0 ); 

// constructor
Pong::Pong()
{

#ifdef _DEBUG
	rootPtr = new Root("Plugins_d.cfg"); // initialize Root object
#else
	rootPtr = new Root("Plugins.cfg"); // initialize Root object
#endif

   // use the Ogre Config Dialog Box to choose the settings
	//if ( !( rootPtr->showConfigDialog() ) ) // user canceled the dialog box
	//	throw runtime_error( "User Canceled Ogre Setup Dialog Box." );

	WIN32_FIND_DATA w32FD;
	HANDLE h = FindFirstFile(L"ogre.cfg", &w32FD);
	if(FAILED(h)){
      if(!rootPtr->showConfigDialog()){
		  throw runtime_error( "User Canceled Ogre Setup Dialog Box." );
      } else {
         rootPtr->saveConfig();
      }
   } else {
      rootPtr->restoreConfig();
   }


   // get a pointer to the RenderWindow
   windowPtr = rootPtr->initialise( true, "Pong! 2014 Edition" );

   // create the SceneManager
   sceneManagerPtr = rootPtr->createSceneManager( ST_GENERIC );

   // create the Camera
   cameraPtr = sceneManagerPtr->createCamera( "PongCamera" );
   cameraPtr->setPosition( Vector3( 0, 0, 200 ) ); // set Camera position
   cameraPtr->lookAt( Vector3( 0, 0, 0 ) ); // set where Camera looks
   cameraPtr->setNearClipDistance( 5 ); // near distance Camera can see
   cameraPtr->setFarClipDistance( 1000 ); // far distance Camera can see

   // create the Viewport
   viewportPtr = windowPtr->addViewport( cameraPtr );
   viewportPtr->setBackgroundColour( ColourValue( 0, 0, 0 ) );

   // set the Camera's aspect ratio
   cameraPtr->setAspectRatio( Real( viewportPtr->getActualWidth() ) /( viewportPtr->getActualHeight() ) );

   // set the scene's ambient light
   sceneManagerPtr->setAmbientLight( ColourValue( 0.75, 0.75, 0.75 ) );

   // create the Light
   Light *lightPtr = sceneManagerPtr->createLight( "Light" ); // a Light
   lightPtr->setPosition( 0, 0, 50 ); // set the Light's position

   unsigned long hWnd; // variable to hold the window handle
   windowPtr->getCustomAttribute( "WINDOW", &hWnd ); // get window handle
   OIS::ParamList paramList; // create an OIS ParamList

   // add the window to the ParamList
   paramList.insert( OIS::ParamList::value_type( "WINDOW", Ogre::StringConverter::toString( hWnd ) ) );

   // create the InputManager
   inputManagerPtr = OIS::InputManager::createInputSystem( paramList );
   keyboardPtr = static_cast< OIS::Keyboard* >( inputManagerPtr->createInputObject( OIS::OISKeyboard, true ) ); // create a Keyboard
   keyboardPtr->setEventCallback( this ); // add a KeyListener
   
   rootPtr->addFrameListener( this ); // add this Pong as a FrameListener

   // load resources for Pong
   ResourceGroupManager::getSingleton().addResourceLocation("resources", "FileSystem", "Pong" );
   ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

   quit = pause = false; // player has not quit or paused the game
   time = 0; // initialize the time since Ball was reset to 0

   paddle[0] = paddle[1] = 0;

} // end Pong constructor

// Pong destructor erases objects contained in a Pong object
Pong::~Pong()
{
    Ogre::WindowEventUtilities::removeWindowEventListener(windowPtr, this);
    windowClosed(windowPtr);

   // free dynamically allocated memory for Keyboard/mouse
	if(inputManagerPtr)
	{
		//inputManagerPtr->destroyInputObject( mousePtr );
		//mousePtr = 0;

		inputManagerPtr->destroyInputObject( keyboardPtr );
		keyboardPtr = 0;

		OIS::InputManager::destroyInputSystem(inputManagerPtr);
		inputManagerPtr = 0;
	}

   // free dynamically allocated memory for Root
   delete rootPtr; // release memory pointer points to
   rootPtr = 0; // point pointer at 0

   // free dynamically allocated memory for Ball
   delete ballPtr; // release memory pointer points to
   ballPtr = 0; // point pointer at 0

   // free dynamically allocated memory for Paddle
   delete leftPaddlePtr; // release memory pointer points to
   leftPaddlePtr = 0; // point pointer at 0

   // free dynamically allocated memory for Paddle
   delete rightPaddlePtr; // release memory pointer points to
   rightPaddlePtr = 0; // point pointer at 0
} // end Pong destructor

// create the scene to be displayed
void Pong::createScene()
{
   // get a pointer to the Score Overlay
   Overlay *scoreOverlayPtr = OverlayManager::getSingleton().getByName( "Score" ); 
   scoreOverlayPtr->show(); // show the Overlay

   // make the game objects
   ballPtr = new Ball( sceneManagerPtr ); // make the Ball
   ballPtr->addToScene(); // add the Ball to the scene
   rightPaddlePtr = new Paddle( sceneManagerPtr, "RightPaddle", 90 );
   rightPaddlePtr->addToScene(); // add a Paddle to the scene
   leftPaddlePtr = new Paddle( sceneManagerPtr, "LeftPaddle", -90 );
   leftPaddlePtr->addToScene(); // add a Paddle to the scene

   // create the walls
   Entity *entityPtr = sceneManagerPtr->createEntity( "WallLeft", "cube.mesh" ); // create the left wall
   entityPtr->setMaterialName( "wall" ); // set material for left wall
   entityPtr->setNormaliseNormals( true ); // fix the normals when scaled

   // create the SceneNode for the left wall
   SceneNode *nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode( "WallLeft" ); 
   nodePtr->attachObject( entityPtr ); // attach left wall to SceneNode
   nodePtr->setPosition( -95, 0, 0 ); // set the left wall's position
   nodePtr->setScale( .05, 1.45, .1 ); // set the left wall's size
   entityPtr = sceneManagerPtr->createEntity( "WallRight", "cube.mesh" );
   entityPtr->setMaterialName( "wall" ); // set material for right wall
   entityPtr->setNormaliseNormals( true ); // fix the normals when scaled
   
   // create the SceneNode for the right wall
   nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode( "WallRight" );
   nodePtr->attachObject( entityPtr ); // attach right wall to SceneNode
   nodePtr->setPosition( 95, 0, 0 ); // set the right wall's position
   nodePtr->setScale( .05, 1.45, .1 ); // set the right wall's size
   entityPtr = sceneManagerPtr->createEntity( "WallBottom", "cube.mesh" );
   entityPtr->setMaterialName( "wall" ); // set material for bottom wall
   entityPtr->setNormaliseNormals( true ); // fix the normals when scaled
   
   // create the SceneNode for the bottom wall
   nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode( "WallBottom" ); 
   nodePtr->attachObject( entityPtr ); // attach bottom wall to SceneNode
   nodePtr->setPosition( 0, -70, 0 ); // set the bottom wall's position
   nodePtr->setScale( 1.95, .05, .1 ); // set bottom wall's size
   entityPtr = sceneManagerPtr->createEntity( "WallTop", "cube.mesh" );
   entityPtr->setMaterialName( "wall" ); // set the material for wall
   entityPtr->setNormaliseNormals( true ); // fix the normals when scaled
   
   // create the SceneNode for the top wall
   nodePtr = sceneManagerPtr->getRootSceneNode()->createChildSceneNode( "WallTop" ); 
   nodePtr->attachObject( entityPtr ); // attach top wall to SceneNode
   nodePtr->setPosition( 0, 70, 0 ); // set the top wall's position
   nodePtr->setScale( 1.95, .05, .1 ); // set the top wall's size
} // end function createScene

// start a game of Pong
void Pong::run()
{
   createScene(); // create the scene
   Ogre::WindowEventUtilities::addWindowEventListener(windowPtr, this);
   rootPtr->startRendering(); // start rendering frames
} // end function run

// update the score
void Pong::updateScore( Players player )
{
   // increase the correct player's score
   if ( player == Players::PLAYER1 )
      player1Score++;
   else
      player2Score++;

   wait = true; // the game should wait to restart the Ball
   updateScoreText(); // update the score text on the screen
} // end function updateScore

// update the score text
void Pong::updateScoreText()
{
   ostringstream scoreText; // text to be displayed

   scoreText << "P2: " << player2Score; // make the text

   // get the right player's TextArea
   OverlayElement *textElementPtr = OverlayManager::getSingletonPtr()->getOverlayElement( "right" );
   textElementPtr->setCaption( scoreText.str() ); // set the text

   scoreText.str( "" ); // reset the text in scoreText
   scoreText << "P1: " << player1Score; // make the text

   // get the left player's TextArea
   textElementPtr = OverlayManager::getSingletonPtr()->getOverlayElement( "left" );
   textElementPtr->setCaption( scoreText.str() ); // set the text
} // end function updateScoreText

// respond to user keyboard input
bool Pong::keyPressed( const OIS::KeyEvent &keyEventRef )
{
   // if the game is not paused
   if ( !pause )
   {
      // process KeyEvents that apply when the game is not paused
      switch ( keyEventRef.key )
      {
      case OIS::KC_ESCAPE: // escape key hit: quit
         quit = true;
         break;
      case OIS::KC_UP: // up-arrow key hit: move the right Paddle up
         paddle[0] = 1;
         break;
      case OIS::KC_DOWN: // down-arrow key hit: move the right Paddle down
         paddle[0] = -1;
         break;
      case OIS::KC_NUMPAD8: // 8 key hit: move left Paddle up
         paddle[1] = 1;
         break;
	  case OIS::KC_NUMPAD2: // 2 key hit: move left Paddle down
         paddle[1] = -1;
         break;
	  case OIS::KC_W: // W key hit: rotate board 'up'
		  break;
	  case OIS::KC_A: // A key hit: rotate board 'left'
		  break;
	  case OIS::KC_S: // S key hit: rorate board 'down'
		  break;
	  case OIS::KC_D: // D key hit: rotate board 'right'
		  break;
      case OIS::KC_P: // P key hit: pause the game
         pause = true; // set pause to true when the user pauses the game
         Overlay *pauseOverlayPtr = OverlayManager::getSingleton().getByName( "PauseOverlay" );
         pauseOverlayPtr->show(); // show the pause Overlay
         break;
      } // end switch
   } // end if
   else // game is paused
   {
      // user hit 'R' on the keyboard
      if ( keyEventRef.key == OIS::KC_R )
      {
         pause = false; // set pause to false when user resumes the game
         Overlay *pauseOverlayPtr = OverlayManager::getSingleton().getByName( "PauseOverlay" );
         pauseOverlayPtr->hide(); // hide the pause Overlay
      } // end if
   } // end else
   return true;
} // end function keyPressed

// process key released events
bool Pong::keyReleased( const OIS::KeyEvent &keyEventRef )
{
	switch ( keyEventRef.key )
    {
      case OIS::KC_UP: // up-arrow key released, stop moving that direction
         if (paddle[0] != -1) // if we're not moving down already
			 paddle[0] = 0;
         break;
      case OIS::KC_DOWN: // down-arrow key released, stop moving that direction
         if (paddle[0] != 1) // if we're not moving up already
			 paddle[0] = 0;
         break;
      case OIS::KC_NUMPAD8: // number pad 8 key released, stop moving that direction
		 if (paddle[1] != -1) // if we're not moving down already
			paddle[1] = 0;
         break;
	  case OIS::KC_NUMPAD2: // number pad 2 key released, stop moving that direction
		  if (paddle[1] != 1) // if we're not moving up already
			paddle[1] = 0;
         break;
	}
   return true;
} // end function keyReleased

// return true if the program should render the next frame
bool Pong::frameEnded( const FrameEvent &frameEvent )
{
	WindowEventUtilities::messagePump();
	if(windowPtr->isClosed())
    {
        return false;
    }
	return !quit; // quit = false if the user hasn't quit yet
} // end function frameEnded

// process game logic, return true if the next frame should be rendered
bool Pong::frameStarted( const FrameEvent &frameEvent )
{
   keyboardPtr->capture(); // get keyboard events

   
  // paddle moving logic
  if (paddle[0] != 0) // [0] = left paddle
  {
	  //process
	  if (paddle[0] < 0) // go down
	  {
		  leftPaddlePtr->movePaddle( PADDLE_DOWN );
	  } else if (paddle[0] > 0) // go up
	  {
		  leftPaddlePtr->movePaddle( PADDLE_UP );
	  }
  }
  if (paddle[1] != 0) // [1] = right paddle
  {
	  //process
	  if (paddle[1] < 0) // go down
	  {
		  rightPaddlePtr->movePaddle( PADDLE_DOWN );
	  } else if (paddle[1] > 0) // go up
	  {
		  rightPaddlePtr->movePaddle( PADDLE_UP );
	  }
  }


   // the game is not paused and the Ball should move
   if ( !wait && !pause )
   {
      // move the Ball
      ballPtr->moveBall( frameEvent.timeSinceLastFrame );
   } // end if
   // don't move the Ball if wait is true
   else if ( wait )
   {
      // increase time if it is less than 4 seconds
      if ( time < 4 )
         // add the seconds since the last frame
         time += frameEvent.timeSinceLastFrame; 
      else
      {
         wait = false; // shouldn't wait to move the Ball any more
         time = 0; // reset the control variable to 0
      } // end else
   } // end else

   return !quit; // quit = false if the user hasn't quit yet
} // end function frameStarted


//Adjust mouse clipping area
void Pong::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);
 
    const OIS::MouseState &ms = mousePtr->getMouseState();
    ms.width = width;
    ms.height = height;
}
 
//Unattach OIS before window shutdown (very important under Linux)
void Pong::windowClosed(Ogre::RenderWindow* rw)
{

}

bool Pong::mousePressed(const OIS::MouseEvent &,OIS::MouseButtonID)
{
	return true;
}
bool Pong::mouseReleased(const OIS::MouseEvent &,OIS::MouseButtonID)
{
	return true;
}
bool Pong::mouseMoved(const OIS::MouseEvent &)
{
	return true;
}