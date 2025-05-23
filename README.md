# Zerg Invaders

Zerg Invaders is a 2D space shooter game inspired by the classic *Space Invaders* and the *StarCraft* universe. Players control a spaceship and fight off waves of alien enemies resembling iconic Zerg units.

![Main menu](media/main_menu.png)

## 🎮 Gameplay

![Gameplay demo](media/demo.gif)

- **Controls**: Move left and right, shoot to eliminate enemies. Controls can be customized via presets.
- **Enemies**:
  - **Overlord** – flyer that provides control for lesser minions, can't attack
  - **Guardian** – long-range bomber that attacks by lobbing explosive globs of acid
  - **Broodlord** – massive manta-like flying creature that rapidly spawns large batches of scourge
  - **Queen** - support unit, increases speed of other zerg units
- **Progression**: Each level contains 40 enemies. Defeating all advances the player to a harder stage.
- **Lives**: Players start with 3 lives, which regenerate at the beginning of each new level.
- **Scoring**: Points are awarded for killing enemies. When the player loses all lives, the score is saved and encrypted.


## ✨ Features

- Infinite wave-based gameplay
- Retro-style interface with StarCraft-themed visuals and sounds
- Preset-based control rebinding (e.g. use arrow keys instead of A/D)
- Score saving with basic encryption
- Simple menu system and background music


## 🛠️ Installation and Running

### Option 1: Download release (recommended)

1. Go to the [Releases](https://github.com/Frigzer/Zerg-Invaders/releases) page
2. Download the latest `.zip` file
3. Unzip it anywhere
4. Run `ZergInvaders.exe`

No installation required – all DLLs are included.

---

### Option 2: Build from source (for developers)

1. Clone the repository:

   ```bash
   git clone https://github.com/Frigzer/Zerg-Invaders.git
2. Open the .sln file in Visual Studio.

2. Make sure SFML (from External/) is properly linked:

- External/include → Header files

- External/lib → Library files

4. Build and run using Release or Debug configuration.

---

📦 Note: The External/ folder includes SFML headers and libraries.
It can be used for local builds, especially on Windows without installing SFML system-wide.


## 📁 Project Structure

```
📦 Zerg-Invaders/
 ┣ 📂media/  
 ┣ 📂External/  
 ┃ ┣ 📂include/SFML/... – SFML headers  
 ┃ ┗ 📂lib/ – SFML static/dynamic libraries  
 ┣ 📂ZergInvaders/  
 ┃ ┣ 📂Config/ – Keybindings (left, right, shoot)  
 ┃ ┣ 📂Fonts/ – Fonts used in the game menus/UI  
 ┃ ┣ 📂Leaderboard/ – Score file (`wyniki.txt`)  
 ┃ ┣ 📂Music/ – Background music (WAV)  
 ┃ ┣ 📂Sound/ – Sound effects (WAV)  
 ┃ ┣ 📂Textures/ – All game sprites, backgrounds, icons, etc.  
 ┃ ┣ 📜main.cpp  
 ┃ ┣ 📜bullet.cpp / bullet.h  
 ┃ ┣ 📜enemy.cpp / enemy.h  
 ┃ ┣ 📜game.cpp / game.h  
 ┃ ┣ 📜menu.cpp / menu.h  
 ┃ ┣ 📜player.cpp / player.h  
 ┃ ┣ 📜scoreboard.cpp / scoreboard.h  
 ┃ ┣ 📜settings.cpp / settings.h  
 ┃ ┣ 📜window.cpp / window.h  
 ┃ ┣ 📜StringCrypter.cpp / StringCrypter.h – score encryption logic  
 ┃ ┣ 📜*.dll – required SFML dynamic libraries (for Windows builds)   
 ┗ 📜README.md – this file
```


## 🛠️ Development Notes

This game was created in C++ using the SFML graphics library as the final project for my *Fundamentals of Computer Science* course.

Although I had already passed the subject earlier (due to holding a computer technician certificate), I was still required to complete the final assignment — just earlier than most of the group. While regular students worked in teams, those of us who had passed in advance had to complete the project solo. So, I built the entire game on my own.

It was my first real experience with both object-oriented programming and the SFML library. The whole project was developed in under a week.


## 📜 License

This project is for educational and personal use only.
All StarCraft-related assets (visuals, sounds) are property of Blizzard Entertainment and are used here under fair use for non-commercial purposes.

---

## 🧩 Patch notes

🟢 v1.0.1 (Bugfix)
- Fixed crash when removing bullets/enemies
- Bullets no longer carry between levels
