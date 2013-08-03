#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "grid.h"

using namespace std;

int main(int argc, char* argv[]) {
   // commands
   string left = "left";
   string right = "right";
   string down = "down";
   string drop = "drop";
   string cw = "clockwise";
   string ccw = "counterclockwise";
   string lvUp = "levelup";
   string lvDown = "leveldown";
   string restart = "restart";
   string quit = "quit";
   string hold = "hold";

   // seed for random num generator, will be 1 unless specified
   int seed = 1;//time(0);

   // counter for for-loop
   int counter = 1;

   // windows option
   bool graphics = true;

   // initital starting level of the game
   int startLevel = 0;
   string file = "sequence.txt";
   // checks for command line arguments
   for (; counter < argc; ++counter ){
	  string strConvert( argv[counter] );

	  if (strConvert  == "-text" ) {
		 graphics = false;
	  } else if ( strConvert == "-seed" ){
		 counter++;

		 stringstream buffer;
		 string seedStr( argv[counter] );

		 buffer << seedStr;
		 buffer >> seed;
		 if ( buffer.fail() ) {
			seed = 1;
			break;
		 }

	  } else if ( strConvert == "-scriptfile" ){
		 counter++;

		 string converter (argv[counter]);
		 file = converter;
		 // change grid constructor to take string

	  } else if ( strConvert == "-startlevel" ) {
		 counter++;

		 stringstream buffer;
		 string seedStr( argv[counter] );
		 buffer << seedStr;
		 buffer >> startLevel;

		 if (buffer.fail() || startLevel < 0 || startLevel> 3 ) {
		   startLevel = 0;
		   break;
		 }
	  }
   }
   srand(seed);
   Grid g(startLevel, file);//, graphics);
   g.place();
   cout << g;// << endl; // prints after placing first block

	stringstream buffer;

	bool multDrop = false;
	int dropTimes = 0;
	int mult = 1;

   while ( !cin.eof() ){

	  while ( !g.getCurrSet() )
	  {
		//buffer.clear();
	   if (cin.eof()) { return 42; }
		stringstream buffer;
		string command, comm;

		if (!multDrop){

			mult = 1;
		 	getline(cin, command);
		 	buffer << command; // read command into sstream

			// checks for multiplier
			buffer >> mult;
       	if ( buffer.fail() ){
         	buffer.clear();
         	mult = 1; // reset mult to 1
      	}
			buffer >> comm;

		} else {
			mult = dropTimes;
			comm = "drop";
		}

		// read first while space deliminated string from command
		if (comm.size() <= 1) continue;

		 // new commands for Quardis

		 // check if command is left
		 if ( comm.size() <= left.size() ){
			 if ( ( left.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 3 ){
				for ( int i = 0; i < mult; ++i){
					 g.left();
				}
			  }
		 }
		// checks if command is right
		 if ( comm.size() <= right.size() ){
			   if ( ( right.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){
			   for (int i = 0; i < mult; ++i) {
				  g.right();
			   }
			}
		 }
		// down command
		 if ( comm.size() <= down.size() ){
			if ( ( down.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){
			   for (int i = 0; i < mult; ++i){
					 g.down();
			   }
			}
		 }
		// drop command
		 if ( comm.size() <= drop.size() ){
			if ( ( drop.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){
			   //for (int i = 0; i < mult; ++i){
					g.drop();
					if (mult >= 1 ){
						multDrop = true;
 			  			dropTimes = mult-1;
					}
					if (multDrop && (dropTimes == 0) ){
						multDrop = false;
					}
			}
		 }
		// clockwise command
		 if ( comm.size() <= cw.size() ){
			if ( ( cw.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){


	auto start = std::chrono::high_resolution_clock::now();


			   for (int i = 0; i < mult; ++i){
				  g.cw();
			   }

	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << (finish - start).count() << " microseconds\n";
	unsigned long long time = (finish - start).count();
	std::cout << time << std::endl;

			}
		 }
		// countclockwise command
		 if ( comm.size() <= ccw.size() ){
			if ( ( ccw.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){

	auto start = std::chrono::high_resolution_clock::now();
//std::cout << "hi I'm slow" << std::endl; 42 more microseconds eek
			   for (int i = 0; i < mult; ++i){
				  g.ccw();
			   }

	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << (finish - start).count() << " microseconds\n";
	unsigned long long time = (finish - start).count();
	std::cout << time << std::endl;

			}
		 }


		 // check if command is hold
		 if ( comm.size() <= hold.size() ){
			 if ( ( hold.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 1 ){
					 g.hold();
			  }
		 }





		// levelup command
		 if ( comm.size() <= lvUp.size() ){
			if ( ( lvUp.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 6){
				for (int i = 0; i < mult; ++i){
				    if (g.getLevel() >= 0 && g.getLevel() <= 2) {
	   				 g.setLevel( g.getLevel()+1 );
				  }
			   }
			}
		 }

		// leveldown command
		 if ( comm.size() <= lvDown.size() ){
			if ( ( lvDown.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 6 ){
			  for (int i = 0; i < mult; ++i){
				  if (g.getLevel() >= 1 && g.getLevel() <= 3) {
					 if (g.getLevel() == 1) {
					   g.setLevel( 0, file );
					 }
					 else { g.setLevel(  g.getLevel()-1); }
				  }
   		  }
			}
		 }
		// restart command
		 if ( comm.size() <= restart.size() ){
			if ( ( restart.compare( 0,comm.size(),comm ) == 0 ) && comm.size() >= 2 ){
                g.setLevel(startLevel, file);
                g.reset();
			    g.place();
			}
		 }
		 cout << g;// << endl;
	  }
	  // checks if we can clear lines and blocks
	  g.clearLines();

	  //make new block check for game over
	  if (g.place() ) {
		 cout << g;// << endl;
		 continue;
		} else {
		 multDrop = false;
		 cout << "Game Over" << endl;
		 cout << "Would you like to play again? [y/n]";
		 char ch = 'x';
            while ((ch != 'y' && ch != 'Y') && (ch != 'n' && ch != 'N')){
                cin >> ch;
                if (ch == 'y' || ch == 'Y' ) {
                    g.setLevel(startLevel, file);
                    g.reset();
                    g.place();
                    cout << g << endl;
                } else if ( ch == 'n' || ch == 'N' ) {
                    return 42;
                }
            }
        }

   }
   return 0;
}

