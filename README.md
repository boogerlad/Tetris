#Textris

###Todo
* switch from row, column notation to x, y
* cleanup
* split main to main + input interpretor
* observer pattern
* ghost piece
* 5 next piece queue
* block hold
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
* unroll loops so sequential access 2d array

[reference 1](http://tetrisproject.googlecode.com/files/TetrisRequirements.pdf)
[reference 2](http://tetris.wikia.com/wiki/Tetris_Guideline)
[reference 3 section 5](http://colinfahey.com/tetris/tetris.html)

###How to use
	make
	./quadris
That will compile for you. Left, right, down, drop, clockwise, counterclockwise, levelup, leveldown and restart work. You can append an integer multiplier in front of each if you want. Exit by eof aka ctrl+d.