/*
* Copyright (c) 2022, Andrew Clunis <andrew@orospakr.ca>
* Copyright (c) 2022, the SerenityOS developers.
*
* SPDX-License-Identifier: BSD-2-Clause
 */

#include "GameView.h"
#include "TileView.h"
#include <LibGUI/BoxLayout.h>

REGISTER_WIDGET(Wordo, GameView)

namespace Wordo {
    GameView::GameView() : m_try_number(0), m_tile_index(0), m_game_board(Vector<Vector<TileView*>>()) {
        for(int try_count = 0; try_count < total_tries; try_count++) {
            Vector<TileView*> tile_views;

            auto& row_container = this->add<GUI::Widget>();
            row_container.set_layout<GUI::HorizontalBoxLayout>();
            row_container.set_height(30);

            for(int tile_count = 0; tile_count < word_length; tile_count++) {
                auto& tile_view = row_container.add<Wordo::TileView>();
                tile_view.set_state(TileView::TileState::Input);
                tile_views.append(&tile_view);
            }

            m_game_board.append(tile_views);
        }

        this->set_layout<GUI::VerticalBoxLayout>();
    }

    void GameView::keyup_event(GUI::KeyEvent& event)
    {
        Widget::keyup_event(event);
        auto key_code = event.key();
        const auto *character = key_code_to_string(key_code);
        dbgln("GameView: key pressed: {}", character);

        if (event.key() == KeyCode::Key_Backspace) {
            auto previous_index = max(0, m_tile_index - 1);
            m_game_board[m_try_number][previous_index]->set_letter("");
            m_tile_index = previous_index;
            return;
        }

        VERIFY(m_tile_index < word_length);
        m_game_board[m_try_number][m_tile_index]->set_letter(character);
        if(m_tile_index < word_length - 1) {
            m_tile_index++;
        }
    }
}