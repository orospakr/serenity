/*
* Copyright (c) 2022, Andrew Clunis <andrew@orospakr.ca>
* Copyright (c) 2022, the SerenityOS developers.
*
* SPDX-License-Identifier: BSD-2-Clause
*/

#include "TileView.h"
#include <LibGUI/Painter.h>


REGISTER_WIDGET(Wordo, TileView);

namespace Wordo {

TileView::TileView()
{
    dbgln("TileView() in Wordo!");
    REGISTER_STRING_PROPERTY("letter", letter, set_letter);
    this->set_fixed_size(25, 25);
}

void TileView::set_letter(String letter)
{
    dbgln("TileView got letter {}", letter);
    this->m_letter = letter;
    // TODO: invalidate?
}

void TileView::paint_event(GUI::PaintEvent& event)
{
    Frame::paint_event(event);
    GUI::Painter painter(*this);
    auto& font_database = Gfx::FontDatabase::the();
    auto font = font_database.get_by_name("Liberation Serif 22 700 0");
    dbgln("Got font: {}", font);
    painter.set_font(*font);

    painter.draw_text({ 0, 0, 25, 25 }, letter(), Gfx::TextAlignment::Center, Color::Blue);
}
}