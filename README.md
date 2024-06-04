# GUIZorkMM
LM173 ISE Block 4 C++ Project that's a GUI version of a Zork-like game. 

Nandakishore Vinayakrishnan - 23070854

GitHub Repo Link: https://github.com/Nanda128/GUIZorkMM.git

## Instructions:

When the game is first booted up, the user is presented with their stamina level, along with the possible
directions to go to enter the next room.

To view the character stats and inventory, the user can click on "View Character Info". To view
information relating to how to play the game, the user can click on "Help".

Clicking on "North", "South", "West", and "East" will make the player move into the room in the respective
direction that is clicked, provided there is a room in that direction. It will throw an error and send
the user back to the same room they were in when they clicked on the button if the user clicks on a button
leading to an invalid direction.

By clicking on "Teleport", the user will be teleported to a random room in the game.

Clicking on "View Map" will display the map of rooms in the game.

Clicking on "View Room Items" will list the items found in the current room, and will allow them to be picked
up and stored in the character's inventory. These items can be taken into the inventory by double-clicking on
the menu items in the widget. Likewise, the "View Character Items" button lists the items found in the player's
inventory.

The game's end states are:

- When the total weight of the items being carried by the player exceeds 15g
- If the user's stamina runs out
- If the user selects Suspect 1 in SubmissionRoom.

The winning state is when the player enters the "SubmissionRoom" room and selects Suspect 2.
