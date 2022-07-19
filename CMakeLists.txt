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
                src/tiles/Tile.cc
                src/tiles/BaseTile.cc
                src/tiles/DegreeTile.cc
                src/tiles/TileDecorator.cc
                src/tiles/TrapTile.cc
                src/board/Board.cc
                src/display/Display.cc
                src/player/Player.cc
                src/player/PlayerOptions.cc
                src/utils/Observer.cc
                )
target_include_directories(goose_party PRIVATE include)

target_link_libraries(goose_party
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
)
