@GUI::Widget {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {

    }

    @GUI::Widget {
        layout: @GUI::HorizontalBoxLayout {

        }

        @Wordo::TileView {
            name: "test0"
            letter: "W"
            state: "Revealed"
        }

        @Wordo::TileView {
            name: "test1"
            letter: "O"
            state: "MatchedLetter"
        }

        @Wordo::TileView {
            name: "test2"
            letter: "R"
            state: "Input"
        }

        @Wordo::TileView {
            name: "test3"
            letter: "D"
            state: "Revealed"
        }

        @Wordo::TileView {
            name: "test4"
            letter: "O"
            state: "MatchedLetter"
        }
    }

    @GUI::Statusbar {
        name: "statusbar"
    }
}