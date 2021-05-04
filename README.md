# Ikaruga

##### A light-weight clone of the bullet hell shooter game.

<img src="https://i.imgur.com/pSzG1XM.png" alt="screenshot of game" width="400"/>

<!-- TABLE OF CONTENTS -->

## Table of Contents

- [Dependencies](#dependencies)
- [Project Setup](#project-setup)
- [Controls](#controls)

## Dependencies

- [gcc](https://gcc.gnu.org/) or [clang](https://clang.llvm.org/ ) or [MSVC 2015+]("https://www.visualstudio.com/")
- [cmake](https://cmake.org/)

### Ubuntu

```
 $ sudo apt-get install gcc cmake
```

### MacOS

```
$ brew install gcc cmake
```

### Windows

- [Visual Studio 2015+](https://visualstudio.microsoft.com/)

## Project Setup

#### Linux

```
$ git clone https://github.com/uiuc-sp21-cs126/final-project-rishisek-illinois.git
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ ./ikaruga
```

#### Windows

```
> git clone https://github.com/uiuc-sp21-cs126/final-project-rishisek-illinois.git
> mkdir build
> cd build
> cmake ..
> cmake --build .
> .\ikaruga
```

## Controls

### Player Movement

| Key | Action |
|-----|--------|
| `W` | Up |
| `A` | Left |
| `S` | Down |
| `D` | Right |

### Bullet Action

| Key | Action |
|-----|--------|
| `ENTER` `RETURN` | Fire a bullet |
| `RSHIFT` | Switch bullet type |
| `LEFT` | Tilt aim left |
| `RIGHT` | Tilt aim right |