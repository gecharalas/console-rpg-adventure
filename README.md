Below is a revised version of the README, formatted and structured to be compatible with a GitHub repository:

---

# Market Overview

The Market comprises two main vectors: Items and Spells, respectively. It offers a user-friendly Market Menu, allowing players to explore the available products within the Market. This menu becomes accessible when the player is on a Market-type grid tile. Besides, the Market facilitates methods for buying and selling the hero's items/spells.

## Features

- **Browse and Interact**: Players can easily browse through the Market's offerings, with each item/spell assigned a specific number to minimize selection errors.
- **Purchase Mechanism**: If the hero meets the minimum requirements to acquire an item/spell, the purchase is executed, storing the item/spell in the respective inventory, occupying an inventory slot, and deducting the cost from the hero's wallet.
- **Sales Functionality**: Players can sell items/spells from their inventory or those equipped, with a simple number input for inventory items or specific selection for equipped items (like weapons or armors).

## Hero Configuration

- The hero is characterized by two vectors: ItemsInventory and SpellsInventory, each with a capacity of four slots.
- The hero possesses two pointers, `right_hand` and `left_hand`, representing the hero's ability to equip items like one-handed swords or shields, with special consideration for double-handed weapons.
- The hero can equip/unequip items during battle without losing a turn but loses the turn if a potion is used.

## Gameplay Dynamics

- The game supports single-hero selection and one-on-one monster battles.
- Initial setup grants the hero 2000 gold for market transactions.
- A custom, consistent grid map enhances the game's aesthetic and predictability.
- Certain potions permanently enhance the hero's attributes like health, dexterity, agility, or strength.
- The hero's Magic Power replenishes after each battle, aiding in ongoing gameplay.
- In-game messages guide the player, negating the need for an external user manual.
- It is advised to enlarge the terminal window for a better visual experience.

## Technical Details

- The game is tailored for Windows 10, developed using Code::Blocks.
- For Linux execution:
  - Compile with `g++ *.cpp`
  - Run with `./a.out`

---

Ensure to adapt the content according to your project specifics and GitHub's markdown styling for optimal presentation. This format highlights key aspects of your game, structured in a way that's conducive to the GitHub environment.
