// BlackJack Game by Nicholas Nikas
#include <iostream>
#include "blackjack.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Card class Implementations

Card::Card(Rank rank, Type type)
{
    this->rank = rank;
    this->type = type;
}

int Card::getValue()
{
    int value = 0;
    Rank rank = this->rank;
    switch (rank)
    {
    case ACE:
        value = 11;
        break;
    case TWO:
        value = 2;
        break;
    case THREE:
        value = 3;
        break;
    case FOUR:
        value = 4;
        break;
    case FIVE:
        value = 5;
        break;
    case SIX:
        value = 6;
        break;
    case SEVEN:
        value = 7;
        break;
    case EIGHT:
        value = 8;
        break;
    case NINE:
        value = 9;
        break;
    case TEN:
        value = 10;
        break;
    case JACK:
        value = 10;
        break;
    case QUEEN:
        value = 10;
        break;
    case KING:
        value = 10;
        break;
    }

    return value;
}

void Card::displayCard()
{
    Rank rank = this->rank;
    Type type = this->type;

    switch (rank)
    {
    case ACE:
        cout << '1';
        break;
    case TWO:
        cout << '2';
        break;
    case THREE:
        cout << '3';
        break;
    case FOUR:
        cout << '4';
        break;
    case FIVE:
        cout << '5';
        break;
    case SIX:
        cout << '6';
        break;
    case SEVEN:
        cout << '7';
        break;
    case EIGHT:
        cout << '8';
        break;
    case NINE:
        cout << '9';
        break;
    case TEN:
        cout << "10";
        break;
    case JACK:
        cout << 'J';
        break;
    case QUEEN:
        cout << 'Q';
        break;
    case KING:
        cout << 'K';
        break;
    }

    switch (type)
    {
    case CLUBS:
        cout << 'C';
        break;
    case DIAMONDS:
        cout << 'D';
        break;
    case HEARTS:
        cout << 'H';
        break;
    case SPADES:
        cout << 'S';
        break;
    }
}

// Hand class Implementations

void Hand::add(Card card)
{
    this->cards.push_back(card);
}
void Hand::clear()
{
    this->cards.clear();
}
int Hand::getTotal()
{
    int total = 0;
    int aceCount = 0;
    for (int i = 0; i < this->cards.size(); i++)
    {
        // count how many aces are in hand
        if (this->cards[i].getValue() == 11)
        {
            aceCount++;
        }
        total += this->cards[i].getValue();
    }

    // make ace be valued at 1 if total exceeds 21
    for (int i = 0; i < aceCount; i++)
    {
        if (total > 21)
        {
            total -= 10;
        }
    }
    return total;
}

// helper method to print all card of a hand
void Hand::displayHand()
{
    for (int i = 0; i < this->cards.size(); i++)
    {
        this->cards[i].displayCard();
        cout << " ";
    }
}

// Deck class Implementations

void Deck::Populate()
{
    for (int type = CLUBS; type <= SPADES; type++)
    {
        for (int rank = ACE; rank <= KING; rank++)
        {
            this->deck.push_back(Card((Rank)rank, (Type)type));
        }
    }
}

void Deck::shuffle()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    auto gen = std::default_random_engine(seed);
    std::shuffle(this->deck.begin(), this->deck.end(), gen);
}
Card Deck::deal()
{
    Card dealt = this->deck[0];
    this->deck.erase(this->deck.begin());
    return dealt;
}

// AbstractPlayer class Implementations

bool AbstractPlayer::isBusted()
{
    if (this->hand.getTotal() > 21)
    {
        return true;
    }
    return false;
}

// HumanPlayer class Implementations

bool HumanPlayer::isDrawing()
{
    char answer;
    bool descision;
    cout << "Do you want to draw? (y/n): ";
    cin >> answer;
    cout << endl
         << endl;
    descision = (answer == 'y' ? true : false);
    return descision;
}

void HumanPlayer::announce(char &status, int compTotal)
{
    if (isBusted())
    {
        // player is busted
        status = 'B';
        cout << "Player busts." << endl;
        cout << "Casino wins." << endl;
    }
    else if (compTotal > 21)
    {
        // computer busts
        status = 'B';
        cout << "Casino busts." << endl;
        cout << "Player wins." << endl;
    }
    else if (this->hand.getTotal() == 21 && compTotal == 21)
    {
        // push tie game
        status = 'P';
        cout << "Push: No one wins." << endl;
    }
    else
    {
        // no one has reached 21 or busted
        status = 'U';
    }
}

bool ComputerPlayer::isDrawing()
{
    if (ComputerPlayer::hand.getTotal() <= 16)
    {
        return true;
    }
    return false;
}

// BlackJackGame class Implementations

void BlackJackGame::play()
{
    // populate and shuffle deck
    // clear deck before every new round
    this->m_deck.clear();
    this->m_deck.Populate();
    this->m_deck.shuffle();

    // clear hand before every start of game
    this->m_casino.hand.clear();
    this->m_player.hand.clear();

    // Initial logic for start of game

    // COMPUTER LOGIC
    // deal first card to computer and add to hand
    this->m_casino.hand.add(this->m_deck.deal());
    cout << "Casino: ";
    // display hand and value of hand
    this->m_casino.hand.displayHand();
    cout << " [";
    cout << this->m_casino.hand.getTotal();
    cout << "]" << endl;

    // PLAYER LOGIC
    cout << "Player: ";
    // deal first card and add to players hand
    this->m_player.hand.add(this->m_deck.deal());
    // deal a second card and add to players hand
    this->m_player.hand.add(this->m_deck.deal());
    // display hand and value of hand
    this->m_player.hand.displayHand();
    cout << " [";
    cout << this->m_player.hand.getTotal();
    cout << "]" << endl;

    // character to determine status of game
    char status = 'X';

    // continue dealing while player decides to draw
    while (this->m_player.isDrawing())
    {
        cout << "Player: ";
        // deal and add to hand
        this->m_player.hand.add(this->m_deck.deal());
        // display hand and value of hand
        this->m_player.hand.displayHand();
        cout << " [";
        cout << this->m_player.hand.getTotal();
        cout << "]" << endl;
        //update status of game
        this->m_player.announce(status, this->m_casino.hand.getTotal());

        if (status == 'B')
        {
            // exit game if player is busted since over
            return;
        }
        else if (this->m_player.hand.getTotal() == 21)
        {
            // player has 21, move to casinos turn
            break;
        }
    }

    while (this->m_casino.isDrawing())
    {
        // deal card to computer and add to hand
        this->m_casino.hand.add(this->m_deck.deal());
        cout << "Casino: ";
        // display hand and value of hand
        this->m_casino.hand.displayHand();
        cout << " [";
        cout << this->m_casino.hand.getTotal();
        cout << "]" << endl;
    }
    // announce final status of game
    this->m_player.announce(status, this->m_casino.hand.getTotal());

    // no player has reached 21 or busted, we decide winner on higher score
    if (status == 'U')
    {
        if (this->m_player.hand.getTotal() > this->m_casino.hand.getTotal())
        {
            // player wins with score under 21
            cout << "Player wins." << endl;
        }
        else if (this->m_player.hand.getTotal() < this->m_casino.hand.getTotal())
        {
            // casino wins with score under 21
            cout << "Casino wins." << endl;
        }
        else if (this->m_player.hand.getTotal() == this->m_casino.hand.getTotal())
        {
            cout << "Push: No one wins." << endl;
        }
    }
}
