cmake_minimum_required (VERSION 3.11)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v3.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(goose_party
  LANGUAGES CXX
  VERSION 1.0.0
)

add_executable(goose_party
        src/main.cc
        src/game/Game.cc
        src/game/DebugGame.cc
        src/cards/Card.cc
        src/cards/SpellCard.cc
        src/cards/TrapCard.cc
        src/tiles/Tile.cc
        src/tiles/BaseTile.cc
        src/tiles/DegreeTile.cc
        src/tiles/GradeTile.cc
        src/tiles/AbilityTile.cc
        src/tiles/CardTile.cc
        src/tiles/HealthTile.cc
        src/tiles/BeaconTile.cc
        src/tiles/TileDecorator.cc
        src/tiles/TrapTile.cc
        src/board/Board.cc
        src/display/Display.cc
        src/player/Player.cc
        src/player/PlayerOptions.cc
        src/player/BasePlayer.cc
        src/player/PlayerDecorator.cc
        src/beacon/Beacon.cc
        src/beacon/TuitionBeacon.cc
        src/beacon/ExamBeacon.cc
        src/player/ability/GradeCurve.cc
        src/player/ability/BonusMarks.cc
        src/player/ability/GoodSleep.cc
        src/player/ability/AllNighter.cc
        src/player/ability/TimeManagement.cc
        src/player/ability/Attendance.cc
        src/player/ability/PerfectGpa.cc
        src/player/ability/CopyCat.cc
        src/player/ability/Distracting.cc
        src/utils/Observer.cc
        src/utils/Utils.cc include/utils/Utils.h)
target_include_directories(goose_party PRIVATE include)

target_link_libraries(goose_party
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
)
