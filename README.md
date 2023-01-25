# eight-puzzle-game
## About
Unlike other apps that solve the 8-puzzle, this app allows you to specify the final state of the board and the goal state. 
At the moment, only the A* algorithm is available to solve the puzzle, although more are expected in the future, such as 'Greedy Best' and others.

## How to use
The solver expects two inputs (initial and final states of the board) as a string. For example, the string "123456780" wiill
respresent the following board.
```
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+
| 4 | 5 | 6 |
+---+---+---+
| 7 | 8 | 0 |
+---+---+---+
```
Then the solver will show the initial and final states of the board that where specified, the exact path from the given start to the solution and
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

## Unistall
To unistall the program, just remove the executable at /usr/bin
```bash
# Linux
sudo rm /usr/bin/eightgame

# MacOS
/usr/local/bin/eightgame
```
