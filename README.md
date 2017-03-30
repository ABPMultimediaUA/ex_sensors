# Simple Enemy Sensor Implementation in C++

This code is an application example for the implementation of simple sensors for enemies. It shows a simple maze game with different types of enemies and walls. The EnemySensor type has a seeing sensor and is able to see players in its looking at direction.

![Screenshot of an enemy looking at a Player using its sight sensor](/media/gamescr00.png?raw=true "An enemy sees a player and stops moving, exemplifying the sight sensor implementation")


## Explanation

This example was used during Computer Games lessons of the [Multimedia Degree](https://cvnet.cpd.ua.es/webcvnet/planestudio/planEstudioND.aspx?plan=C205&lengua=E&caca=2016-17) at the [University of Alicante](http://www.ua.es). You may want to check out the [associated C++ lesson video (in Spanish)](https://youtu.be/mPapuUC0kLg):

[![Francisco Gallego's Computer Games Lesson at the University of Alicante](https://img.youtube.com/vi/mPapuUC0kLg/0.jpg "Watch Francisco Gallego's lesson on Computer Games at the University of Alicante (in Spanish)")](https://youtu.be/mPapuUC0kLg)

## Compilation requisites

In order to compile this code you require:
- A Linux/*Nix operative system (Win10 bash may do the job)
- CMake 3.2 or greater
- A compiler supporting C++11 or greater (GNU GCC is recommended)
- NCurses library and its development headers

## Compilation instructions

1. Enter project folder
2. Create a build subfolder (`mkdir bin/`)
3. Enter build subfolder (`cd bin/`)
4. Launch CMake (`cmake ../src/`)
5. If CMake succeeded, run make (`make`)
6. If build succeeded, run minimaze game (`./minimaze`)

## Copyright and License

(c) 2017 Francisco Gallego 

This code is distributed under GNU-GPL v3 License.
