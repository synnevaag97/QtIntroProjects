# QtIntroProjects
This repo takes on various Qt intro projects to learn Qt. 

The first four tasks is mainly QML programming to learn the language and some of its modules or elements. 

- Traffic Light
- Mouse Events
- Anchors
- QML Tutorial
- Qt Widget Tutorial
- TicTacToe
- Morse Code Converter
- Site Crawler

## Install
Follow this guide for windows 11:
https://www.youtube.com/watch?v=OoVNt-KJ96w

or this for ubuntu 22.04:
https://www.youtube.com/watch?v=sjApF6qnyUI

## Traffic Light
Task based on https://www.qt.io/product/qt6/qml-book/ch05-fluid-states-transitions. A simple traffic light.  

Introduces states and transitions when using QML in Qt Quick. 

## Mouse Events
https://doc.qt.io/qt-6/qtquick-input-mouseevents.html
We can define a specific area to detect events from the mouse. The area can react on specific signals:
- canceled
- clicked
- doubleClicked
- entered
- exited
- positionChanged
- pressAndHold
- pressed
- released
    
We can define callback functions for all of these events. 


## Anchors
https://doc.qt.io/qt-6/qtquick-positioning-anchors.html

Task to understands anchors of containers and how to change anchors with states and transitions. 


##  QML Tutorial
The QML tutorial found at https://doc.qt.io/qt-6/qml-tutorial1.html. 


## Qt Widget Tutorial
https://doc.qt.io/qt-6/widgets-tutorial.html

For more details on item models visit: https://doc.qt.io/qt-6/examples-itemviews.html
For more detail on model/view programming visit: https://doc.qt.io/qt-6/model-view-programming.html



## TicTacToe
Creating a TicTacToe game. 

Inspiration for TicTacToe bots: https://thesharperdev.com/coding-the-perfect-tic-tac-toe-bot/

| Task  | Name | Description | Completed |
| ------------- |  ------------- | ------------- | ------------- |
| 1 | Simple functioning version | Simple tictactoe that declares a winner with 3 in a row.  | ✅ |
| 2 | Pop up window| Create a pop up window declaring winner and a tie.| ✅ |
| 3   | Menu| Create a menu that start the game and closes the game.  | ✅ |
| 4   | Play computer | Play against a computer that choose random tiles. | ✅|
| 5 | One layer computer | Picks if there is a one winner move or else random.  | ✅ | 
| 6 | Two layer computer | Picks if there is a one winner move, blocks a winning move for the opponent otherwise random.  |✅ | 
| 7 | AI computer | Play against a optimal computer. You never win. | ✅ | 
| 8   | Menu with 1 and 2 player | Create a menu that can choose to play computer (1 player) or against friend (2 player) | ✅ |
| 9 | Player registration | | ✅  |
| 10 | Player scoreboard | Games played, games won, games lost, games tied. | ✅ |
| 11 | Adjustable boardsize | Let the user decide the size of the board. |  |


 [InGameVideo.webm](https://github.com/synnevaag97/QtIntroProjects/assets/72789025/33b5c7c3-cfef-449b-9eef-5d939349d010)


## Morse Code Converter
An interactive morse converter that can convert English letters to morse code; the user can type either, and gets the converted text displayed in real time. The app can also play the morse code.

![MorseConverter](https://github.com/synnevaag97/QtIntroProjects/assets/72789025/2e0b3e9f-1e4f-4480-af75-a94a869cdb06)



## Site Crawler
A site crawler for the online Qt documentation, starting at https://doc.qt.io/qt-6/classes.html, extracting and following all the links, and storing the information in a machine-readable format that allows comparison between different versions.
