cmake_minimum_required(VERSION 3.12)
project(Monk)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monk main.cpp Characters/BaseCharacter.h Characters/Monk.h Dungeon/Dungeon.cpp Dungeon/Dungeon.h Dungeon/Room.cpp Dungeon/Room.h Characters/Monk.cpp Dungeon/DungeonGenerator.cpp Dungeon/DungeonGenerator.h Characters/Monster.cpp Characters/Monster.h Play/Combat.cpp Play/Combat.h Dungeon/DungeonSuper.cpp Dungeon/DungeonSuper.h Play/Movement.cpp Play/Movement.h Play/Run.cpp Play/Run.h)