/*
* Copyright (c) 2022, Andrew Clunis <andrew@orospakr.ca>
* Copyright (c) 2022, the SerenityOS developers.
*
* SPDX-License-Identifier: BSD-2-Clause
*/

#pragma once

#include <LibGUI/Frame.h>
#include <LibGfx/Font.h>


namespace Wordo {



class TileView final : public GUI::Frame {
    C_OBJECT(TileView)
public:
    enum class TileState {
        Unrevealed,

        Input,

        MatchedLetter,

        Revealed
    };

    virtual ~TileView() override = default;

    String letter() const { return m_letter; }
    void set_letter(String letter);

    TileState state() const { return m_state; }
    void set_state(TileState state);
private:
    TileView();

protected:
    void paint_event(GUI::PaintEvent& event) override;

private:
    String m_letter;
    TileState m_state;
    RefPtr<Gfx::Font> tileFont;


};
}