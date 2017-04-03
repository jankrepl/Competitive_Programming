#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;

////Need to define a new type that represents the suits of a card
//enum suit {C,D,H,S};


struct card{
    int value;
    char suit;
};

class hand{
    //Members
public:
    int player;
    vector<card> cards;





                                        /*METHODS*/
public:
    // Constructors

    hand() = default;

    hand(int player, string input){
        this->player = player;
        this->cards = read(input);

    }

    //Summaries
    void print_me(){
        cout << "This hand belongs to player " << this->player << endl;
        cout << "His cards are: ";
        for(vector<card>::iterator it = this->cards.begin(); it < this->cards.end(); it++){
            cout << (*it).value << (*it).suit << " ";
        }
        cout << endl;
    }

    void print_me_good(){
        print_me();


        cout << endl << " HISTOGRAM: ";
        print_vector<int>(this->histogram());


        cout << endl << " HIGHEST VALUE CARD? " <<this->high_card().first<< "      with following indeces: ";
        print_vector<bool>(this->high_card().second);

        cout << endl << " PAIR? " <<this->one_pair().first<< "      with following indeces: ";
        print_vector<bool>(this->one_pair().second);

        cout << endl << " TWO PAIRS? " <<this->two_pairs().first<< "      with following indeces for the first value: ";
        print_vector<bool>(this->two_pairs().second.first); cout << "     and  with following indeces for the second value: ";
        print_vector<bool>(this->two_pairs().second.second);



        cout << endl << " THREE OF THE KIND? " << this->three_of_a_kind().first << "      with following indeces: ";
        print_vector<bool>(this->three_of_a_kind().second);

        cout << endl << " STRAIGHT? " << this->straight();

        cout << endl << " FLUSH? " << this->flush();

        cout << endl << " FULL HOUSE? " <<this->full_house().first<< "      with following indeces for the triplet value: ";
        print_vector<bool>(this->full_house().second.first); cout << "     and  with following indeces for the double values: ";
        print_vector<bool>(this->full_house().second.second);

        cout << endl << " FOUR OF THE KIND? " << this->four_of_a_kind().first << "      with following indeces: ";
        print_vector<bool>(this->four_of_a_kind().second);

        cout << endl << " STRAIGHT FLUSH? " << this->straight_flush();

        cout << endl << " ROYAL FLUSH? " <<this->royal_flush();
        cout << endl << " The highest combo is: " <<this->maximum_combo();


    }

    // Evaluation related
    vector<card> read(string input){
        //todo
    };

    bool operator>(hand rhs){
        //todo
        int max_lhs = this->maximum_combo();
        int max_rhs = rhs.maximum_combo();

        if(max_lhs > max_rhs){
            return true;
        }else if(max_lhs == max_rhs){
            switch(max_rhs){
                default: return false;

                case 0 :{
                    //no combos...a player with the highest card wins
                    vector<int> values_rhs = rhs.extract_values(true);
                    vector<int> values_lhs = this->extract_values(true);
                    int max_value_lhs = values_lhs[4];
                    int max_value_rhs = values_rhs[4];

                    return max_value_lhs>max_value_rhs;

                }
                case 1 :{
                    vector<int> values_rhs = rhs.extract_values(false);
                    vector<int> values_lhs = this->extract_values(false);

                    vector<bool> indeces_rhs = (vector<bool> &&) rhs.one_pair().second;
                    vector<bool> indeces_lhs = (vector<bool> &&) this->one_pair().second;

                    int pair_value_lhs;
                    int pair_value_rhs;

                    for(int i = 0; i < 5; i++){
                        if(indeces_lhs[i]){
                            pair_value_lhs = values_lhs[i];
                            break;
                        }
                    }

                    for(int i = 0; i < 5; i++){
                        if(indeces_rhs[i]){
                            pair_value_rhs = values_rhs[i];
                            break;
                        }
                    }

                    return pair_value_lhs>pair_value_rhs;


                }
                case 2 :{

                }
                case 3 :{

                }
                case 4 :{

                }
                case 5 :{

                }
                case 6 :{

                }
                case 7 :{

                }
                case 8 :{

                }
                case 9 :{

                }
            }

        }else{

        }

        return false;

    };

    int maximum_combo(){
        int temp = 0;
        if(one_pair().first){
            temp = 1;
        }

        if(two_pairs().first){
            temp = 2;
        }

        if(three_of_a_kind().first){
            temp = 3;
        }

        if(straight()){
            temp = 4;
        }

        if(flush()){
            temp = 5;
        }

        if(full_house().first){
            temp = 6;
        }

        if(four_of_a_kind().first){
            temp = 7;
        }

        if(straight_flush()){
            temp = 8;
        }

        if(royal_flush()){
            temp = 9;
        }

        return temp;
    }


    vector<int> extract_values(bool sort_me){
        vector<int> temp;
        for(vector<card>::iterator it = this->cards.begin(); it < this->cards.end(); it++){
            temp.push_back((*it).value);
        }

        if(sort_me){
            sort(temp.begin(),temp.end());
        }
        return temp;

    };

    vector<char> extract_suits(){
        vector<char> temp;
        for(vector<card>::iterator it = this->cards.begin(); it < this->cards.end(); it++){
            temp.push_back((*it).suit);
        }
        return temp;

    };

    vector<int> histogram(){
        //output a 15 element vector where i-th element means the number of occurences of the card with value i...first two elements always zero
        vector<int> output(15,0);
        vector<int> values = extract_values(true);

        for(int i = 2; i <= 14; i++){
            int counter = 0;
            for(vector<int>::iterator it = values.begin(); it < values.end(); it++){
                if(*it == i){
                    counter++;
                }
            }
            output[i] = counter;
        }
        return output;
    }


    // Combo related
    pair<int,vector<bool>> high_card(){
        //int is the highest value card and then it outpits the index vector
        vector<int> values = extract_values(false);
        int max = 0;
        int index_winner = 0;
        int index = 0;
        for(vector<int>::iterator it = values.begin(); it < values.end(); it++){
            if((*it)> max){
                max = (*it);
                index_winner = index;
            }
            index++;
        }
        pair<int,vector<bool>> temp;
        temp.first = max;
        vector<bool> temp_bool(5,false);
        temp_bool[index_winner] = true;
        temp.second = temp_bool;
        return temp;
    };

    pair<bool,vector<bool>> one_pair(){
        //Only one pair and nothing more
        //Idea is to search for 2 in the histogram twice..first time from the beginning ..second tim
        vector<int> values = extract_values(false);
        vector<int> histogram = this->histogram();

        vector<int>::iterator found_first = find(histogram.begin(),histogram.end(),2);
        vector<int>::iterator found_second;

        if(found_first != histogram.end()){
            found_second = find(found_first + 1, histogram.end(),2);
        }else{
            found_second = found_first;
        }

        pair<bool,vector<bool>> temp;

        if(found_first != histogram.end() && found_second == histogram.end()){
            temp.first = true;
            //wee need to find the two cards that have value equal to
            int card_value = distance(histogram.begin(), found_first);
            int first_index = distance(values.begin(),find(values.begin(),values.end(),card_value));
            int second_index = distance(values.begin(),find(find(values.begin(),values.end(),card_value) + 1,values.end(),card_value));


            vector<bool> temp_bool(5,false);
            temp_bool[first_index] = true;
            temp_bool[second_index] = true;
            temp.second = temp_bool;
            return temp;

        }else{
            temp.first = false;
            vector<bool> temp_bool(5,false);
            temp.second = temp_bool;
            return temp;
        }

    };

    pair<bool,pair<vector<bool>,vector<bool>>> two_pairs(){
        //
        vector<int> values = extract_values(false);
        vector<int> histogram = this->histogram();

        vector<int>::iterator found_first = find(histogram.begin(),histogram.end(),2);
        vector<int>::iterator found_second;

        if(found_first != histogram.end()){
            found_second = find(found_first + 1, histogram.end(),2);
        }else{
            found_second = found_first;
        }

        pair<bool,pair<vector<bool>,vector<bool>>> temp;

        if(found_first != histogram.end() && found_second != histogram.end()){
            temp.first = true;
            //first value lookup
            int card_value_1 = distance(histogram.begin(), found_first);
            int first_index_1 = distance(values.begin(),find(values.begin(),values.end(),card_value_1));
            int second_index_1 = distance(values.begin(),find(find(values.begin(),values.end(),card_value_1) + 1,values.end(),card_value_1));
            //second value lookup
            int card_value_2 = distance(histogram.begin(), found_second);
            int first_index_2 = distance(values.begin(),find(values.begin(),values.end(),card_value_2));
            int second_index_2 = distance(values.begin(),find(find(values.begin(),values.end(),card_value_2) + 1,values.end(),card_value_2));

            vector<bool> temp_bool_1(5,false);
            vector<bool> temp_bool_2(5,false);
            temp_bool_1[first_index_1] = true;
            temp_bool_1[second_index_1] = true;
            temp_bool_2[first_index_2] = true;
            temp_bool_2[second_index_2] = true;

            temp.second.first = temp_bool_1;
            temp.second.second = temp_bool_2;
            return temp;

        }else{
            temp.first = false;
            vector<bool> temp_bool_1(5,false);
            vector<bool> temp_bool_2(5,false);

            temp.second.first = temp_bool_1;
            temp.second.second = temp_bool_2;
            return temp;
        }
    };

    pair<bool,vector<bool>> three_of_a_kind(){
        //EXACTLY THREE
        vector<int> histogram = this->histogram();

        vector<int>::iterator found_pure = find(histogram.begin(),histogram.end(),3);

        pair<bool,vector<bool>> temp;

        if(found_pure == histogram.end()){
            temp.first = false;
            vector<bool> temp_vector(5,false);
            temp.second = temp_vector;
            return temp;
        }else{//one is not the same
            temp.first = true;

            vector<int> values = extract_values(false);
            //This value is there only once
            int trice = distance(histogram.begin(),find(histogram.begin(),histogram.end(),3));
            int included_1  = distance(values.begin(),find(values.begin(),values.end(), trice));
            int included_2  = distance(values.begin(),find(find(values.begin(),values.end(), trice) + 1,values.end(), trice));
            int included_3  = distance(values.begin(),find(find(find(values.begin(),values.end(), trice) + 1,values.end(), trice) + 1,values.end(), trice));
            //there are two types...four of a kind pure or five of a kind
            vector<bool> temp_vector(5,false);
            temp_vector[included_1] = true;
            temp_vector[included_2] = true;
            temp_vector[included_3] = true;
            temp.second = temp_vector;
            return temp;
        }
    };

    bool straight(){
        vector<int> values = extract_values(true);

        for(int i = 1; i <= 4; i++){
            if(values[i] - values[i-1] != 1){
                return false;
            }
        }
        return true;
    };

    bool flush(){
        vector<char> suits = extract_suits();

        vector<char> rf_suits(5,suits[0]);

        return rf_suits == suits;

    };

    pair<bool,pair<vector<bool>,vector<bool>>> full_house(){
        //THREE OF A KIND
        //EXACTLY THREE
        vector<int> histogram = this->histogram();

        vector<int>::iterator found_double = find(histogram.begin(),histogram.end(),2);
        vector<int>::iterator found_triple = find(histogram.begin(),histogram.end(),3);

        pair<bool,pair<vector<bool>,vector<bool>>> temp;

        if(found_double != histogram.end() && found_triple != histogram.end()){
            temp.first = true;


            vector<int> values = extract_values(false);
            int trice = distance(histogram.begin(),find(histogram.begin(),histogram.end(),3));
            int three_index_1 = distance(values.begin(),find(values.begin(),values.end(), trice));
            int three_index_2  = distance(values.begin(),find(find(values.begin(),values.end(), trice) + 1,values.end(), trice));
            int three_index_3  = distance(values.begin(),find(find(find(values.begin(),values.end(), trice) + 1,values.end(), trice) + 1,values.end(), trice));

            int twice = distance(histogram.begin(),find(histogram.begin(),histogram.end(),2));
            int twice_index_1 = distance(values.begin(),find(values.begin(),values.end(), twice));
            int twice_index_2  = distance(values.begin(),find(find(values.begin(),values.end(), twice) + 1,values.end(), twice));

            vector<bool> temp_bool_1(5,false);
            vector<bool> temp_bool_2(5,false);
            temp_bool_1[three_index_1] = true;
            temp_bool_1[three_index_2] = true;
            temp_bool_1[three_index_3] = true;
            temp_bool_2[twice_index_1] = true;
            temp_bool_2[twice_index_2] = true;
            temp.second.first = temp_bool_1;
            temp.second.second = temp_bool_2;
            return temp;


        }else{
            temp.first = false;
            vector<bool> temp_bool_1(5,false);
            vector<bool> temp_bool_2(5,false);
            temp.second.first = temp_bool_1;
            temp.second.second = temp_bool_2;
            return temp;
        }

//        vector<int> histogram = this->histogram();
//
//        vector<int>::iterator found_pure = find(histogram.begin(),histogram.end(),3);
//
//        pair<bool,vector<bool>> temp;
//
//        if(found_pure == histogram.end()){
//            temp.first = false;
//            vector<bool> temp_vector(5,false);
//            temp.second = temp_vector;
//            return temp;
//        }else{//one is not the same
//            temp.first = true;
//
//            vector<int> values = extract_values(false);
//            //This value is there only once
//            int trice = distance(histogram.begin(),find(histogram.begin(),histogram.end(),3));
//            int included_1  = distance(values.begin(),find(values.begin(),values.end(), trice));
//            int included_2  = distance(values.begin(),find(find(values.begin(),values.end(), trice) + 1,values.end(), trice));
//            int included_3  = distance(values.begin(),find(find(find(values.begin(),values.end(), trice) + 1,values.end(), trice) + 1,values.end(), trice));
//            //there are two types...four of a kind pure or five of a kind
//            vector<bool> temp_vector(5,false);
//            temp_vector[included_1] = true;
//            temp_vector[included_2] = true;
//            temp_vector[included_3] = true;
//            temp.second = temp_vector;
//            return temp;

        // Pair
//        vector<int> values = extract_values(false);
//        vector<int> histogram = this->histogram();
//
//        vector<int>::iterator found_first = find(histogram.begin(),histogram.end(),2);
//        vector<int>::iterator found_second;
//
//        if(found_first != histogram.end()){
//            found_second = find(found_first + 1, histogram.end(),2);
//        }else{
//            found_second = found_first;
//        }
//
//        pair<bool,vector<bool>> temp;
//
//        if(found_first != histogram.end() && found_second == histogram.end()){
//            temp.first = true;
//            //wee need to find the two cards that have value equal to
//            int card_value = distance(histogram.begin(), found_first);
//            int first_index = distance(values.begin(),find(values.begin(),values.end(),card_value));
//            int second_index = distance(values.begin(),find(find(values.begin(),values.end(),card_value) + 1,values.end(),card_value));
//
//
//            vector<bool> temp_bool(5,false);
//            temp_bool[first_index] = true;
//            temp_bool[second_index] = true;
//            temp.second = temp_bool;
//            return temp;
//
//        }else{
//            temp.first = false;
//            vector<bool> temp_bool(5,false);
//            temp.second = temp_bool;
//            return temp;
//        }
    };

    pair<bool,vector<bool>> four_of_a_kind(){
        //FOUR OR FIVE
        vector<int> histogram = this->histogram();

        vector<int>::iterator found_pure = find(histogram.begin(),histogram.end(),4);
        vector<int>::iterator found_above = find(histogram.begin(),histogram.end(),5);

        pair<bool,vector<bool>> temp;

        if(found_pure == histogram.end() && found_above == histogram.end()){
            temp.first = false;
            vector<bool> temp_vector(5,false);
            temp.second = temp_vector;
            return temp;
        }else if(found_pure != histogram.end()){//one is not the same
            temp.first = true;

            vector<int> values = extract_values(false);
            //This value is there only once
            int once = distance(histogram.begin(),find(histogram.begin(),histogram.end(),1));
            int not_included  = distance(values.begin(),find(values.begin(),values.end(), once));
            //there are two types...four of a kind pure or five of a kind
            vector<bool> temp_vector(5,true);
            temp_vector[not_included] = false;
            temp.second = temp_vector;
            return temp;
        }else{ // all five the same value
            temp.first = true;
            vector<bool> temp_vector(5,true);
            temp.second = temp_vector;
            return temp;
        }

    };

    bool straight_flush(){
    //DONE
        vector<int> values = extract_values(true);
        vector<char> suits = extract_suits();

        vector<char> sf_suits(5,suits[0]);

        if(sf_suits != suits){
            return false;
        }

        for(int i = 1; i <= 4; i++){
            if(values[i] - values[i-1] != 1){
                return false;
            }
        }
        return true;
    };

    bool royal_flush(){
    //DONE
        vector<int> values = extract_values(true);
        vector<char> suits = extract_suits();

        vector<int> rf_values({10,11,12,13,14});
        vector<char> rf_suits(5,suits[0]);

        return values == rf_values && suits == rf_suits;


    };
};

pair<hand,hand> string_to_hands(string one_line){
    string player_one = one_line.substr(0,14);
    string player_two = one_line.substr(15,14);

    //Player 1 card strings
    hand player_1_hand;
    player_1_hand.player = 1;
    vector<card> player_1_cards;

    for(int i = 0; i < 5; i++){
        card current_card;
        //extract the suit character
        current_card.suit = (player_one.substr(i*3 + 1,1))[0];
        //extract the value
        if('T' == (player_one.substr(i * 3, 1))[0]){
            current_card.value = 10;

        }else if('J' == (player_one.substr(i * 3, 1))[0]){
            current_card.value = 11;

        }else if('Q' == (player_one.substr(i * 3, 1))[0]){
            current_card.value = 12;

        }else if('K' == (player_one.substr(i * 3, 1))[0]){
            current_card.value = 13;

        }else if('A' == (player_one.substr(i * 3, 1))[0]){
            current_card.value = 14;

        }else{
            current_card.value = (int)((player_one.substr(i * 3, 1))[0]) - 48;
        }
        player_1_cards.push_back(current_card);

    }

    //Player 2 card strings
    hand player_2_hand;
    player_2_hand.player = 2;
    vector<card> player_2_cards;

    for(int i = 0; i < 5; i++){
        card current_card;
        //extract the suit character
        current_card.suit = (player_two.substr(i*3 + 1,1))[0];
        //extract the value
        if('T' == (player_two.substr(i * 3, 1))[0]){
            current_card.value = 10;

        }else if('J' == (player_two.substr(i * 3, 1))[0]){
            current_card.value = 11;

        }else if('Q' == (player_two.substr(i * 3, 1))[0]){
            current_card.value = 12;

        }else if('K' == (player_two.substr(i * 3, 1))[0]){
            current_card.value = 13;

        }else if('A' == (player_two.substr(i * 3, 1))[0]){
            current_card.value = 14;

        }else{
            current_card.value = (int)((player_two.substr(i * 3, 1))[0]) - 48;
        }
        player_2_cards.push_back(current_card);

    }
    player_1_hand.cards = player_1_cards;
    player_2_hand.cards = player_2_cards;

    return make_pair(player_1_hand,player_2_hand);

};
int main() {
    int counter =  0;
    int game_counter = 1;
    string temp;
    ifstream my_input_file("/Users/jankrepl/Desktop/Pjogjamovani/C++/Problem Solving/Project Euler/text_for_54.txt");

    while(getline(my_input_file, temp)){
        //importing a line
        pair<hand,hand> hands;
        hands = string_to_hands(temp);
        hand player1 = hands.first;
        hand player2 = hands.second;

        cout << "       GAME NUMBER: " << game_counter << endl;
        game_counter++;
        player1.print_me();
        player2.print_me();


        if(player1 > player2){
            counter++;
            cout << "   Player 1 won";
        }
        if(player2 > player1){
            cout << "   Player 2 won";
        }

        if(!(player1 > player2) && !(player2 > player1)){
            cout << "Jan! You need to help me! Who won?" << endl;
            int input;
            cin >> input;
            if(input == 1){
                counter++;
                cout << "Ok, player one won ..I believe you, Jan";
            }else if(input == 2){
                cout << "Ok, player two won ..I believe you, Jan";

            }else{
                cout << "you put in some bbulshit and now youre fucked";
            }
        }
        cout << endl;


    }

    cout << "END. Player 1 won " << counter << " times!!";

    


}


