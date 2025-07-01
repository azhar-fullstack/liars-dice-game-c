# Liar's Dice Game

A complete implementation of the classic Liar's Dice game in C, featuring an AI opponent and interactive command-line interface.

## 🎲 Game Overview

Liar's Dice is a classic bluffing game where players roll dice and make bets about the total number of dice showing a particular value. Players can either raise the bet or call "bluff" if they think the previous player is lying.

## ✨ Features

- **Complete Game Implementation**: Full Liar's Dice game with all core mechanics
- **AI Opponent**: Intelligent computer player with decision-making algorithms
- **Interactive Interface**: Command-line based user interface
- **Bet Validation**: Ensures all bets follow game rules
- **Game State Management**: Tracks dice, bets, and player status
- **Win/Lose Conditions**: Complete game flow with victory detection

## 🛠️ Technical Implementation

### Core Components

- **Player Structure**: Manages player dice and game state
- **Dice Rolling**: Random number generation for dice simulation
- **Bet Validation**: Algorithm to ensure valid betting sequences
- **AI Logic**: Computer opponent decision-making system
- **Game Loop**: Complete game flow management

### Key Algorithms

- **Dice Counting**: Efficient counting of dice values
- **Bet Validation**: Ensures bets follow game rules (higher quantity or same quantity with higher value)
- **AI Decision Making**: Random but valid bet generation
- **Bluff Detection**: Calculates total dice to determine bluff outcomes

## 🚀 Getting Started

### Prerequisites

- C compiler (GCC, Clang, or MSVC)
- Standard C libraries

### Compilation

```bash
gcc -o liarDisc liarDisc.c
```

### Running the Game

```bash
./liarDisc
```

## 🎮 How to Play

1. **Game Setup**: Each player starts with 5 dice
2. **Dice Rolling**: Both players roll their dice at the start of each round
3. **AI First Bet**: The computer makes the initial bet
4. **Your Turn**: Choose to either:
   - **Raise (0)**: Make a higher bet
   - **Call Bluff (1)**: Challenge the current bet
5. **Betting Rules**: Each bet must be higher than the previous one
6. **Winning**: Last player with dice remaining wins

### Game Commands

- `0` - Raise the bet
- `1` - Call bluff
- Enter bet format: `[quantity] [dice_value]` (e.g., "3 4" for three 4's)

## 💻 Code Structure

```c
// Core data structures
typedef struct {
    int dice[MAX_DICE];
    int num_dice;
} Player;

// Key functions
void roll_dice(Player* player);           // Roll dice for a player
int count_dice(Player* player, int value); // Count specific dice values
int is_valid_bet(int new_num, int new_val, int cur_num, int cur_val); // Validate bets
void ai_make_bet(int *bet_num, int *bet_val, int cur_num, int cur_val); // AI decision making
```

## 🔧 Technical Features

- **Memory Management**: Efficient use of C structs and pointers
- **Random Number Generation**: Proper seeding and dice simulation
- **Input Validation**: Robust handling of user input
- **Modular Design**: Clean separation of game logic and interface
- **Error Handling**: Graceful handling of invalid inputs

## 🎯 Skills Demonstrated

- **C Programming**: Advanced use of structs, pointers, and functions
- **Algorithm Design**: Game logic and AI decision-making
- **Problem Solving**: Complex game rule implementation
- **Software Engineering**: Clean, maintainable code structure
- **Interactive Systems**: Command-line interface design

## 📁 Project Structure

```
liarDisc/
├── liarDisc.c      # Main game implementation
├── liarDisc.exe    # Compiled executable (Windows)
└── README.md       # This file
```

## 🤝 Contributing

This is a portfolio project demonstrating C programming skills. Feel free to fork and enhance the game with additional features like:
- Multiple AI difficulty levels
- Network multiplayer support
- GUI interface
- Statistics tracking
- Sound effects

## 📄 License

This project is open source and available under the MIT License.

---

**Author**: Azhar Mehmood  
**Language**: C  
**Category**: Game Development, Algorithms, Interactive Systems 
