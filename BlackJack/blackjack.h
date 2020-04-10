using namespace std;
#include <vector>

enum Rank
{
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};
enum Type
{
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES,
};

class Card
{
protected:
    enum Rank rank;
    enum Type type;

public:
    Card(Rank rank, Type type);
    int getValue();
    void displayCard();
};

class Hand
{
protected:
    vector<Card> cards;

public:
    void add(Card card);
    void clear();
    int getTotal();
    void displayHand();
};

class Deck : public Hand
{
protected:
    vector<Card> deck;

public:
    void Populate();
    void shuffle();
    Card deal();
};

class AbstractPlayer : public Hand
{
public:
    Hand hand;

public:
    virtual bool isDrawing() = 0;
    bool isBusted();
};

class ComputerPlayer : public AbstractPlayer
{
public:
    bool isDrawing();
};

class HumanPlayer : public ComputerPlayer
{
public:
    bool isDrawing();
    void announce(char &status, int compTotal);
};

class BlackJackGame
{
private:
    Deck m_deck;
    ComputerPlayer m_casino;
    HumanPlayer m_player;

public:
    void play();
};
