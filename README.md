# Game of Life

## Introduction
The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. This implementation provides a basic simulation environment to explore the fascinating emergent behaviors of this simple yet powerful model.

## Features
- Simulation of Conway's Game of Life.
- Customizable map sizes and initial configurations.
- Several predefined structures like Gliders, Pulsars, and Still Lifes.

## Installation

Clone the repository to your local machine:

```
git clone https://github.com/Nixential/Game-Of-Life-C.git GameOfLife
cd GameOfLife
```

Compile the project using the provided Makefile:

```
make
```

## Usage

To run the Game of Life simulation:

```
./GameOfLife maps/glider.gol
```

Replace `maps/glider.gol` with the path to any other `.gol` map file you wish to use as the initial configuration.

## Contributing

Contributions to the Game of Life project are welcome! Here are some ways you can contribute:

- Reporting bugs
- Suggesting enhancements
- Adding new patterns to the `maps/` directory
- Improving the documentation

Please feel free to fork the repository and submit pull requests.

## License

This project is open source and available under the [MIT License](LICENSE).

## Acknowledgments

- John Horton Conway, for the original concept of the Game of Life.
- Contributors and community members who have/will submit issues, pull requests, and provided feedback.

Thank you for your interest in the Game of Life simulation project!

## How to Use

### Game of Life Simulation

After compiling the project with `make`, you can run the Game of Life simulation in several ways:

1. **Default Configuration:**

   Simply run the program without any arguments to start the simulation with a default 9x9 grid.

   ```
   ./GameOfLife
   ```

2. **Custom Grid Size:**

   Provide the number of columns and rows as arguments to start the simulation with a custom grid size.

   ```
   ./GameOfLife <num_cols> <num_rows>
   ```

   Replace `<num_cols>` and `<num_rows>` with your desired grid dimensions. For example, to start a simulation with a 20x20 grid:

   ```
   ./GameOfLife 20 20
   ```

3. **Using a Map File:**

   You can also start the simulation with a predefined map by providing the path to a `.gol` file as an argument.

   ```
   ./GameOfLife maps/glider.gol
   ```

   Replace `maps/glider.gol` with the path to any `.gol` map file.

### Generating Custom Maps with Perl Script

The `gol_generator.pl` Perl script allows you to generate `.gol` map files with predefined structures like gliders, pulsars, etc. To use it:

1. Navigate to the `maps` directory:

   ```
   cd maps
   ```

2. Run the Perl script with the desired structure as an argument. Available structures include `glider`, `beacon`, `pulsar`, etc.

   ```
   perl gol_generator.pl <structure_name>
   ```

   Replace `<structure_name>` with the name of the structure you want to generate. For example, to generate a map with a glider:

   ```
   perl gol_generator.pl glider > glider.gol
   ```

   This will create a `.gol` file in the current directory with the specified structure.