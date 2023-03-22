# PS4B: Sokoban

## Contact
Name: Jeffrey Goodman
Section:201
Time to Complete:
Im gonna go on the short end of 15 hours but lost track a long time ago.

## Description
Explain what the project does.
The project uses the SFML software as well as a class we define to create the base for our sokoban game.
### Features
Describe what your major decisions were and why you did things that way.
my major decisions in this project were to use a 2D vector to store the data from the map, because I thought the process of adding to the vector was easier.
Another one of my major decisions was to create a function that displays the map read in, to ensure that it was read properly.
### Memory
Describe how you decided to store the level data including whether you used smart pointers.
I used a 2D vector to store the level, and I did not use a smart pointer.
### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.
I used the find algorithm to find if the player had pushed 2 boxes onto the goal, and if they had, then we could declare that they had won the game.
I also used the copy algorithm to copy the map into another array so I could have the original map perserved.
I used a lambda expression that would display an error message if the texture files could not be opened for each of the textures present in the game.
### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
I fixed the errors in my last submission, as well as added the ability to restart the level, as mine wasn't working before. Everything should work now.
### Extra Credit
Anything special you did.  This is required to earn bonus points.

### changes
I added the ability to restart the level, stopped my boxes from moving through walls, stopped the player from moving after winning, added a lambda expression,
and included a picture of my game running. These should be all the errors I had in my last submission that have been fixed in the resubmission.
## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

https://stackoverflow.com/questions/64298188/no-operator-matches-these-operands-operand-types-are-stdistream-doubl

https://stackoverflow.com/questions/26937550/two-dimensional-vector-printing

https://stackoverflow.com/questions/56554212/how-do-i-read-a-text-file-into-a-2d-vector

https://stackoverflow.com/questions/50203818/check-whether-an-element-exists-in-a-2d-vector

If you used images or other resources than the ones provided, list them here.
jackpot.ttf from https://www.dafont.com/theme.php?cat=101&page=3 to display the winning message.
