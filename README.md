# huntthemugwump
C++ lab group project

https://faculty-web.msoe.edu/hasker/cs2040/labs/6/

Labs 6 and 7 will give you experience with working in teams to write a larger, object-oriented C++ program.

# The Game
Hunt the Wumpus was an early computer game. The basic goal of the game is to kill a wumpus in a cave without entering the chamber the wumpus is in, using your senses to detect when it is close by. Along the way you can fall into pits, be picked up by bats, and discover objects such as arrows and treasure. Atari had a full version of this that you can play online, but this has far more features than we want you to try to implement. A simpler version that is closer to what you should implement is available here. However, your solution must be character based. For example, your program might look like

    
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: e

 You hear flapping. You smell something bad.
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: s

 You find an arrow. You smell something bad.
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: n

 You hear flapping. You smell something bad.
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: n

 You are in a maze of twisty passages, all alike.
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: e

 You feel a breeze. You smell something bad.
 Action: N)orth, S)outh, E)ast, W)est, shoot A)rrow, H)elp, Q)uit: s

 You were eaten by a wumpus!

You will work in groups of 2 or 3 on this assignment. You will design your own version of the game and implement it in C++. One of your early tasks will be to document the rules of your game and to construct a class model. Part of your grade will be based on how unique your solution is; you might hunt moldy food in your fridge, chase Roscoe Raider through the science building, or be hunted by a large cockroach. Be creative with behaviors as well: alternative traps and new ways to move about the caves are also appropriate. Note that just substituting (say) marshmallows for arrows is not an example of creativity.

# The Game
You must have a help option describing how to play the game. Ensure this covers all rules.
The game must be reasonably simple. In particular, it must be possible to play the game without extensive research.
In addition, your game must be winnable applying basic deductive reasoning. In the original game, the player has a reasonable chance of winning based on educated guesses, just as it is with modern puzzle games. You will lose points if winning is purely a matter of luck.
At a minimum, you must have equivalents for the wumpus, the pits, the bats, and the arrows (something to pick up). Since you must use inheritance in the implementation (see below), you will probably want at least two types of hazards or weapons (such as two types of traps or two types of weapons).
No graphics. All user input and output to your program must be through cin, cout, and cerr using the standard ASCII character set.
The map must have a reasonable size. With the standard rules, a map of 6 rooms by 6 rooms is enough to exhibit good game play. Maps larger than 10 by 10 will not be allowed, and you must have a strong justification for being larger than 6 by 6.
You must provide clues to the player when they approach the various hazards. Since the gamer cannot see the map contents, they need clues to tell them when they approach hazards and the wumpus. For instance, the original game says "you smell something bad" if the player is in a room adjacent to the wumpus, "you feel a breeze" if the player is in a room adjacent to a pit, and "you hear flapping" if the player is close to a room with a bat. In the original, "adjacent" means either sharing a wall or a corner, and "close to" a bat is up to 2 rooms away. Arrows are not hazards, so there are no clues for those. You will need to define your own rules for clues (that must be documented). The key is that the clues must be strong enough that a player can deduce the location of the target (such as the wumpus) but still requiring logic to work out that location.
When the player reaches the edge of the map, one of two things must happen. Either any moves that would be "outside" the map must be blocked, or you must implement a wraparound behavior where moving outside teleports the player to the corresponding position on the other side of the map. Implementing the teleport is a possible form of uniqueness, but if you do then you must also also allow the player to pick up clues (as described above) from the other side of the map.
Stick to one level. Multi-level dungeons are too hard for instructors to test.
Use e/w/n/s to move in the specified directions. Entering an "e" should move east; do not have the user enter more complex commands such as "m" for move followed by an "e"; the "e" is enough by itself. Uniformity is critical for grading. Upper case commands must be treated the same as lower case commands (case in-sensitive). Do not implement the common "wasd" directions - this game is intended for casual gamers.
The program cannot quit because of an invalid command. Print an error and continue.
Your game must exhibit random behavior. Randomly place items on the map so the user has to solve a different map each time. You can use rand to generate the random numbers. Your game maps must be randomly generated.
Provide a debug mode that can be used to illustrate that your program works. The debug mode must have a pre-generated map with a full collection of the different types of objects you have implemented, placed to show that these objects work as intended. You can also display additional information if you find it helpful. Enable the debug mode by having the user enter "d" during game play - it cannot be just a compile-time option.
Along with the e/w/n/s, actions to pick up weapons, etc., have "m" display the full map. This will help with debugging and grading. Use the following key for this map: a period for an empty room, an - for a weapon (such as an arrow), + or P for the player, B for a bat, @ for a hazard (such as a pit), ? for treasure, and ! for the monster. As an example, your map would look like

. . - + .
. B @ . -
. ? . - B
. @ ! . .
@ . . - @

Follow this notation for your own game, though you might use a different symbol than B for alternative bat-like entities. Having uniform notation on this output will help tremendously in grading.
While displaying the map is important to verify game play is working, it must be possible to win the game without resorting to viewing the map. This means you must implement clues similar to the "you smell something bad" clue of the classical game. In addition, the monster and other items must not move during game play unless there is a specific rule such as "the wumpus moves when shot at".
Any hints you give the player should be based on being close to an object; for example, feeling a breeze when the player is next to a pit or hearing the wumpus start to move if it is disturbed by shooting an arrow. This is a large part of what makes hunt-the-wumpus a winnable puzzle game. You should be able to find corresponding clues for any variant of the game. Do not make the player purchase hints (say, trading gold or experience points) because this will make the game too hard to grade.
Whenever the bat (or its equivalent) moves the player in the dungeon, provide a hint saying the player moved. Note the original game does not say where the player moved to, just that the player was moved.
Whenever the player is killed, say by falling into a trap or being eaten by a monster, say what killed the player so the user can learn to play the game better in the future.
Whenever you create an instance of a class your group writes, or whenever you pass an instance as a parameter, use pointers. This is especially important for inheritance, but it is also necessary to give your team more experience with pointers. Be sure to use delete to return all allocated memory to the heap. This wouldn't be strictly necessary for a small project like this, but it is good practice. There must be exactly one delete executed for each new executed. You will likely want to implement destructors to ensure this happens.

# Design Constraints
Your implementation must be unique, even if your rules are very close to the original. If your implementation looks like one of the hundreds of versions of the game that are available online, you will be penalized. Ignore the online code and you will be fine.
You must use inheritance in an important way as part of your solution. One use of inheritance is adequate (that is, one base class with two distinct subclasses with important different behaviors), but you may find it leads to a better design to use inheritance in multiple ways. for an A you may need additional base classes with additional subclasses.
You must make heavy use of classes (have a number of them). This actually helps distinguish your solution from most of the ones online. Start with the obvious domain classes: maps, rooms, the item being hunted, hazards, etc. These are the objects in the problem that a non-programmer would recognize, and using them as the basis of a design makes your program easier to write and maintain.
Use pointers for domain objects like the map, locations, arrows, etc.
You might use a standard design pattern, other than singleton, as discussed in SE 2811 (Software Design Patterns). This is another way to be unique, but be sure there is a good reason to use the pattern.
Each class must have clear, documented responsibilities. This documentation must be in the .h files.
All group members must contribute to the solution. You will use GitLab (or a similar site) for your project repository; see below.
It is expected that all team members will contribute to at least a third of the classes related to the minimal requirements listed above (in the paragraph starting with "at a minimum"). The goal is to learn about interfaces between classes in C++, and having each team member implement a substantial portion is important to that. Features beyond the minimums are not considered when checking this requirement.
Hints
Use rand to generate random numbers.
Use srand to seed your random number generator; see the line "srand(time(NULL))" in the example.
You might prompt the user about using debug mode and then call the srand function only in regular mode. You can also set up debug mode to run when the user specifies a command-line argument. Be sure to document entering debug mode in the readme file (see below).
If you are interested in using the C++ <random> library instead of rand and srand, talk to your instructor.
# Lab 6
Labs 6 and 7 are two parts of the same project. Lab 6 will be based on setting up the project and designing the game, and lab 7 will be based on delivering a working, maintainable solution.

For lab 6, submit a (single) PDF containing all of the following

The names of the people in the group.
The URL of your GitLab repository. In particular, the username and repository name should be obvious. The username must be a campus username - no names like "drwump". Be sure the repository is private and your instructor has been invited to it with write or administrator permission. The repository name must be all lower case, have no spaces, and must include "puzzle", and include the usernames of all team members such as puzzle-user1-user2
The typewritten (that is, word-processed) list of rules for your game. Any changes to these rules must be signed off by your instructor.
A high level class diagram capturing your intended design, drawn in Enterprise Architect. Include any design patterns you will use. The diagram must be high level:
Prioritize domain level objects.
Capture classes and generalizations.
Include only important attributes and methods; do not document constructors, getters/setters, constants, and other items that can be assumed.
Include types for attributes and methods only if important.
Capture associations and multiplicities, but do not distinguish between composition and aggregation.
Capture static information only - do not include dynamic associations.
A description of which part of the system each team member will implement.
A short sentence or two discussing what you believe to be unique about your solution.
In addition, check in an initial version of the project that builds on all machines. This does not need to do more than print the primary menu and exit when the user enters 'q'. However, it will be to your advantage to implement more than this minimum since it will be difficult to implement the full solution during the next week's lab time. In fact, you will want to use that lab time to integrate the work done by each partner and to determine if all requirements are satisfied.

Some students are tempted use use the code generation feature of Enterprise Architect to create the initial code. Do not; it adds a lot of unnecessary artifacts and means you will not get sufficient practice writing C++ code. If it takes more than about 15 minutes to create an initial version of the project, get help from your instructor. It should be as simple as creating a "hello world" program and editing it to prompt the user until the user enters 'q'.

# Lab 7
Lab 7 is finishing and delivering the full solution. This includes the following:

Have a friend play the game and confirm it is winnable with minimal help from you.
Ensure all code meets the published coding standard and has been pushed to GitLab. All source (.h, .cpp files) must be in a folder called src in the top level of your repository.
Remember that the standard mandates lower case filenames.
There should not be any subdirectories in src. Multi-folder C++ projects do not make sense for the small projects you create in academics.
You must have fewer files than classes to ensure you understand that one file per class is not a requirement in C++.
The submitted code must be on the main branch. You are discouraged from using branches for short assignments such as this.
Ensure the project build files have been checked in to your repository.
In the top level of your repository, create a file README.TXT (or README.md, etc.) which gives the names of all people on your team and build directions that indicate the version of C++ you used, the build tool you used (CodeLite, make, etc.), the steps someone goes through to use that tool to build an executable, and where the executable can be found once it is built. Anyone who knows C++ and has your build system installed should be able to reproduce those steps.
Document how to enter debug mode.
Include any changes to your game (from your stated design) in this document.
Use the output of g++ --version to determine the version of the tool used to build the system. It is very helpful to be able to identify this when trying to get a system to build years after it was written.
Double-check that your instructor has access to your repository.
In the top level of your repository, create a file called sample-run.pdf that has screen shots showing that your solution works. This will likely be a large number of screen shots. You do not have to include screen shots of every movement, but you must build a narrative stating what the game player did and why the final result (win or lose) is correct. Include debug output to help make your case, especially a clearly marked picture of your debugging map.
In addition to your screenshots, use these directions to create a reverse-engineered diagram of your system, export it as a .png, and include that image in sample-run.pdf.
Submit sample-run.pdf to Canvas to signal that you are finished.
Demonstrate your solution to your instructor within a week of submitting to Canvas. Only one of the students must be present at the demo, but others can participate.