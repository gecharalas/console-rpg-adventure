# Hero's Quest: Realm of Legends

A text-based RPG adventure game where you choose your hero, battle monsters, explore a grid-based world, and trade in mystical markets.

## Game Overview

Hero's Quest: Realm of Legends is a console-based role-playing game that combines classic RPG elements with strategic combat and exploration. Choose from three unique hero classes, each with distinct abilities and progression paths, as you navigate through a 10x20 grid world filled with monsters, markets, and mysteries.

## Features

### Hero Classes
- **Warrior**: Master of physical combat with high strength and durability
- **Paladin**: Holy warrior with balanced stats and divine protection
- **Sorcerer**: Arcane spellcaster with powerful magic abilities

### World & Exploration
- **10x20 Grid World**: Navigate through a carefully crafted map
- **Multiple Tile Types**: 
  - Market tiles for trading and shopping
  - Monster encounter zones
  - Non-accessible areas
  - Safe zones for rest and recovery

### Combat System
- **Turn-based Battles**: Strategic combat against various monster types
- **Monster Variety**: 
  - Dragons: Powerful fire-breathing creatures
  - Spirits: Ethereal beings with magical abilities
  - Exoskeletons: Undead warriors with high defense
- **Combat Mechanics**:
  - Damage calculation based on strength and equipment
  - Dodge chance based on agility
  - Spell damage influenced by dexterity
  - Armor provides damage reduction

### Market & Economy
- **Trading System**: Buy and sell weapons, armor, spells, and potions
- **Inventory Management**: 4-slot inventory for both items and spells
- **Equipment System**: Dual-wield weapons or weapon + shield combinations
- **Starting Capital**: 2000 gold to begin your adventure

### Progression System
- **Experience Points**: Gain XP through battles to level up
- **Attribute Growth**: Increase strength, dexterity, and agility
- **Magic Power**: Replenishes after each battle for spellcasting
- **Permanent Enhancements**: Special potions provide lasting stat boosts

## Installation & Setup

### Prerequisites
- C++ compiler (GCC/G++ recommended)
- Code::Blocks IDE (for Windows development)
- Terminal/Command Prompt

### Compilation Instructions

#### Windows (Code::Blocks)
1. Open the project in Code::Blocks
2. Build the project (F9 or Build → Build)
3. Run the executable

#### Linux/Unix
```bash
# Navigate to project directory
cd RPG

# Compile all source files
g++ *.cpp -o heros_quest

# Run the game
./heros_quest
```

#### macOS
```bash
# Navigate to project directory
cd RPG

# Compile all source files
g++ *.cpp -o heros_quest

# Run the game
./heros_quest
```

## 🎮 How to Play

### Starting Your Adventure
1. **Hero Selection**: Choose from Warrior, Paladin, or Sorcerer
2. **Name Your Hero**: Give your character a unique name
3. **Begin Exploration**: Navigate the grid world using movement commands

### Movement Controls
- Use directional commands to move around the grid
- Navigate to different tile types for various activities
- Avoid non-accessible areas

### Combat Guide
- **Automatic Encounters**: Monsters appear when entering certain tiles
- **Battle Options**:
  - Attack with equipped weapons
  - Cast spells (if available)
  - Use potions for healing or buffs
  - Equip/unequip items during battle
- **Victory Rewards**: Gain experience points and money

### Market Trading
- **Access Markets**: Visit market tiles to trade
- **Browse Inventory**: View available weapons, armor, spells, and potions
- **Purchase Items**: Buy equipment that meets your hero's requirements
- **Sell Equipment**: Trade unwanted items for gold
- **Inventory Management**: Manage your 4-slot item and spell inventories

### Equipment System
- **Dual Wielding**: Equip weapons in both hands
- **Weapon Types**: One-handed and two-handed weapons
- **Armor**: Provides damage reduction
- **Spells**: Magical abilities for sorcerers and paladins

## Project Structure

### Core Classes
- `Hero.h/cpp`: Base hero class with common functionality
- `Warrior.h/cpp`: Warrior hero specialization
- `Paladin.h/cpp`: Paladin hero specialization  
- `Sorcerer.h/cpp`: Sorcerer hero specialization

### Combat System
- `Monster.h/cpp`: Base monster class
- `Dragon.h/cpp`: Dragon monster type
- `Spirit.h/cpp`: Spirit monster type
- `Exosceleton.h/cpp`: Exoskeleton monster type
- `fight.cpp`: Combat mechanics and battle logic

### World & Navigation
- `Grid.h/cpp`: Main game world and grid management
- `GridTile.h/cpp`: Individual tile types and properties
- `move.cpp`: Movement and navigation logic

### Items & Equipment
- `Item.h/cpp`: Base item class
- `Weapon.h/cpp`: Weapon items
- `Armor.h/cpp`: Armor items
- `Potion.h/cpp`: Consumable potions

### Magic System
- `Spell.h/cpp`: Base spell class
- `FireSpell.h/cpp`: Fire-based spells
- `IceSpell.h/cpp`: Ice-based spells
- `LightingSpell.h/cpp`: Lightning-based spells
- `SpellEffects.h/cpp`: Spell effect calculations

### Market & Economy
- `Market.h/cpp`: Market system and trading
- `market_functions.cpp`: Market interaction functions
- `more_market_functions.cpp`: Additional market features

### Data Files
- `weapons.txt`: Weapon database
- `armors.txt`: Armor database
- `spells.txt`: Spell database
- `potions.txt`: Potion database
- `names.txt`: Name generation data

## Game Tips

1. **Choose Your Hero Wisely**: Each class has unique strengths and playstyles
2. **Manage Your Resources**: Balance health, magic power, and money
3. **Visit Markets Regularly**: Upgrade your equipment as you progress
4. **Use Potions Strategically**: Some provide permanent stat boosts
5. **Explore Thoroughly**: Different areas contain various challenges and rewards
6. **Enlarge Terminal Window**: For better visual experience and readability

## Technical Details

- **Language**: C++
- **Platform**: Cross-platform (Windows, Linux, macOS)
- **Architecture**: Object-oriented design with inheritance
- **Memory Management**: Manual memory management with proper cleanup
- **File I/O**: Text-based data files for game content
- **Random Generation**: Seeded random number generation for encounters
