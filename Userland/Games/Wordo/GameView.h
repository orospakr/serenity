/*
* Copyright (c) 2022, Andrew Clunis <andrew@orospakr.ca>
* Copyright (c) 2022, the SerenityOS developers.
*
* SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <LibGUI/Frame.h>
#include "TileView.h"

namespace Wordo {
class GameView final : public GUI::Frame {
    C_OBJECT(GameView);
public:
    virtual ~GameView() override = default;

private:
    GameView();

    int m_try_number;
    int m_tile_index;
    Vector<Vector<TileView*>> m_game_board;

    static constexpr int word_length = 5;
    static constexpr int total_tries = 6;

protected:
    void keyup_event(GUI::KeyEvent& event) override;
};
}