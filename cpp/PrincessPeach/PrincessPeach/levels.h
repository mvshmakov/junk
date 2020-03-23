#pragma once

#include <SFML/Graphics.hpp>

const int H(24);
const int W(100);

class PLAYER;

class TileMapClass
{
public:
	sf::String TileMap1[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                                B                                                                 B",
		"B0                              0B                                                                0B",
		"B                C               B0               0                           B    B               B",
		"B           0         BBBBB      B                           BBBBB            BBBBBB               B",
		"B                          B    BB        BBB         BBBB       B    B0  0B          B B B B      B",
		"BBBB         B     B             B                               B    BBBBBB           0         BBB",
		"B            BBBBBBB           0 BBB                             B                    B            B",
		"B                                B BB                        B  0B                                 B",
		"B       B                        B  BB                       BBBBB                    B B B B      B",
		"B  0                  BBBB       B   BB                                                           BB",
		"B                                B0          BBBB     BBB                                          B",
		"B                             BBBB           B         0BBB                                 BBB    B",
		"B                                B           B      B     B             B       B                  B",
		"BBBB C                0          B         BBB    C BBBBBBBB           B0B     B0B     C           B",
		"B       0        BB             BBBBBB       BBBB          B          BB BBB BBB BB        BBB  BBBB",
		"B       BB    0  BB        BB                B             B         BB           BB       BB      B",
		"BA      BB       BB       BBB           BB  0B           0 B        BB             BB      BB      B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	};
	sf::String TileMap2[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                                                   B",
		"B                              B                                                                   B",
		"B0                         0 0 B                                                                   B",
		"B      BB B B               0 0B                                  B                    00          B",
		"B   BBBB          B B  BBBBBBBBB           0      BBBBBB                             BBBB          B",
		"B      B       B                         BBBBB               BB       B        BB                  B",
		"B      B                                                                   BSSSSSSSSSSSSSSSSSSSSSSSB",
		"B      B                              BB               000                 BBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBB    B               0                                                   B                       B",
		"B      B               B    B                       B0BBBBB0B              B                       B",
		"B      B                        B            B      BBB   BBB     0        B        B              B",
		"B    BBB                            B        B                    BB       B     BBBBBBBBBBBBBBBBBBB",
		"B      B                                  B  B                             B                       B",
		"B      B                                  B  B                             B                       B",
		"BBB    B                                B B  B                         BBBBB               B       B",
		"B                C                      B B  B                             BBBBBBBBBBBBBBBBBBB     B",
		"B     C                   B           B B B  B                                                     B",
		"BA              BBBB      B       B   BSBSBSSB                                                     B",
		"BBBBBBBBBBBBBBBBBBBB              BBBBBBBBBBBBBBBBB   BBB   BBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBB              BBBBBBBBBBBBBBBBBSSSBBBSSSBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBSSSSSSSSSSSSSSBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBSSSBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	};
	sf::String TileMap3[H] = {
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                                 B",
		"B                                                B                                                 B",
		"B 0    0            0                            BWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB          B",
		"B                                                BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB         B",
		"BWWWWWWWWWWWWBWWWWWWWWWWWWWWWWB                  BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB       B",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                                                    B",
		"B          B                      BBB                                                              B",
		"B          B                                     BBBBWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWB     B",
		"B   0      B                             BBBB    BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     B",
		"B   B      B                                                                                       B",
		"B          B0                   BWWWWB                                                             B",
		"B        BBB                    BBBBBB                                                             B",
		"B                    BWWWWWWB                                                                      B",
		"B                    BBBBBBBB                                                                      B",
		"BBBBB            BB                                                                                B",
		"B    B                                                                                             B",
		"B            BB                                                                                    B",
		"B                                                                                                  B",
		"B                                                                                                  B",
		"BBBBBBBBBBB                                                                                        B",
		"BBBBBBBBBBB                                                                                        B",
		"BBBBBBBBBBBSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	};

	int getSpawnPoint(PLAYER& Princess, std::string axis);
};