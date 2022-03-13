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
    this->m_state = TileState::Unrevealed;
    dbgln("TileView() in Wordo!");
    REGISTER_STRING_PROPERTY("letter", letter, set_letter);
    REGISTER_ENUM_PROPERTY("state", state, set_state, TileView::TileState,
        { TileState::Unrevealed, "Unrevealed" },
        { TileState::Input, "Input" },
        { TileState::MatchedLetter, "MatchedLetter"},
        { TileState::Revealed, "Revealed"});

    auto& font_database = Gfx::FontDatabase::the();
    this->tileFont = font_database.get_by_name("Liberation Serif 22 700 0");
    VERIFY(this->tileFont);
    this->set_fixed_size(30, 30);
}

void TileView::set_letter(String letter)
{
    dbgln("TileView got letter {}", letter);
    this->m_letter = letter;
    // TODO: invalidate?
}

void TileView::set_state(TileState state) {
    this->m_state = state;
    // TODO: invalidate?
}


void TileView::paint_event(GUI::PaintEvent& event)
{
    Frame::paint_event(event);
    GUI::Painter painter(*this);

    Color fill_color;
    Color text_color = Color::White;
    switch(m_state) {
    case TileState::Unrevealed:
        painter.fill_rect({0, 0, 30, 30 }, Color::Black);
        return;
    case TileState::Input:
        fill_color = Color::Black;
        break;
    case TileState::MatchedLetter:
        fill_color = Color(180, 159, 59);
        break;
    case TileState::Revealed:
        fill_color = Color(83, 141, 78);
        break;
    }

    painter.set_font(*(this->tileFont));
    painter.fill_rect({0, 0, 30, 30 }, fill_color);
    painter.draw_text({ 3, 3, 25, 25 }, letter(), Gfx::TextAlignment::Center, text_color);
}
}