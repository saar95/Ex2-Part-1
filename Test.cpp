#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;
#include <iostream>
#include <stdexcept>

using ariel::Direction;


ariel::Board board;
TEST_CASE("Empty board->before entering any values") {
	CHECK(board.read(0, 0, Direction::Horizontal, 8) == " ");//==________
	CHECK(board.read(5, 6, Direction::Horizontal,1) == " ");//==_
	CHECK(board.read(0, 8, Direction::Vertical, 5) == " ");//==_____
	CHECK(board.read(9, 9, Direction::Horizontal, 1) == " ");//==_
	CHECK(board.read(9,9, Direction::Vertical, 1) == " ");//==_
	CHECK(board.read(1,5, Direction::Vertical, 3) == " ");//==___
}

TEST_CASE("Good case") {
	board.post(0, 0, Direction::Horizontal, "saarbarel");
	CHECK(board.read(0, 0, Direction::Horizontal, 9) == " ");//==saarbarel
	CHECK(board.read(0, 4, Direction::Horizontal, 6) == " ");//==barel_
	board.post(1, 6, Direction::Horizontal, "ron");
	CHECK(board.read(1, 6, Direction::Horizontal, 3) == " ");//==ron
	board.post(1, 4, Direction::Vertical, "efrat");
	CHECK(board.read(1, 4, Direction::Vertical, 5) == " ");//==efrat
	board.post(9, 6, Direction::Horizontal, "yoni");
	CHECK(board.read(9, 6, Direction::Horizontal, 4) == " ");//==yoni
	board.post(7, 0, Direction::Horizontal, "yossicohen");
	CHECK(board.read(7, 0, Direction::Horizontal, 10) == " ");//==yossicohen
	CHECK(board.read(7, 5, Direction::Horizontal, 5) == " ");//==cohen
	board.post(3, 9, Direction::Vertical, "omer");
	CHECK(board.read(3, 9, Direction::Vertical, 4) == " ");//==omer
	board.post(4, 0, Direction::Vertical, "ziv");
	CHECK(board.read(4, 0, Direction::Vertical, 4) == " ");//==zivy
	CHECK(board.read(4, 0, Direction::Horizontal, 10) == " ");//==z___a____m
	CHECK(board.read(0, 4, Direction::Vertical, 10) == " ");//==befrat_i__
	CHECK(board.read(0, 6, Direction::Vertical, 5) == " ");//==rr___
	
	


}

TEST_CASE("Good post code with Overriding values") {
	board.post(0, 0, Direction::Horizontal, "haya");//override saar to haya
	CHECK(board.read(4, 0, Direction::Horizontal, 10) == " ");//==hayabarel
	board.post(4, 0, Direction::Horizontal, "sara cohen");//override lane 9
	CHECK(board.read(9, 0, Direction::Horizontal, 10) == " ");//==sara cohen
	board.post(2, 9, Direction::Vertical, "amit");//overide col 9
	CHECK(board.read(2, 9, Direction::Vertical, 8) == " ");//==amitrn_n
	board.post(1, 5, Direction::Horizontal, "uriya");//overide lane 1
	CHECK(board.read(1, 0, Direction::Horizontal, 10) == " ");//==____euriya
	board.post(3, 4, Direction::Vertical, "shoham");//overide col 4
	CHECK(board.read(0, 4, Direction::Vertical, 8) == " ");//==befshoham_
	CHECK(board.read(7, 0, Direction::Horizontal, 5) == " ");//==yossa
	

}
TEST_CASE("random msg length and random location") {

}

// TEST_CASE("Wrong post code") {
// 	CHECK_THROWS(board.post('c', 'd', Direction::Horizontal, "xxx"));
// 	CHECK_THROWS(board.post(-1, -2, Direction::Horizontal, "abc"));
// 	CHECK_THROWS(board.post(2, -8, Direction::Vertical, "xxx"));
// }
// TEST_CASE("Wrong read code") {
// 	CHECK_THROWS(board.read(-2, 1, Direction::Horizontal, 3));
// 	CHECK_THROWS(board.read(-3, -5, Direction::Horizontal, 1));
// 	CHECK_THROWS(board.read(1, -4, Direction::Vertical, 5));
// }



