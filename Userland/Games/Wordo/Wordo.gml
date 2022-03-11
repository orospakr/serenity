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
        }

        @Wordo::TileView {
            name: "test1"
            letter: "O"
        }

        @Wordo::TileView {
            name: "test2"
            letter: "R"
        }

        @Wordo::TileView {
            name: "test3"
            letter: "D"
        }

        @Wordo::TileView {
            name: "test4"
            letter: "O"
        }
    }

    @GUI::Statusbar {
        name: "statusbar"
    }
}