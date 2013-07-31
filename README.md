#Textris

###Todo
* cleanup
* split main to main + input interpretor
* observers5
* ghost piece
* 5 next piece queue
* clock
* wallkicks
* srs
* ogl
* [input](http://sourceforge.net/projects/wgois/)
* no bitmaps for gfx
* [dynamic created tetriminoes?](https://engineering.purdue.edu/OOSD/F2009/Assignments/GPA/stage1.html)
* dynamic computed rotations => (not tetris 2)		will this be faster than static? profiling awaits!
* [audio](http://www.portaudio.com/)
* network p2p or lobby system
* ai
* tetris battle modes
* cooperative mode
* port to windows
* replay and video capture

tetrisproject.googlecode.com/files/TetrisRequirements.pdf
tetris.wikia.com/wiki/Tetris_Guideline
http://colinfahey.com/tetris/tetris.html
section 5

###How to use
	make
	./quadris
That will compile for you. Left, right, down, drop, clockwise, counterclockwise, levelup, leveldown and restart work. You can append an integer multiplier in front of each if you want. Exit by eof aka ctrl+d.