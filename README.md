# Chess-GUI (C++ with SFML)

## About the Project
Chess-GUI is a simple graphical chess game built using **C++** and the **SFML** library. This game provides an interactive UI for playing chess against another player or integrating an external chess engine like **Stockfish**.

## Features
- Fully functional chessboard with a graphical interface.
- Supports two-player mode.
- Option to integrate chess engines (e.g., **Stockfish**).
- Smooth and responsive UI.
- Standard chess rules implementation.

## Prerequisites
To run this project, you need the following:
- **C++ Compiler** (MinGW for Windows, g++ for Linux/macOS)
- **SFML Library** ([Download Here](https://www.sfml-dev.org/download.php))
- **Stockfish Engine** (Optional for AI gameplay) - [Download Here](https://stockfishchess.org/download/)

## Installation & Setup

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/shubham-shipt/Chess-GUI.git
   cd Chess-GUI
   ```

2. **Install SFML**
   - **Windows:** Follow SFML setup guide with MinGW.
   - **Linux:**
     ```sh
     sudo apt-get install libsfml-dev
     ```
   - **macOS:**
     ```sh
     brew install sfml
     ```

3. **Compile the Game:**
   ```sh
   g++ -std=c++17 main.cpp -o chess -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. **Run the Game:**
   ```sh
   ./chess
   ```

## Using a Chess Engine (Stockfish)
To enhance gameplay, integrate Stockfish:
1. **Download Stockfish** from the [official website](https://stockfishchess.org/download/).
2. **Place the executable** in the project directory.
3. **Modify the Code** to interface with the engine and enable AI-based moves.

## Controls
- Click on a piece to select it.
- Click on a valid move to place the piece.
- The game follows standard chess rules.

## Screenshots



## Contact
For queries or improvements, contact:
- **GitHub:** [shubham-shipt](https://github.com/shubham-shipt)
- **Email:** your.email@example.com

