# Progress

## Presentation

Progress is an open version of the popular MMORPG Ingress.

## Supported Qt versions

Progress has been tested with:
* Qt 4.7.4
* Qt 5.3.1

## Supported platforms

Progress is been developed for:
* Linux (Qt GCC 5.3 64bit)
* Android (Qt 5.3.1 armeabi-v7a GCC 4.8)
* Symbian (Qt 4.7.4 for Symbian Anna with armv5)

## Compiling and running

This is a standard Qt project with no extra dependency. It can be built within QtCreator or from the command line:
* `$ git clone https://github.com/fdugast/Progress`
* `$ cd src/`
* `$ qmake progress.pro`
* `$ make`



- in the deployment configuration, add the extra library liQtOpenGL
