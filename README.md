<div class="languages" align="center">

# Eight-puzzle-game

:uk: <a href="#">English</a>
:es: <a href="https://github.com/dpv927/eight-puzzle-game/edit/main/esREADME.md">Español</a>
</div>

## About
Unlike other apps that solve the 8-puzzle, this app allows you to specify the final state of the board and the goal state. 
The search tree is developed with the <ins>A* algorithm</ins>, giving the least expensive solution (talking about the number of moves).

## How to use
The solver expects two inputs (initial and final states of the board) as a string. For example, the string "123456780" (Obviously without the quotes ("")) will
respresent the following board: 
```
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+   Note: A spot with '0' indicates that there is 
| 4 | 5 | 6 |   no chip in that position on the board.
+---+---+---+
| 7 | 8 | 0 |
+---+---+---+
```

Then the solver will show the initial and final states of the board that where specified, the exact path from the given start to the solution with each step depth and
some search info like `CREATED_NODES`, `EXPANDED_NODES` and `SOLUTION_DEPTH`.

## Compile & Install
The project has a easy way to compile all the source code to a executable file and install it. To compile run:
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
> The 'make install' command is made only for Linux and MacOS. If you use Windows, modify the Makefile or copy the compiled execulable file into a source path
like C:\\\Program Files.
