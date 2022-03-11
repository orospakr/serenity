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
#include <stdio.h>

ErrorOr<int> serenity_main(Main::Arguments arguments) {
    TRY(Core::System::pledge("stdio recvfd sendfd rpath unix"));

    auto app = TRY(GUI::Application::try_create(arguments));
    auto app_icon = TRY(GUI::Icon::try_create_default_icon("app-wordo"));
    auto window = TRY(GUI::Window::try_create());

    window->set_title("Wordo");   

    window->set_icon(app_icon.bitmap_for_size(16));
    // window->resize(300, 300);

    auto widget = TRY(window->try_set_main_widget<GUI::Widget>());
    widget->load_from_gml(wordo_gml);


    window->show();



    // auto main_widget = TRY(window->try_set_main_widget<GUI::Widget>());
    // (void)TRY(main_widget->try_set_layout<GUI::VerticalBoxLayout>());
    // main_widget->set_fill_with_background_color(true);

    return app->exec();
}