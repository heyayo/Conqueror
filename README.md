# Conqueror's Dungeon
A game made for Module DX1124 Interactive Story Telling using Raylib

## How to compile
Using CMake:
```
mkdir build ( Create a folder in the repo or somewhere else, the groupName can be anything )
cmake -S [repo] -B [the folder you made above]
cmake --build [groupName of folder]
```
OR
```
Open Repo Folder in IDE
If IDE supports CMake, use the CMakeLists.txt has compile target and compile

Visual Studio:
Ensure you have CMAKE for Windows on Visual Studio. You can check by running the Visual Studio Installer, Modify Install, Under Individual Components, Find CMAKE for Windows.
After Installing CMAKE for Windows, Right click on the repo folder and open in Visual Studio.
VS should recognise the CMAKE File.
Right click on the small arrow to the right of the Run Program Button with the green arrow and select Prototype.exe as the Target.
VS Should Proceed to Compile the Program.
```

# Documentation

## Classes

### Entity Class
Almost everything Inherits from this Class, it contains a texture data, position and rotation.

It includes Getter and Setter Functions for needed values

Is an Abstract Class.

Has Parenting System, using
```
SetParent();
GetParent();
```

Initialize the Entity using the Init Functions
```
--- IMPORTANT ---
All Sprites must be PNG Format, Raylib does not support jpg
--- IMPORTANT ---

Init(string imagelink); // Example - Init("sprites/arrow.png");

Init(Image var); // Initializes using an Image Variable
// Example
// Image img = LoadImage("sprites/archer.png");
// Init(img);

Init(string imagelink, V2 resize); // Initializes using an image link and resizes it, Example - Init("sprites/archer.png", V2(128,128));
```

### Physical - Child to Entity
A basic Entity but with Collision Ability.

Set a collision boxSize using these functions:
```
// Automatically Sets the Collision Hitbox based off the Size of the Provided Texture
// Use this if you don't need to change hitbox sizes
AutoCollider();
```
```
// Sets a square hitbox of provided boxSize, the boxSize is should be measured from the center
// E.G. Texture of 128x128 should have a hitbox boxSize of 64
SetCollisionSize(int boxSize);
```
```
// Sets a rectangular hitbox using the Vector2 Size
// Proportions are the same as above
SetCollisionSize(V2 boxSize);
```

--- IMPORTANT ---

To use a child class of Physical, they must have these two Functions
```
// Runs once right before the object spawns
Start();

// Runs every frame
Update();
```
--- IMPORTANT ---

This is an Abstract Class

### StaticBody - Child to Physical
I can't remember why I made this, but I think its supposed to be a class for stuff that doesnt move, like walls and doors

### Player - Child to Physical
This is the example player class and is the class you see moving with WASD
The InputHandler Class is for Categorization and is not necessary.

### Arrow - Child to Physical
This class is an example of making a Projectile
It spawns at the position of the parent class and travels forwards based on Parent Rotation

### UIElement - Child to Entity
WORK IN PROGRESS
This is the parent class to all UI Elements

Class Functions:
```
CalculateMouseCollision(); // Calculates if the mouse is hover the object
```

### TextBox - Child to UIElement
This is a class for easily creating a textbox

To Create a TextBox
```
TextBox [groupName] = new TextBox("INSERT TEXT HERE");
```

TextBox Functions
```
SetTextColor(Color color); // Sets the Text Color
SetBoxColor(Color color); // Sets the Box Color
SetPadding(V2 padding); // Sets the padding around the text
SetText(const char* text); // Sets Text in the TextBox
SetFont(Font font); // Sets the font of the text
SetFontSize(float fontSize); // Sets the font size
SetTextPosition(V2 pos); // Sets the Text Position, ONLY WORKS IF ALIGNMENT IS SET TO CUSTOM
SetAlignment(Alignment align); // Sets the Alignment of the Text

ALIGNMENT OPTIONS
TOPLEFT - aka unaligned
CENTER
CUSTOM
```

Using the UIElement Mouse Checking Function, it can be made into a button

### Scene
This is the base Scene Class containing required Scene Functions

--- IMPORTANT ---

All Children must have these functions:
```
// Like Update but for Scenes
SceneUpdate();
// This should handle Collisions Only
Collision();

--- IMPORTANT ---

Is Abstract

### TestScene - Child to Scene
This is the example for making a new scene

# NON CLASSES
## Game
This is a collection of functions meant for bridging connections between classes that would otherwise cause a Circular Include Error

## Maths
This namespace is a collection of Math Functions that can probably be found as a better version somewhere else but remade for the sake of OOP Marks

# CREATING A NEW CLASS
First, Determine what class are you trying to make.

If a normal game thing like an enemy, weapon or wall:
Create a new Class consisting of a h/hpp and cpp pair
Make the new class a child to Physical
If a UIElement, like healthbars or text:
Don't make a new class, use the existing classes that fulfill this functionality (WIP)

## Adding the new class to the game
In the Constructor of the Scene you wanna add the class to, do
```
Entity* [anyname] = new [CLASS];
[anyname]->Init([INSERTTEXTURE]); // The Init Function has Three Varieties, Refer to Entity Class Above
AddPhysical([anyname]
```
There is no need to delete the pointer, it is handled by the Scene Class
