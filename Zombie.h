#pragma once
#include "GameObject.h"
#include "Player.h"
class Zombie : public GameObject
{
public:
	enum class Types
	{
		Bloater,
		Chase,
		Crawler,
	};

	static const int TotalTypes = 3;

protected:
	Types type = Types::Bloater;
	sf::Sprite body;
	std::string texId;

	sf::Vector2f direction;

	int maxHp = 0;
	float speed = 0.f;
	int damage = 0;
	float attackIntervale = 0.f;

	int hp;

	Player* player = nullptr;
public:
	Zombie(const std::string& name = "");
	virtual ~Zombie() = default;

	void Set(const sf::Vector2i& count, const sf::Vector2f& size);
	void UpdateTransform();
	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetType(Types type);
};

