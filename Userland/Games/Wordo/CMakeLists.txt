serenity_component(
    Wordo
    RECOMMENDED
    TARGETS Wordo
)

set(SOURCES
    main.cpp
)

serenity_app(Wordo ICON app-wordo)
target_link_libraries(Wordo LibConfig LibGUI LibGfx LibCore LibMain)