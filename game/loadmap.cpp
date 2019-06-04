#include "loadmap.h"

using namespace std;

void loadmap::checker() {
	for (int i = 1; i <= N_Lines; i++) {
		if (A_Lines[i] == "TEXTURE") {
			loadtexture(&i);
		}
		else if (A_Lines[i] == "FONT") {
			loadfont(&i);
		}
		else if (A_Lines[i] == "SPRITEM") {
			loadspriteM(&i);
		}
		else if (A_Lines[i] == "SPRITET") {
			loadspriteT(&i);
		}
		else if (A_Lines[i] == "TEXT") {
			loadtext(&i);
		}
		else if (A_Lines[i] == "PROTAGONISTSTART") {
			setStart(&i);
		}
		else if (A_Lines[i] == "ENEMYSPAWN") {
			setSpawn(&i);
		}
		else if (A_Lines[i] == "STAR") {
			setStar(&i);
		}
		else if (A_Lines[i] == "ENDPOINT") {
			setEnd(&i);
		}
		else {
			cout << "wtf?" << endl;
		}
	}
}

void loadmap::loadUp(string map, sf::RenderTarget * target){
	drawTarget = target;
	loader.loadUp(map);
	reset();
	N_Lines = loader.getNumber();
	A_Lines = loader.getString();
	checker();
	V_textures.shrink_to_fit();
}
void loadmap::drawText() {
	for (int i = 0; i<N_texts; i++) {
		drawTarget->draw(A_texts[i]);
	}
}
void loadmap::drawSoftSprites() {
	for (int i = 0; i < N_spritesM; i++) {
		drawTarget->draw(V_Ssprites[i]);
	}
}
void loadmap::drawHardSprites() {
	for (int i = 0; i < N_spritesT; i++) {
		drawTarget->draw(V_Hsprites[i]);
	}
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadtexture(int * i) {
	N_textures++;
	V_textures.push_back(sf::Texture());
	if (!V_textures[N_textures-1].loadFromFile(A_Lines[(*i) + 1]))
	{
		 //error...
	}
	(*i) += 1;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadfont(int * i) {
	N_fonts++;
	A_font = new sf::Font[N_fonts];
	if (!A_font[N_fonts-1].loadFromFile(A_Lines[(*i)+1]))
	{
		 //error...
	}
	(*i) += 1;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadspriteM(int * i) {
	N_spritesM++;
	V_Ssprites.push_back(sf::Sprite());
	V_Ssprites[N_spritesM-1].setTexture(V_textures[atoi(A_Lines[(*i) + 1].c_str())]);
	V_Ssprites[N_spritesM-1].setPosition(stof(A_Lines[(*i) + 2].c_str()), stof(A_Lines[(*i) + 3].c_str()));
	(*i) += 3;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadspriteT(int * i) {
	N_spritesT++;
	V_Hsprites.push_back(sf::Sprite());
	V_Hsprites[N_spritesT-1].setTexture(V_textures[atoi(A_Lines[(*i) + 1].c_str())]);
	V_Hsprites[N_spritesT-1].setPosition(stof(A_Lines[(*i) + 2].c_str()), stof(A_Lines[(*i) + 3].c_str()));
	(*i) += 3;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadtext(int * i) {
	N_texts++;
	A_texts = new sf::Text[N_texts];
	A_texts[N_texts-1].setFont(A_font[(*i)+1]);
	A_texts[N_texts-1].setString(A_Lines[(*i)+2]);
	A_texts[N_texts-1].setPosition(stof(A_Lines[(*i)+3].c_str()), stof(A_Lines[(*i)+4].c_str()));
	A_texts[N_texts-1].setCharacterSize(atoi(A_Lines[(*i)+5].c_str()));
	A_texts[N_texts-1].setFillColor(sf::Color(atoi(A_Lines[(*i)+6].c_str()), atoi(A_Lines[(*i)+7].c_str()), atoi(A_Lines[(*i)+8].c_str())));
	(*i) += 8;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setStart(int * i) {
	N_starts++;
	A_ProtCoord = new sf::Vector2f[N_starts];
	A_ProtCoord[N_starts-1] = sf::Vector2f(stof(A_Lines[(*i)+1].c_str()), stof(A_Lines[(*i) + 2].c_str()));
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setStar(int * i) {
	N_stars++;
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setSpawn(int * i) {
	N_spawns++;
	V_EnemCoord.push_back(sf::Vector2f());
	V_AnimSrc.push_back(std::string());
	V_EnemType.push_back(std::string());
	V_EnemCoord[N_spawns-1] = sf::Vector2f(stof(A_Lines[(*i) + 1].c_str()), stof(A_Lines[(*i) + 2].c_str()));
	V_AnimSrc[N_spawns-1] = A_Lines[(*i) + 3];
	V_EnemType[N_spawns-1] = A_Lines[(*i) + 4];
	(*i) += 4;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setEnd(int * i) {
	N_ends++;
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
int loadmap::EnemyNumber() {
	return N_spawns;
}
string * loadmap::EnemyType() {
	return V_EnemType.data();
}
sf::Vector2f * loadmap::EnemyCoords() {
	return V_EnemCoord.data();
}
string * loadmap::eAnimSource() {
	return V_AnimSrc.data();
}
sf::Vector2f loadmap::PlayerCoords() {
	int random=0;
	if (N_starts > 1) {
		random = rand() % N_starts;
	}
	return A_ProtCoord[random];
}
sf::Sprite * loadmap::Collisionable() {
	return V_Hsprites.data();
}
int loadmap::CollisionNum() {
	return N_spritesT;
}
void loadmap::reset() {
	V_textures.clear();
	V_Hsprites.clear();
	V_Ssprites.clear();
	V_EnemCoord.clear();
	V_AnimSrc.clear();
	V_EnemType.clear();
	N_textures = 0;
	N_Lines = 0;
	N_texts = 0;
	N_fonts = 0;//texts
	N_textures = 0;
	N_spritesM = 0;
	N_spritesT = 0;//sprites
	N_starts = 0;
	N_stars = 0;
	N_spawns = 0;
	N_ends = 0;//gameplay
}
loadmap::loadmap() {}