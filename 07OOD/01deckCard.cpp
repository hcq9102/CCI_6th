//https://godbolt.org/z/c1n58154E


#include <bits/stdc++.h>

using namespace std;

enum class Suit{HEARTS, DIAMONDS, CLUBS,SPADES,JOKER};
class Card{
    private:
        Suit suit; // 花色
        int rank; // 点数
    public:
        Card(int rank, Suit suit):rank(rank), suit(suit){}

        int getRank(){
            return rank;
        }

        Suit getSuit(){
            return suit;
        }

        string toString() const{
            if (suit == Suit::JOKER) {
                return "Joker";
            }

            string rankStr;
            if(rank ==1) rankStr = "A";
            else if(rank == 11) rankStr = "J";
            else if(rank == 12) rankStr = "Q";
            else if(rank == 13) rankStr = "K";
            else rankStr = to_string(rank);

            string suitStr;
            switch(suit){
                case Suit::HEARTS: suitStr = "Hearts"; break;
                case Suit::DIAMONDS: suitStr = "Diamonds"; break;
                case Suit::CLUBS: suitStr = "Clubs"; break;
                case Suit::SPADES: suitStr = "Spades"; break;
                default: suitStr = "Unknown";
            }

            return rankStr + " of " + suitStr;
            
        }
};

class Deck{
    protected:
        vector<Card> cards;
    public:
        Deck(){
            for(int rank = 1;rank<=13; rank ++){
                for(int suit = 0; suit <4; suit++){
                    cards.push_back(Card(rank, static_cast<Suit>(suit)));
                }
            }
            //shuffle();
        }  

        void shuffle(){
            random_device rd;
            std::mt19937 g(rd());
            std::shuffle(cards.begin(), cards.end(),g);
        }  

        Card dealCard(){
            if(cards.empty()){
                throw std::out_of_range("no more cards can be distributed ");
            }

            Card dealtCard = cards.back();
            cards.pop_back();
            return dealtCard;
        }

        // 添加一张牌
        void addCard(const Card& card) {
            cards.push_back(card);
        }

        size_t remainningCards() const{
            return cards.size();
        }
};


class BlackjackCard : public Card {
public:
    BlackjackCard(const Card& card) : Card(card) {}
    BlackjackCard(int rank, Suit suit) : Card(rank, suit) {}

    int getValue() {
        int rank = getRank();
        if (rank >= 10) return 10;
        if (rank == 1) return 11; // 起初将Ace视为11
        return rank;
    }
};

class BlackjackDeck : public Deck {
public:
    BlackjackDeck() {
        for (int rank = 1; rank <= 13; ++rank) {
            for (int suit = 0; suit < 4; ++suit) {
                addCard(BlackjackCard(rank, static_cast<Suit>(suit)));
            }
        }
        shuffle();
    }

    BlackjackCard dealCard() {
        return static_cast<BlackjackCard>(Deck::dealCard());
    }
};

class Hand {
public:
    void addCard( BlackjackCard&& card) {
        cards.push_back(std::move(card));
        int cardValue = card.getValue();
        value += cardValue;
        if (card.getRank() == 1) { // Ace
            ++aces;
        }

        while (value > 21 && aces) {
            value -= 10;
            --aces;
        }
    }

    int getValue() const {
        return value;
    }

    bool isBusted() const {
        return value > 21;
    }

    std::vector<BlackjackCard> getCards() const {
        return cards;
    }

private:
    std::vector<BlackjackCard> cards;
    int value = 0;
    int aces = 0;
};


int main() {
    BlackjackDeck deck;
    Hand playerHand;
    Hand dealerHand;

    playerHand.addCard(deck.dealCard());
    playerHand.addCard(deck.dealCard());

    dealerHand.addCard(deck.dealCard());
    dealerHand.addCard(deck.dealCard());

    std::cout << "Player's Hand: ";
    for (const auto& card : playerHand.getCards()) {
        std::cout << card.toString() << " ";
    }
    std::cout << "Value: " << playerHand.getValue() << std::endl;

    std::cout << "Dealer's Hand: ";
    for (const auto& card : dealerHand.getCards()) {
        std::cout << card.toString() << " ";
    }
    std::cout << "Value: " << dealerHand.getValue() << std::endl;

    return 0;
}



