#include "loadmap.h"

void loadmap::checker() {
	for (int i = 1; i <= N_Lines; i++) {
		if (A_Lines[i] == "TEXTURE") {
			loadtexture(&i);
		}
		else if (A_Lines[i] == "FONT") {
			loadfont(&i);
		}
		else if (A_Lines[i] == "BACKSPRITEM") {
			loadBackSprite(&i);
		}
		else if (A_Lines[i] == "FORWSPRITEM") {
			loadForwSprite(&i);
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
			std::cout << "ignored" << std::endl;
		}
	}
}

void loadmap::loadUp(std::string map, sf::RenderTarget * target){
	drawTarget = target;
	loader.loadUp(map);
	reset();
	N_Lines = loader.getNumber();
	A_Lines = loader.getString();
	checker();
	V_textures.shrink_to_fit();
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadtexture(int * i) {
	N_textures++;
	V_textures.push_back(sf::Texture());
	if (!V_textures[V_textures.size()-1].loadFromFile(A_Lines[(*i) + 1]))
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
void loadmap::loadBackSprite(int * i) {
	N_spritesM++;
	V_BackImgs.push_back(sf::Sprite());
	V_BackImgs[V_BackImgs.size() - 1].setTexture(V_textures[atoi(A_Lines[(*i) + 1].c_str())]);
	V_BackImgs[V_BackImgs.size() - 1].setPosition(std::stof(A_Lines[(*i) + 2].c_str()), std::stof(A_Lines[(*i) + 3].c_str()));
	(*i) += 3;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadForwSprite(int * i) {
	N_spritesM++;
	V_ForwImgs.push_back(sf::Sprite());
	V_ForwImgs[V_ForwImgs.size() - 1].setTexture(V_textures[atoi(A_Lines[(*i) + 1].c_str())]);
	V_ForwImgs[V_ForwImgs.size() - 1].setPosition(std::stof(A_Lines[(*i) + 2].c_str()), std::stof(A_Lines[(*i) + 3].c_str()));
	(*i) += 3;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadspriteT(int * i) {
	V_Hsprites.push_back(sf::Sprite());
	V_Hsprites[V_Hsprites.size() - 1].setTexture(V_textures[atoi(A_Lines[(*i) + 1].c_str())]);
	V_Hsprites[V_Hsprites.size() - 1].setPosition(std::stof(A_Lines[(*i) + 2].c_str()), std::stof(A_Lines[(*i) + 3].c_str()));
	(*i) += 3;
}
///////////////////////////////////////////////////////////////////////////
void loadmap::loadtext(int * i) {
	N_texts++;
	A_texts = new sf::Text[N_texts];
	A_texts[N_texts-1].setFont(A_font[(*i)+1]);
	A_texts[N_texts-1].setString(A_Lines[(*i)+2]);
	A_texts[N_texts-1].setPosition(std::stof(A_Lines[(*i)+3].c_str()), std::stof(A_Lines[(*i)+4].c_str()));
	A_texts[N_texts-1].setCharacterSize(atoi(A_Lines[(*i)+5].c_str()));
	A_texts[N_texts-1].setFillColor(sf::Color(atoi(A_Lines[(*i)+6].c_str()), atoi(A_Lines[(*i)+7].c_str()), atoi(A_Lines[(*i)+8].c_str())));
	(*i) += 8;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setStart(int * i) {
	N_starts++;
	A_ProtCoord = new sf::Vector2f[N_starts];
	A_ProtCoord[N_starts-1] = sf::Vector2f(std::stof(A_Lines[(*i)+1].c_str()), std::stof(A_Lines[(*i) + 2].c_str()));
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setStar(int * i) {
	N_stars++;
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setSpawn(int * i) {
	V_EnemCoord.push_back(sf::Vector2f());
	V_AnimSrc.push_back(std::string());
	V_EnemType.push_back(std::string());
	V_EnemCoord[V_EnemCoord.size() -1] = sf::Vector2f(std::stof(A_Lines[(*i) + 1].c_str()), std::stof(A_Lines[(*i) + 2].c_str()));
	V_AnimSrc[V_AnimSrc.size() -1] = A_Lines[(*i) + 3];
	V_EnemType[V_EnemType.size() -1] = A_Lines[(*i) + 4];
	(*i) += 4;
}
/////////////////////////////////////////////////////////////////////////
void loadmap::setEnd(int * i) {
	N_ends++;
	(*i) += 2;
}
/////////////////////////////////////////////////////////////////////////
int loadmap::EnemyNumber() {
	std::cout << "n1" << " lol " << V_EnemCoord.size() << std::endl;
	return V_EnemCoord.size();
}
std::string * loadmap::EnemyType() {
	return V_EnemType.data();
}
sf::Vector2f * loadmap::EnemyCoords() {
	return V_EnemCoord.data();
}
std::string * loadmap::eAnimSource() {
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
	return V_Hsprites.size();
}

void loadmap::drawText() {
	for (int i = 0; i<N_texts; i++) {
		drawTarget->draw(A_texts[i]);
	}
}
void loadmap::drawBackImgs() {
	for (int i = 0; i < V_BackImgs.size(); i++) {
		drawTarget->draw(V_BackImgs[i]);
	}
}
void loadmap::drawForwImgs() {
	for (int i = 0; i < V_ForwImgs.size(); i++) {
		drawTarget->draw(V_ForwImgs[i]);
	}
}
void loadmap::drawCollisables() {
	for (int i = 0; i < V_Hsprites.size(); i++) {
		drawTarget->draw(V_Hsprites[i]);
	}
}

void loadmap::reset() {
	V_textures.clear();
	V_Hsprites.clear();
	V_ForwImgs.clear();
	V_BackImgs.clear();
	V_EnemCoord.clear();
	V_AnimSrc.clear();
	V_EnemType.clear();
	N_Lines = 0;
	N_texts = 0;
	N_fonts = 0;//texts
	N_starts = 0;
	N_stars = 0;
	N_spawns = 0;
	N_ends = 0;//gameplay
}
loadmap::loadmap() {}