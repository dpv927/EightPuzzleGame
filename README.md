<div class="languages" align="center">

# Eight-puzzle-game

:uk: <a href="#">English</a>
:es: <a href="https://github.com/dpv927/eight-puzzle-game/blob/main/esREADME.md">Español</a>
</div>

## About
Unlike other apps that solve the 8-puzzle, this app allows you to specify the initial and goal state of the game-board. 
The search tree is developed with the <ins>A* algorithm</ins>, giving the least expensive solution (talking about the number of moves).

## How to use
The program expects two arguments (initial and final states of the board described as strings). For example, the string "123456780" (Obviously without the quotes "") will represent the following board: 
```
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+   Note: A spot with '0' indicates that there is 
| 4 | 5 | 6 |   no chip in that position on the board.
+---+---+---+
| 7 | 8 | 0 |
+---+---+---+
```
For example, an example of execution of the program can be: ``8-puzzle-solver 123456780 012345678``, were 123456780 is the initial state of the board, and 012345678 the final state of the board.

Then the solver will show the initial and final states of the board that were specified, the exact path from the given start to the solution with each step depth and some search info like `CREATED_NODES`, `EXPANDED_NODES` and `SOLUTION_DEPTH`.

## Compile & Install
The project has an easy way to compile all the source code to an executable file and install it. To compile run:
```bash
make clean
```

If you want to install it directly:
```bash
make clean install
```

## Uninstall
To unistall the program, just remove the executable at the source path:
```bash
# Linux
sudo rm /usr/bin/eightgame

# MacOS
sudo rm /usr/local/bin/eightgame
```

> **Note**
> The 'make install' command is made only for Linux and MacOS. If you use Windows, modify the Makefile or copy the compiled executable file into a source path
like C:\\\Program Files.
