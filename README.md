# A*
This is a simple A* implementation in C++.

## Compile

From the project root:
```
cmake CMakeList.txt && make
```

The executable should be found under the `bin` folder.

## Run 

The program is waiting for a parameter with the path of the file containing the map:

```
a-star <filename.txt>
```

## Input file format

The program is expecting a specific file format. The first line must be the width of the square grid.
The grid must contain:

* `x` for an obstacle
* `m` for the starting point
* `p` for the goal
* `-` for empty cells

## Output

The output is a set of instruction to get to the goal.