cmake_minimum_required(VERSION 3.13)
project(Monk2)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Monk2 main.cpp Characters/BaseCharacter.h Characters/Monk.cpp Characters/Monk.h Characters/Monster.cpp Characters/Monster.h Dungeon/Dungeon.cpp Dungeon/Dungeon.h Dungeon/DungeonGenerator.cpp Dungeon/DungeonGenerator.h Dungeon/DungeonSuper.cpp Dungeon/DungeonSuper.h Dungeon/Room.cpp Dungeon/Room.h Play/Combat.cpp Play/Combat.h Play/Movement.cpp Play/Movement.h Play/Run.cpp Play/Run.h FileOut.h FileOut.cpp)