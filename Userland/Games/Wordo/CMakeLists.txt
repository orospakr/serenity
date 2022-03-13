serenity_component(
    Wordo
    DESCRIPTION "5-letter word guessing game"
    RECOMMENDED
    TARGETS Wordo
)

compile_gml(Wordo.gml WordoGML.h wordo_gml)

set(SOURCES
    main.cpp
    TileView.cpp
    GameView.cpp
    WordoGML.h
)

serenity_app(Wordo ICON app-wordo)
target_link_libraries(Wordo LibConfig LibGUI LibGfx LibCore LibMain)