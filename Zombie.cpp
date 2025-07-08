#include "stdafx.h"
#include "Zombie.h"
#include "Player.h"
Zombie::Zombie(const std::string& name) : GameObject(name)
{
}
void Zombie::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(pos);
}

void Zombie::SetRotation(float rot)
{
	rotation = rot;
	body.setRotation(rot);
}

void Zombie::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(s);
}

void Zombie::SetOrigin(const sf::Vector2f& o)
{
	origin = o;
	originPreset = Origins::Custom;
	body.setOrigin(o);
}

void Zombie::SetOrigin(Origins preset)
{
	originPreset = preset;
	Utils::SetOrigin(body, originPreset);
}
void Zombie::Init()
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;

	SetType(type);
}

void Zombie::Release()
{
}

void Zombie::Reset()
{
	player = (Player*)SCENE_MGR.GetCurrentScene()->FindGameObject("Player");

	body.setTexture(TEXTURE_MGR.Get(texId));

	SetOrigin(Origins::MC);
	SetPosition({ 0.f,0.f });
	SetRotation(0.f);
	SetScale({ 1.f,1.f });
}

void Zombie::Update(float dt)
{
	if (Utils::Distance(player->GetPosition(), GetPosition()) >= 10.f)
	{
		direction = Utils::GetNormal(player->GetPosition() - GetPosition());
		SetRotation(Utils::Angle(direction));
		SetPosition(GetPosition() + direction * speed * dt);
	}
}

void Zombie::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Zombie::SetType(Types type)
{
	this->type = type;
	switch (this->type)
	{
	case Types::Bloater:
		texId = "graphics/bloater.png";
		maxHp = 100;
		speed = 100.f;
		damage = 100.f;
		attackIntervale = 1.f;
		break;
	case Types::Chase:
		texId = "graphics/chaser.png";
		maxHp = 200;
		speed = 50.f;
		damage = 100.f;
		attackIntervale = 1.f;
		break;
	case Types::Crawler:
		texId = "graphics/crawler.png";
		maxHp = 50;
		speed = 200.f;
		damage = 100.f;
		attackIntervale = 1.f;
		break;
	default:
		break;
	}
}
