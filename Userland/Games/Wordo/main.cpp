/*
 * Copyright (c) 2022, Andrew Clunis <andrew@orospakr.ca>
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibGUI/Application.h>
#include <LibMain/Main.h>
#include <LibConfig/Client.h>
#include <LibCore/System.h>
#include <LibGUI/Icon.h>
#include <LibGUI/BoxLayout.h>
#include <LibGUI/Statusbar.h>
#include <LibGUI/Window.h>
#include <Games/Wordo/WordoGML.h>
#include <Games/Wordo/GameView.h>
#include <stdio.h>

ErrorOr<int> serenity_main(Main::Arguments arguments) {
    TRY(Core::System::pledge("stdio recvfd sendfd rpath unix"));

    auto app = TRY(GUI::Application::try_create(arguments));
    auto app_icon = TRY(GUI::Icon::try_create_default_icon("app-wordo"));
    auto window = TRY(GUI::Window::try_create());

    window->set_title("Wordo");   

    window->set_icon(app_icon.bitmap_for_size(16));

    auto widget = TRY(window->try_set_main_widget<GUI::Widget>());
    widget->load_from_gml(wordo_gml);

    auto& game = *widget->find_descendant_of_type_named<Wordo::GameView>("game");
    window->set_focused_widget(&game);

    window->show();
    return app->exec();
}