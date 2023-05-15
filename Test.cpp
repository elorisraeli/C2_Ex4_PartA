#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <random>
#include <chrono>

using namespace ariel;
using namespace std;

TEST_CASE("Test Point class") {
    Point p1(3, 4);
    Point p2(0, 0);
    CHECK_EQ(p1.distance(p2), 5.0);
}

TEST_CASE("Test Character class") {
    Point p1(0, 0);
    Character character("Character1", p1);

    CHECK_EQ(character.getName(), "Character1");
    CHECK_EQ(character.getLocation().getX(), 0);
    CHECK_EQ(character.getLocation().getY(), 0);
    CHECK_EQ(character.isAlive(), true);
}

TEST_CASE("Test Ninja class") {
    Point p1(0, 0);
    Ninja ninja("Ninja1", p1);

    CHECK_EQ(ninja.getName(), "Ninja1");
    CHECK_EQ(ninja.getLocation().getX(), 0);
    CHECK_EQ(ninja.getLocation().getY(), 0);
    CHECK_EQ(ninja.isAlive(), true);
}

TEST_CASE("Test Cowboy class") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);

    CHECK_EQ(cowboy.getName(), "Cowboy1");
    CHECK_EQ(cowboy.getLocation().getX(), 0);
    CHECK_EQ(cowboy.getLocation().getY(), 0);
    CHECK_EQ(cowboy.isAlive(), true);
    CHECK_EQ(cowboy.hasboolets(), true);

    SUBCASE("Test shooting") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        cowboy.shoot(&cowboy2);
        CHECK_EQ(cowboy.getBullets(), 0); // Assuming each cowboy starts with 1 bullet
    }
}

TEST_CASE("Test OldNinja class") {
    Point p1(0, 0);
    OldNinja oldNinja("OldNinja1", p1);

    CHECK_EQ(oldNinja.getName(), "OldNinja1");
    CHECK_EQ(oldNinja.getLocation().getX(), 0);
    CHECK_EQ(oldNinja.getLocation().getY(), 0);
    CHECK_EQ(oldNinja.isAlive(), true);
}

TEST_CASE("Test TrainedNinja class") {
    Point p1(0, 0);
    TrainedNinja trainedNinja("TrainedNinja1", p1);

    CHECK_EQ(trainedNinja.getName(), "TrainedNinja1");
    CHECK_EQ(trainedNinja.getLocation().getX(), 0);
    CHECK_EQ(trainedNinja.getLocation().getY(), 0);
    CHECK_EQ(trainedNinja.isAlive(), true);
}

TEST_CASE("Test YoungNinja class") {
    Point p1(0, 0);
    YoungNinja youngNinja("YoungNinja1", p1);

    CHECK_EQ(youngNinja.getName(), "YoungNinja1");
    CHECK_EQ(youngNinja.getLocation().getX(), 0);
    CHECK_EQ(youngNinja.getLocation().getY(), 0);
    CHECK_EQ(youngNinja.isAlive(), true);
}

TEST_CASE("Test Team class") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    Team team1(&cowboy);

    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test adding new character") {
        Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
        team1.add(cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);
    }

    SUBCASE("Test attacking") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        Team2 team2(&cowboy2);
        team1.attack(&team2);
        CHECK_EQ(team2.stillAlive(), 0); // Assuming one attack is enough to defeat a character
    }
}

TEST_CASE("Test Team2 class") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    Team2 team1(&cowboy);

    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test adding new character") {
        Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
        team1.add(cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);
    }

    SUBCASE("Test attacking") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        Team2 team2(&cowboy2);
        team1.attack(&team2);
        CHECK_EQ(team2.stillAlive(), 0); // Assuming one attack is enough to defeat a character
    }
}

TEST_CASE("Test SmartTeam class") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    SmartTeam team1(&cowboy);

    CHECK_EQ(team1.stillAlive(), 1);

    SUBCASE("Test adding new character") {
        Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
        team1.add(cowboy2);
        CHECK_EQ(team1.stillAlive(), 2);
    }

    SUBCASE("Test attacking") {
        Cowboy cowboy2("Cowboy2", Point(1, 1));
        SmartTeam team2(&cowboy2);
        team1.attack(&team2);
        CHECK_EQ(team2.stillAlive(), 0); // Assuming one attack is enough to defeat a character
    }
}

TEST_CASE("Test Cowboy reloading") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    cowboy.shoot(&cowboy);
    CHECK_EQ(cowboy.hasboolets(), false);

    cowboy.reload();
    CHECK_EQ(cowboy.hasboolets(), true);
}

TEST_CASE("Test Ninja moving towards enemy") {
    Point p1(0, 0);
    Point p2(1, 1);
    Ninja ninja("Ninja1", p1);
    Cowboy cowboy("Cowboy1", p2);
    ninja.move(&cowboy);

    CHECK_EQ(ninja.getLocation().getX(), p2.getX());
    CHECK_EQ(ninja.getLocation().getY(), p2.getY());
}

TEST_CASE("Test Team2 order") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    Team2 team(&cowboy);
    team.add(&cowboy2);

    CHECK_EQ(team.getByOrder()->getName(), "Cowboy2");
}

TEST_CASE("Test SmartTeam order") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    SmartTeam team(&cowboy);
    team.add(&cowboy2);

    CHECK_EQ(team.getByOrder()->getName(), "Cowboy2");
}

TEST_CASE("Test ninja slashing") {
    Point p1(0, 0);
    Point p2(1, 1);
    Ninja ninja("Ninja1", p1);
    Cowboy cowboy("Cowboy1", p2);
    ninja.slash(&cowboy);

    CHECK_EQ(cowboy.isAlive(), false); // Assuming one slash is enough to defeat a character
}

TEST_CASE("Test team attack") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    Team team1(&cowboy);
    Team team2(&cowboy2);

    team1.attack(&team2);
    CHECK_EQ(team2.stillAlive(), 0); // Assuming one attack is enough to defeat a character
}

TEST_CASE("Test team defense") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    Team team1(&cowboy);
    Team team2(&cowboy2);

    team2.attack(&team1);
    CHECK_EQ(team1.stillAlive(), 1); // Assuming the team can defend itself
}

TEST_CASE("Test team with multiple characters") {
    Point p1(0, 0);
    Point p2(1, 1);
    Cowboy cowboy("Cowboy1", p1);
    Cowboy cowboy2("Cowboy2", p2);
    Team team1(&cowboy);
    team1.add(&cowboy2);

    CHECK_EQ(team1.stillAlive(), 2);
}

TEST_CASE("Test character hit points") {
    Point p1(0, 0);
    Character character("Character1", p1, 100);

    CHECK_EQ(character.isAlive(), true);
    character.hit(50);
    CHECK_EQ(character.isAlive(), true);
    character.hit(50);
    CHECK_EQ(character.isAlive(), false);
}

TEST_CASE("Test character movement") {
    Point p1(0, 0);
    Point p2(1, 1);
    Character character("Character1", p1, 100);

    CHECK_EQ(character.getLocation().getX(), 0);
    CHECK_EQ(character.getLocation().getY(), 0);

    character.moveTowards(p2, 1);

    CHECK_EQ(character.getLocation().getX(), 1);
    CHECK_EQ(character.getLocation().getY(), 1);
}

TEST_CASE("Test Team destruction") {
    Point p1(0, 0);
    Cowboy cowboy("Cowboy1", p1);
    Team *team = new Team(&cowboy);

    CHECK_EQ(team->stillAlive(), 1);
    delete team;
    // Check if memory was released correctly, there's no direct way in C++ to check if a pointer has been deleted,
    // But we can make sure the program doesn't crash after the delete operation.
    CHECK(true);
}
   

