#include <iostream>
#include <string>
#include <vector>

// Правила Black Jack: https://add-hobby.ru/blackjack.html
// Уточнения под которые сделан код:
// игра одной колодой,
// ставок нет - только статус выигрыша,
// нет даблов и триплов,
// игра дилера с одним игроком, т.е. не более 2х человек.
// За дилера будет играть компьютер.

enum Suit {HEARTS, SPADES, CROSS, DIAMONDS}; // Черви, Пики, Крести, Буби (в этой игре не нужно)
// карта
class Card {
       int cardValue;
       bool picture=false;  // рубашкой вверх = true.
    public:
       std::string cardName;
       Suit suit;
       void flip() {picture = ! picture;}
       int getValue() {return cardValue;}
       void setValue(int val) {cardValue=val;}
//       Card & operator=(const Card & other) {
//           cardValue=other.cardValue;
//           picture=other.picture;
//	   cardName=other.cardName;
//	   suit=other.suit;
//	   return *this; 
//       }

       Card& operator=(const Card&) = default;
};

class Hand {};

class GenericPlayer : public Hand {};

// колода карт
class Deck : public Hand {
	std::vector<Card> AllCards; 
    public:
        void init();
};

// метод присваивающий значения массиву AllCards
void Deck::init() {
	  // двойки
	  Card dvaPik;
	  dvaPik.setValue(2);
	  dvaPik.cardName="2 пик";
	  dvaPik.suit=SPADES;
          AllCards[0]=dvaPik;
	  Card dvaCherv;
	  dvaCherv.setValue(2);
	  dvaCherv.cardName="2 червей";
	  dvaCherv.suit=HEARTS;
          AllCards[1]=dvaCherv;
	  Card dvaTref;
	  dvaTref.setValue(2);
	  dvaTref.cardName="2 треф";
	  dvaTref.suit=CROSS;
          AllCards[2]=dvaTref;
	  Card dvaBubey;
	  dvaBubey.setValue(2);
	  dvaBubey.cardName="2 бубей";
	  dvaBubey.suit=DIAMONDS;
          AllCards[3]=dvaBubey;
	  // тройки
	  Card triPik;
	  triPik.setValue(3);
	  triPik.cardName="3 пик";
	  triPik.suit=SPADES;
          AllCards[4]=triPik;
	  Card triCherv;
	  triCherv.setValue(3);
	  triCherv.cardName="3 червей";
	  triCherv.suit=HEARTS;
          AllCards[5]=triCherv;
	  Card triTref;
	  triTref.setValue(3);
	  triTref.cardName="3 треф";
	  triTref.suit=CROSS;
          AllCards[6]=triTref;
	  Card triBubey;
	  triBubey.setValue(3);
	  triBubey.cardName="3 бубей";
	  triBubey.suit=DIAMONDS;
          AllCards[7]=triBubey;
	  // четверки
	  Card chetirePik;
	  chetirePik.setValue(4);
	  chetirePik.cardName="4 пик";
	  chetirePik.suit=SPADES;
          AllCards[8]=chetirePik;
	  Card chetireCherv;
	  chetireCherv.setValue(4);
	  chetireCherv.cardName="4 червей";
	  chetireCherv.suit=HEARTS;
          AllCards[9]=chetireCherv;
	  Card chetireTref;
	  chetireTref.setValue(4);
	  chetireTref.cardName="4 треф";
	  chetireTref.suit=CROSS;
          AllCards[10]=chetireTref;
	  Card chetireBubey;
	  chetireBubey.setValue(4);
	  chetireBubey.cardName="4 бубей";
	  chetireBubey.suit=DIAMONDS;
          AllCards[11]=chetireBubey;
	  // пятерки
	  Card piatPik;
	  piatPik.setValue(5);
	  piatPik.cardName="5 пик";
	  piatPik.suit=SPADES;
          AllCards[12]=piatPik;
	  Card piatCherv;
	  piatCherv.setValue(5);
	  piatCherv.cardName="5 червей";
	  piatCherv.suit=HEARTS;
          AllCards[13]=piatCherv;
	  Card piatTref;
	  piatTref.setValue(5);
	  piatTref.cardName="5 треф";
	  piatTref.suit=CROSS;
          AllCards[14]=piatTref;
	  Card piatBubey;
	  piatBubey.setValue(5);
	  piatBubey.cardName="5 бубей";
	  piatBubey.suit=DIAMONDS;
          AllCards[15]=piatBubey;
	  // шестерки
	  Card shestPik;
	  shestPik.setValue(6);
	  shestPik.cardName="6 пик";
	  shestPik.suit=SPADES;
          AllCards[16]=shestPik;
	  Card shestCherv;
	  shestCherv.setValue(6);
	  shestCherv.cardName="6 червей";
	  shestCherv.suit=HEARTS;
          AllCards[17]=shestCherv;
	  Card shestTref;
	  shestTref.setValue(6);
	  shestTref.cardName="6 треф";
	  shestTref.suit=CROSS;
          AllCards[18]=shestTref;
	  Card shestBubey;
	  shestBubey.setValue(6);
	  shestBubey.cardName="6 бубей";
	  shestBubey.suit=DIAMONDS;
          AllCards[19]=shestBubey;
	  // семерки
	  Card semPik;
	  semPik.setValue(7);
	  semPik.cardName="7 пик";
	  semPik.suit=SPADES;
          AllCards[20]=semPik;
	  Card semCherv;
	  semCherv.setValue(7);
	  semCherv.cardName="7 червей";
	  semCherv.suit=HEARTS;
          AllCards[21]=semCherv;
	  Card semTref;
	  semTref.setValue(7);
	  semTref.cardName="7 треф";
	  semTref.suit=CROSS;
          AllCards[22]=semTref;
	  Card semBubey;
	  semBubey.setValue(7);
	  semBubey.cardName="7 бубей";
	  semBubey.suit=DIAMONDS;
          AllCards[23]=semBubey;
	  // восьмерки
	  Card vosemPik;
	  vosemPik.setValue(8);
	  vosemPik.cardName="8 пик";
	  vosemPik.suit=SPADES;
          AllCards[24]=vosemPik;
	  Card vosemCherv;
	  vosemCherv.setValue(8);
	  vosemCherv.cardName="8 червей";
	  vosemCherv.suit=HEARTS;
          AllCards[25]=vosemCherv;
	  Card vosemTref;
	  vosemTref.setValue(8);
	  vosemTref.cardName="8 треф";
	  vosemTref.suit=CROSS;
          AllCards[26]=vosemTref;
	  Card vosemBubey;
	  vosemBubey.setValue(8);
	  vosemBubey.cardName="8 бубей";
	  vosemBubey.suit=DIAMONDS;
          AllCards[27]=vosemBubey;
	  // девятки
	  Card deviatPik;
	  deviatPik.setValue(9);
	  deviatPik.cardName="9 пик";
	  deviatPik.suit=SPADES;
          AllCards[28]=deviatPik;
	  Card deviatCherv;
	  deviatCherv.setValue(9);
	  deviatCherv.cardName="9 червей";
	  deviatCherv.suit=HEARTS;
          AllCards[29]=deviatCherv;
	  Card deviatTref;
	  deviatTref.setValue(9);
	  deviatTref.cardName="9 треф";
	  deviatTref.suit=CROSS;
          AllCards[30]=deviatTref;
	  Card deviatBubey;
	  deviatBubey.setValue(9);
	  deviatBubey.cardName="9 бубей";
	  deviatBubey.suit=DIAMONDS;
          AllCards[31]=deviatBubey;
	  // десятки
	  Card desiatPik;
	  desiatPik.setValue(10);
	  desiatPik.cardName="10 пик";
	  desiatPik.suit=SPADES;
          AllCards[32]=desiatPik;
	  Card desiatCherv;
	  desiatCherv.setValue(10);
	  desiatCherv.cardName="10 червей";
	  desiatCherv.suit=HEARTS;
          AllCards[33]=desiatCherv;
	  Card desiatTref;
	  desiatTref.setValue(10);
	  desiatTref.cardName="10 треф";
	  desiatTref.suit=CROSS;
          AllCards[34]=desiatTref;
	  Card desiatBubey;
	  desiatBubey.setValue(10);
	  desiatBubey.cardName="10 бубей";
	  desiatBubey.suit=DIAMONDS;
          AllCards[35]=desiatBubey;
	  // валеты
	  Card valetPik;
	  valetPik.setValue(10);
	  valetPik.cardName="валет пик";
	  valetPik.suit=SPADES;
          AllCards[36]=valetPik;
	  Card valetCherv;
	  valetCherv.setValue(10);
	  valetCherv.cardName="валет червей";
	  valetCherv.suit=HEARTS;
          AllCards[37]=valetCherv;
	  Card valetTref;
	  valetTref.setValue(10);
	  valetTref.cardName="валет треф";
	  valetTref.suit=CROSS;
          AllCards[38]=valetTref;
	  Card valetBubey;
	  valetBubey.setValue(10);
	  valetBubey.cardName="валет бубей";
	  valetBubey.suit=DIAMONDS;
          AllCards[39]=valetBubey;
	  // дамы
	  Card damaPik;
	  damaPik.setValue(10);
	  damaPik.cardName="дама пик";
	  damaPik.suit=SPADES;
          AllCards[40]=damaPik;
	  Card damaCherv;
	  damaCherv.setValue(10);
	  damaCherv.cardName="дама червей";
	  damaCherv.suit=HEARTS;
          AllCards[41]=damaCherv;
	  Card damaTref;
	  damaTref.setValue(10);
	  damaTref.cardName="дама треф";
	  damaTref.suit=CROSS;
          AllCards[42]=damaTref;
	  Card damaBubey;
	  damaBubey.setValue(10);
	  damaBubey.cardName="дама бубей";
	  damaBubey.suit=DIAMONDS;
          AllCards[43]=damaBubey;
	  // короли
	  Card korolPik;
	  korolPik.setValue(10);
	  korolPik.cardName="король пик";
	  korolPik.suit=SPADES;
          AllCards[44]=korolPik;
	  Card korolCherv;
	  korolCherv.setValue(10);
	  korolCherv.cardName="король червей";
	  korolCherv.suit=HEARTS;
          AllCards[45]=korolCherv;
	  Card korolTref;
	  korolTref.setValue(10);
	  korolTref.cardName="король треф";
	  korolTref.suit=CROSS;
          AllCards[46]=korolTref;
	  Card korolBubey;
	  korolBubey.setValue(10);
	  korolBubey.cardName="король бубей";
	  korolBubey.suit=DIAMONDS;
          AllCards[47]=korolBubey;
	  // тузы
	  Card tuzPik;
	  tuzPik.setValue(10);
	  tuzPik.cardName="туз пик";
	  tuzPik.suit=SPADES;
          AllCards[48]=tuzPik;
	  Card tuzCherv;
	  tuzCherv.setValue(10);
	  tuzCherv.cardName="туз червей";
	  tuzCherv.suit=HEARTS;
          AllCards[49]=tuzCherv;
	  Card tuzTref;
	  tuzTref.setValue(10);
	  tuzTref.cardName="туз треф";
	  tuzTref.suit=CROSS;
          AllCards[50]=tuzTref;
	  Card tuzBubey;
	  tuzBubey.setValue(10);
	  tuzBubey.cardName="туз бубей";
	  tuzBubey.suit=DIAMONDS;
          AllCards[51]=tuzBubey;
	}



class Player : public GenericPlayer {
    public:
};


class House :public GenericPlayer{
   public:
};

class Game {
  public:
};


int main(int argc, char ** argv) {
    return 0;
}
