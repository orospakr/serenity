@GUI::Widget {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {

    }

    @GUI::Widget {
        layout: @GUI::HorizontalBoxLayout {

        }

        @Wordo::LetterView {
            name: "test0"
            letter: "W"
        }

        @Wordo::LetterView {
            name: "test1"
            letter: "O"
        }

        @Wordo::LetterView {
            name: "test2"
            letter: "R"
        }

        @Wordo::LetterView {
            name: "test3"
            letter: "D"
        }

        @Wordo::LetterView {
            name: "test4"
            letter: "O"
        }
    }

    @GUI::Statusbar {
        name: "statusbar"
    }
}